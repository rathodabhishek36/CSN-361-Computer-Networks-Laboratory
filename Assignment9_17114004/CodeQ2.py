# Abhishek Rathod
# Enroll. no. - 17114004

import csv 
  
filename1 = "Q1_data.csv"
filename2 = "Q1_Ethernet.csv"
filename3 = "Q1_IPv4.csv"
filename4 = "Q1_IPv6.csv"
filename5 = "Q1_TCP.csv"
filename6 = "Q1_UDP.csv"
  
fields = [] 
rows = [] 
  
with open(filename1, 'r') as csvfile: 
    csvreader = csv.reader(csvfile) 
    fields = next(csvreader) 
    for row in csvreader: 
        rows.append(row) 

len_avg=0
length=csvreader.line_num-1
for row in rows: 
    len_avg=len_avg+int(row[5])

print("Average Packet Size (in Bytes) : %f"%(len_avg/length))

csvfile.close()

#**************************************************************************************************************************

fields = [] 
rows = [] 
  
with open(filename2, 'r') as csvfile: 
    csvreader = csv.reader(csvfile) 
    fields = next(csvreader) 
    for row in csvreader: 
        rows.append(row) 

# for col in fields:
#     print(col)
print("\nFor Ethernet : ")

length=csvreader.line_num-1
dur_avg=0.0
avg_pack_sent=0
avg_pack_recieved=0
avg_byte_sent=0
avg_byte_recieved=0

ratio_pack=0.0
ratio_byte=0.0
pack_count=0
byte_count=0

for row in rows: 
    dur_avg=dur_avg+float(row[9])
    avg_pack_sent=avg_pack_sent+float(row[4])
    avg_pack_recieved=avg_pack_recieved+float(row[6])
    avg_byte_sent=avg_byte_sent+float(row[5])
    avg_byte_recieved=avg_byte_recieved+float(row[7])
    if float(row[4])!=0.0:
        pack_count=pack_count+1
        ratio_pack=ratio_pack+(float(row[6])/float(row[4]))
    if float(row[5])!=0.0:
        byte_count=byte_count+1
        ratio_byte=ratio_byte+(float(row[7])/float(row[5]))


print("Average Flow Duration (seconds) : %f"%(dur_avg/length))
print("Average no of packets sent per flow : %f"%(avg_pack_sent/length))
print("Average no of packets recieved per flow : %f"%(avg_pack_recieved/length))
print("Average no of bytes sent per flow : %f"%(avg_byte_sent/length))
print("Average no of bytes recieved per flow : %f"%(avg_byte_recieved/length))
print("Average ratio of incoming to outgoing packets : %f"%(ratio_pack/pack_count))
print("Average ratio of incoming to outgoing bytes : %f"%(ratio_byte/byte_count))

csvfile.close()

#**************************************************************************************************************************

fields = [] 
rows = [] 
  
with open(filename3, 'r') as csvfile: 
    csvreader = csv.reader(csvfile) 
    fields = next(csvreader) 
    for row in csvreader: 
        rows.append(row) 

print("\nFor IPv4 Protocol : ")

length=csvreader.line_num-1
dur_avg=0.0
avg_pack_sent=0
avg_pack_recieved=0
avg_byte_sent=0
avg_byte_recieved=0

ratio_pack=0.0
ratio_byte=0.0
pack_count=0
byte_count=0

for row in rows: 
    dur_avg=dur_avg+float(row[9])
    avg_pack_sent=avg_pack_sent+float(row[4])
    avg_pack_recieved=avg_pack_recieved+float(row[6])
    avg_byte_sent=avg_byte_sent+float(row[5])
    avg_byte_recieved=avg_byte_recieved+float(row[7])
    if float(row[4])!=0.0:
        pack_count=pack_count+1
        ratio_pack=ratio_pack+(float(row[6])/float(row[4]))
    if float(row[5])!=0.0:
        byte_count=byte_count+1
        ratio_byte=ratio_byte+(float(row[7])/float(row[5]))

