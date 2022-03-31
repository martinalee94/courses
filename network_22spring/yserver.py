
import datetime
import socket
import os
from threading import Thread



SIZE=1024
FORMAT="utf-8"
SERVER_DATA_PATH="server_data"

def main():
    server=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind(("0.0.0.0",10090))
    server.listen()

    while True:
        client,address=server.accept()
        print("Accepted")
        data=client.recv(65535)
        # request=client.recv(1024).decode('utf-8')
        # string_list=request.split(' ')
        # method=string_list[0]
        # requesting_file=string_list[1]
        # print('Client request ',requesting_file)

        # temp=data.decode().split('\r\n')
        data=data.decode().split()
        request_method=data[0]
        page=data[1]
        # print(temp)

        #처음 login할 때 "/"로 바로 들어가거나 주소창에서 "/index.html"를 붙여서 들어간다.
        if (page == "/" or page == "/index.html"):
            if request_method == "GET":
                index_addr = "/index.html"
                f=open('.'+index_addr,'rt', encoding='utf8')
                html_index=f.read()
                f.close()
                client.send(('HTTP/1.1 200 OK\r\n\r\n'+html_index).encode('utf-8'))
                
                
                
            

        elif (page=="/storage" or page=="/storage.html"):
            # if 'Accept:' in data:
            #     file=open()
            #     data[43]

            #     for  i in data:
            #         print(i)
                # data[43]에 file data 들어있는것으로 추정됨.
            if request_method=="POST":
                user, pw=data[-1].split('&')
                user= user.split('=')[1]
                #file받았을때
                if '.' in user:
                    filename=user
                    print(filename)
                    # print("???")
                    # #두번 recv는 안좋아
                    # request=client.recv(65535).decode('utf-8')
                    # client.send(('HTTP/1.1 200 OK\n').encode('utf-8'))
                    # print("???")
                    # string_list=request.split(' ')
                    # print(string_list)
                    # method=string_list[0]
                    # requesting_file=string_list[1]
                    # print('Client request ',requesting_file)
                    # myfile=requesting_file.split('?')[0]
                    # print(myfile)
                    # myfile=myfile.lstrip('/')
                    # if(myfile==''):
                    #     myfile='index.html'
                    # try:
                    #     file=open(myfile,'rb')
                    #     response=file.read()
                    #     file.close()

                    #     header='HTTP/1.1 200 OK\n'
                    #     header+='Content-Type: '+str(user)

                #id pw안치고 login하려고 할때
                elif(user=='' or pw==''):
                    client.send(('HTTP/1.1 200 OK\r\n\r\n403Forbidden').encode('utf-8'))
                    
                #id pw치고 login하려 할때
                else:
                    #처음보는 id로 login할 때
                    if not os.path.isdir("./{}".format(user)):
                        os.mkdir("./{}".format(user))

                    html_addr="/storage.html"
                    read_storage(html_addr,user,client)
                    # client.send(('HTTP/1.1 200 OK\r\n'))
                    

            #storage는 GET(주소창에 쳐도 되는 방식)으로 들어갈 수 없다. 
            elif request_method=="GET":
                client.send('HTTP/1.1 200 OK\r\n\r\n403Forbidden'.encode('utf-8'))


        elif(page=="/cookie" or page == "/cookie.html"):
            pass

        
        client.close()

   

def read_storage(html,user,c):
    f=open('.'+html,'rt', encoding='utf-8')
    htmlcode=f.read()
    f.close()
    user_htmlcode=htmlcode.split('user1')[0]+user+htmlcode.split('user1')[1]
    # print(user_htmlcode[0:-5])
    c.send(('HTTP/1.1 200 OK\r\n'+user_htmlcode).encode('utf-8'))


    
    #print(htmlcode)


# def upload_file(path,c):
#     with open(path,'w') as f:
#         f.write()


if __name__=="__main__":
    main()


#Thread로 관리할 수 있나? Tread list?
#아 그리고 server에서 storage파일 잠시 조작해서 보내준다.
