/**
* @file CodeQ3.cpp
* @brief This file contains the code for creating a server which listens at the port 8000
* @author Abhishek Rathod
* @date 1/10/19
*/

///headers
#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <fstream> 
#include <vector>
#include <map>
#include <cassert>
#include <string.h>
#define NL "\n"

using namespace std;

struct pnode
{
  char ch; /// char
  float p; /// probability
};

static int pnode_compare( const void *elem1, const void *elem2 )
{
  const pnode a = *(pnode*)elem1;
  const pnode b = *(pnode*)elem2;
  if( a.p < b.p ) return 1; /// 1 - less (reverse for decreasing sort)
  else if( a.p > b.p ) return -1;
  return 0;
}

class Coder
{
private:
  int tsize; /// table size (number of chars)
  pnode *ptable; /// table of probabilities
  map<char, string> codes; /// codeword for each char

public:
  void Encode( const char *inputFilename, const char *outputFilename )
  {
    map<char, int> freqs; /// frequency for each char from input text
    int i;

    ///  Opening input file
    
    FILE *inputFile;
    inputFile = fopen( inputFilename, "r" );
    assert( inputFile );

    ///  Counting chars
    
    char ch; // char
    unsigned total = 0;
    while( fscanf( inputFile, "%c", &ch ) != EOF )
    {
      freqs[ch]++;
      total++;
    }
    tsize = (int)freqs.size();

    ///  Building decreasing freqs table
    
    ptable = new pnode[tsize];
    assert( ptable );
    float ftot = float(total);
    map<char, int>::iterator fi;
    for( fi=freqs.begin(),i=0; fi!=freqs.end(); ++fi,++i )
    {
      ptable[i].ch = (*fi).first;
      ptable[i].p = float((*fi).second) / ftot;
    }
    qsort( ptable, tsize, sizeof(pnode), pnode_compare );

    ///  Encoding
    
    EncShannon( 0, tsize-1 );

    ///  Opening output file
    
    FILE *outputFile;
    outputFile = fopen( outputFilename, "wb" );
    assert( outputFile );

    ///  Outputing ptable and codes
    
    fprintf( outputFile, "%i\n", tsize );
    cout<<endl ;
    cout<<"Shannon-Fano Codes : "<<endl ;
    for( i=0; i<tsize; i++ )
    { 
      if(ptable[i].ch!='\n'){
        cout<<"\'"<<ptable[i].ch<<"\'"<</*"  "<<ptable[i].p<<*/":"<<codes[ptable[i].ch].c_str()<<endl;
        // printf("%c\t%f\t%s"NL, ptable[i].ch, ptable[i].p, codes[ptable[i].ch].c_str() );
      }
      fprintf(outputFile, "%c\t%f\t%s\n", ptable[i].ch, ptable[i].p, codes[ptable[i].ch].c_str() );
    }

    ///  Outputing encoded text
    fseek( inputFile, SEEK_SET, 0 );
    printf(NL);
    fprintf(outputFile, NL);
    cout<<"Encoded message : "<<endl ;
    int length = 0 ;
    while( fscanf( inputFile, "%c", &ch ) != EOF )
    { 
      if(ch=='\n'){
        length+=0 ;          
      } else {
        length+=strlen(codes[ch].c_str()) ;
      }
        printf("%s", codes[ch].c_str());
        fprintf(outputFile, "%s", codes[ch].c_str());
    }
    printf(NL);

    cout<<endl<<"Encoded message length: "<<length<<endl<<endl ;
    ///  Cleaning
    codes.clear();
    delete[] ptable;

    ///  Closing files
    fclose( outputFile );
    fclose( inputFile );
  }
  
  void Decode( const char *inputFilename, const char *outputFilename )
  {
    ///  Opening input file
    
    FILE *inputFile;
    inputFile = fopen( inputFilename, "r" );
    assert( inputFile );

    ///  Loading codes
    
    fscanf( inputFile, "%i", &tsize );
    char ch, code[128];
    float p;
    int i;
    fgetc( inputFile ); /// skip end line
    for( i=0; i<tsize; i++ )
    {
      ch = fgetc(inputFile);
      fscanf( inputFile, "%f %s", &p, code );
      codes[ch] = code;
      fgetc(inputFile); // skip end line
    }
    fgetc(inputFile); // skip end line

    ///  Opening output file
    
    FILE *outputFile;
    outputFile = fopen( outputFilename, "w" );
    assert( outputFile );

    ///  Decoding and outputing to file
    
    string accum = "";
    map<char, string>::iterator ci;

    cout<<"Decoded Message : "<<endl ;

    while((ch = fgetc(inputFile)) != EOF)
    {
      accum += ch;
      for( ci=codes.begin(); ci!=codes.end(); ++ci )
        if( !strcmp( (*ci).second.c_str(), accum.c_str() ) )
        {
          accum = "";
          printf( "%c", (*ci).first );
          fprintf( outputFile, "%c", (*ci).first );
        }
    }

    ///  Cleaning
    
    fclose( outputFile );
    fclose( inputFile );
  }

private:
  void EncShannon( int li, int ri )
  {
    int i, isp;
    float p;
    float pfull;
    float phalf;

    if( li == ri )
    {
      return;
    }
    else if( ri - li == 1 )
    {
      ///  If interval consist of 2 elements then it's simple
      
      codes[ptable[li].ch] += '0';
      codes[ptable[ri].ch] += '1';
    }
    else
    {
      ///  Calculating sum of probabilities at specified interval
      
      pfull = 0;
      for( i=li; i<=ri; ++i )
      {
        pfull += ptable[i].p;
      }

      ///  Searching center
      
      p = 0;
      isp = -1; /// index of split pos
      phalf = pfull * 0.5f;
      for( i=li; i<=ri; ++i )
      {
        p += ptable[i].p;
        if(p <= phalf) {
          codes[ptable[i].ch] += '0';
        }
        else
        {
          codes[ptable[i].ch] += '1';
          if( isp < 0 ) isp = i;
        }
      }
      
      if( isp < 0 ) isp = li+1;

      ///  Next step (recursive)
      
      EncShannon( li, isp-1 );
      EncShannon( isp, ri );
    }
  }
};