print("Average Flow Duration (seconds) : %f"%(dur_avg/length))
print("Average no of packets sent per flow : %f"%(avg_pack_sent/length))
print("Average no of packets recieved per flow : %f"%(avg_pack_recieved/length))
print("Average no of bytes sent per flow : %f"%(avg_byte_sent/length))
print("Average no of bytes recieved per flow : %f"%(avg_byte_recieved/length))
print("Average ratio of incoming to outgoing packets : %f"%(ratio_pack/pack_count))
print("Average ratio of incoming to outgoing bytes : %f"%(ratio_byte/byte_count))

csvfile.close()

#**************************************************************************************************************************

fields = [] 
rows = [] 
  
with open(filename4, 'r') as csvfile: 
    csvreader = csv.reader(csvfile) 
    fields = next(csvreader) 
    for row in csvreader: 
        rows.append(row) 

print("\nFor IPv6 Protocol : ")

length=csvreader.line_num-1
dur_avg=0.0
avg_pack_sent=0
avg_pack_recieved=0
avg_byte_sent=0
avg_byte_recieved=0

ratio_pack=0.0
ratio_byte=0.0
pack_count=0
byte_count=0

for row in rows: 
    dur_avg=dur_avg+float(row[9])
    avg_pack_sent=avg_pack_sent+float(row[4])
    avg_pack_recieved=avg_pack_recieved+float(row[6])
    avg_byte_sent=avg_byte_sent+float(row[5])
    avg_byte_recieved=avg_byte_recieved+float(row[7])
    if float(row[4])!=0.0:
        pack_count=pack_count+1
        ratio_pack=ratio_pack+(float(row[6])/float(row[4]))
    if float(row[5])!=0.0:
        byte_count=byte_count+1
        ratio_byte=ratio_byte+(float(row[7])/float(row[5]))

print("Average Flow Duration (seconds) : %f"%(dur_avg/length))
print("Average no of packets sent per flow : %f"%(avg_pack_sent/length))
print("Average no of packets recieved per flow : %f"%(avg_pack_recieved/length))
print("Average no of bytes sent per flow : %f"%(avg_byte_sent/length))
print("Average no of bytes recieved per flow : %f"%(avg_byte_recieved/length))
print("Average ratio of incoming to outgoing packets : %f"%(ratio_pack/pack_count))
print("Average ratio of incoming to outgoing bytes : %f"%(ratio_byte/byte_count))

csvfile.close()

#**************************************************************************************************************************

fields = [] 
rows = [] 
  
with open(filename5, 'r') as csvfile: 
    csvreader = csv.reader(csvfile) 
    fields = next(csvreader) 
    for row in csvreader: 
        rows.append(row) 

print("\nFor TCP Protocol : ")

length=csvreader.line_num-1
dur_avg=0.0
avg_pack_sent=0
avg_pack_recieved=0
avg_byte_sent=0
avg_byte_recieved=0

ratio_pack=0.0
ratio_byte=0.0
pack_count=0
byte_count=0

for row in rows: 
    dur_avg=dur_avg+float(row[9])
    avg_pack_sent=avg_pack_sent+float(row[4])
    avg_pack_recieved=avg_pack_recieved+float(row[6])
    avg_byte_sent=avg_byte_sent+float(row[5])
    avg_byte_recieved=avg_byte_recieved+float(row[7])
    if float(row[4])!=0.0:
        pack_count=pack_count+1
        ratio_pack=ratio_pack+(float(row[6])/float(row[4]))
    if float(row[5])!=0.0:
        byte_count=byte_count+1
        ratio_byte=ratio_byte+(float(row[7])/float(row[5]))

print("Average Flow Duration (seconds) : %f"%(dur_avg/length))
print("Average no of packets sent per flow : %f"%(avg_pack_sent/length))
print("Average no of packets recieved per flow : %f"%(avg_pack_recieved/length))
print("Average no of bytes sent per flow : %f"%(avg_byte_sent/length))
print("Average no of bytes recieved per flow : %f"%(avg_byte_recieved/length))
print("Average ratio of incoming to outgoing packets : %f"%(ratio_pack/pack_count))
print("Average ratio of incoming to outgoing bytes : %f"%(ratio_byte/byte_count))

csvfile.close()

#**************************************************************************************************************************

fields = [] 
rows = [] 
  
with open(filename6, 'r') as csvfile: 
    csvreader = csv.reader(csvfile) 
    fields = next(csvreader) 
    for row in csvreader: 
        rows.append(row) 

print("\nFor UDP Protocol : ")

length=csvreader.line_num-1
dur_avg=0.0
avg_pack_sent=0
avg_pack_recieved=0
avg_byte_sent=0
avg_byte_recieved=0

ratio_pack=0.0
ratio_byte=0.0
pack_count=0
byte_count=0

for row in rows: 
    dur_avg=dur_avg+float(row[9])
    avg_pack_sent=avg_pack_sent+float(row[4])
    avg_pack_recieved=avg_pack_recieved+float(row[6])
    avg_byte_sent=avg_byte_sent+float(row[5])
    avg_byte_recieved=avg_byte_recieved+float(row[7])
    if float(row[4])!=0.0:
        pack_count=pack_count+1
        ratio_pack=ratio_pack+(float(row[6])/float(row[4]))
    if float(row[5])!=0.0:
        byte_count=byte_count+1
        ratio_byte=ratio_byte+(float(row[7])/float(row[5]))

print("Average Flow Duration (seconds) : %f"%(dur_avg/length))
print("Average no of packets sent per flow : %f"%(avg_pack_sent/length))
print("Average no of packets recieved per flow : %f"%(avg_pack_recieved/length))
print("Average no of bytes sent per flow : %f"%(avg_byte_sent/length))
print("Average no of bytes recieved per flow : %f"%(avg_byte_recieved/length))
print("Average ratio of incoming to outgoing packets : %f"%(ratio_pack/pack_count))
print("Average ratio of incoming to outgoing bytes : %f"%(ratio_byte/byte_count))

csvfile.close()

#**************************************************************************************************************************

src_ip="10.61.81.49"
avg_time_interval_sent=0.0
avg_time_interval_recieved=0.0

fields = [] 
rows = [] 
  
with open(filename1, 'r') as csvfile: 
    csvreader = csv.reader(csvfile) 
    fields = next(csvreader) 
    for row in csvreader: 
        rows.append(row) 

sent_time_prev=0.0
first=1

sent_count=0
recieved_count=0

connections=0
dest_dict=dict()
conn_dict=dict()

for row in rows:
    if row[2]==src_ip:
        avg_time_interval_sent=avg_time_interval_sent+(float(row[1])-sent_time_prev)
        sent_time_prev=float(row[1])
        sent_count=sent_count+1
    elif row[3]==src_ip:
        if first==1:
            recieved_time_prev=float(row[1])
            first=0
        else:
            avg_time_interval_recieved=avg_time_interval_recieved+(float(row[1])-recieved_time_prev)
            recieved_time_prev=float(row[1])
            recieved_count=recieved_count+1

    if not row[3] in dest_dict.keys():
        dest_dict[row[3]]=1

    key1=row[2]+"_"+row[3]
    key2=row[3]+"_"+row[2]
    if not key1 in conn_dict.keys():
        conn_dict[key1]=1
        conn_dict[key2]=1
        connections=connections+1
    

print("\nAverage Time Interval b/w Packets Sent (in seconds): %f"%(avg_time_interval_sent/sent_count))
print("Average Time Interval b/w Packets Recieved (in seconds): %f"%(avg_time_interval_recieved/recieved_count))

# print(connections) 70
# print(len(dest_dict)) 71 

print("Average ratio of connections to number of destination IP's : %f\n"%(connections/len(dest_dict)))

csvfile.close()