/// A Tree node
struct Node
{
	char ch;
	int freq;
	Node *left, *right;
};

/// Function to allocate a new tree node
Node* getNode(char ch, int freq, Node* left, Node* right)
{
	Node* node = new Node();

	node->ch = ch;
	node->freq = freq;
	node->left = left;
	node->right = right;

	return node;
}

/// Comparison object to be used to order the heap
struct comp
{
	bool operator()(Node* l, Node* r)
	{
		/// highest priority item has lowest frequency
		return l->freq > r->freq;
	}
};

/// traverse the Huffman Tree and store Huffman Codes
/// in a map.
void encode(Node* root, string str,
			unordered_map<char, string> &huffmanCode)
{
	if (root == nullptr)
		return;

	/// found a leaf node
	if (!root->left && !root->right) {
		huffmanCode[root->ch] = str;
	}

	encode(root->left, str + "0", huffmanCode);
	encode(root->right, str + "1", huffmanCode);
}

/// traverse the Huffman Tree and decode the encoded string
void decode(Node* root, int &index, string str)
{
	if (root == nullptr) {
		return;
	}

	/// found a leaf node
	if (!root->left && !root->right)
	{
		cout << root->ch;
		return;
	}

	index++;

	if (str[index] =='0')
		decode(root->left, index, str);
	else
		decode(root->right, index, str);
}

/// Builds Huffman Tree and decode given input text
void buildHuffmanTree(string text)
{
	/// count frequency of appearance of each character
	/// and store it in a map
	unordered_map<char, int> freq;
	for (char ch: text) {
		freq[ch]++;
	}

	/// Create a priority queue to store live nodes of
	/// Huffman tree;
	priority_queue<Node*, vector<Node*>, comp> pq;

	/// Create a leaf node for each character and add it
	/// to the priority queue.
	for (auto pair: freq) {
		pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
	}

	/// do till there is more than one node in the queue
	while (pq.size() != 1)
	{
		/// Remove the two nodes of highest priority
		/// (lowest frequency) from the queue
		Node *left = pq.top(); pq.pop();
		Node *right = pq.top();	pq.pop();

		/// Create a new internal node with these two nodes
		/// as children and with frequency equal to the sum
		/// of the two nodes' frequencies. Add the new node
		/// to the priority queue.
		int sum = left->freq + right->freq;
		pq.push(getNode('\0', sum, left, right));
	}

	/// root stores pointer to root of Huffman Tree
	Node* root = pq.top();

	/// traverse the Huffman Tree and store Huffman Codes
	/// in a map. Also prints them
	unordered_map<char, string> huffmanCode;
	encode(root, "", huffmanCode);

	cout << "Huffman Codes :\n";
	for (auto pair: huffmanCode) {
		cout<<"\'"<<pair.first<<"\'"<<":"<<pair.second << '\n';
	}


	/// print encoded string
	string str = "";
	for (char ch: text) {
		str += huffmanCode[ch];
	}

	cout << "\nEncoded message :\n" << str << '\n';

	cout<<"\nEncoded message length : "<<str.length()<<endl ;

	/// traverse the Huffman Tree again and this time
	/// decode the encoded string
	int index = -1;
	cout << "\nDecoded message :\n";
	while (index < (int)str.size() - 2) {
		decode(root, index, str);
	}
	cout<<endl ;
}

/// Huffman coding algorithm
int main()
{	
	ifstream file ;
	file.open("input.txt") ; 
	string line ;
	string text ;
	while(file){ 
    	getline(file, line); 
    	text=text+line ;
    }
    printf("Choose an algorithm:-\n1.Huffman\n2.Shannon-Fano\n");
    int opt ;
    scanf("%d",&opt) ;
    if(opt==1){
    	buildHuffmanTree(text);	
    } else if(opt==2){
    char inputFilename[128]="input.txt";
    char outputFilename[128]="output.txt";
    char outputFilename1[128]="output1.txt";
    ///  Calling encoding or decoding subroutine
    
    Coder *coder;
    coder = new Coder;
    assert(coder);
    
    coder->Encode( inputFilename, outputFilename );
    coder->Decode( outputFilename, outputFilename1 );
    
    delete coder;

    } else {
    	printf("Enter a valid input !!!\n");
    }

	return 0;
}
