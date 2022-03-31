
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

        data=data.decode().split()
        request_method=data[0]
        page=data[1]
        print(data)

        #처음 login할 때 "/"로 바로 들어가거나 주소창에서 "/index.html"를 붙여서 들어간다.
        if (page == "/" or page == "/index.html"):
            if request_method == "GET":
                htmladdr = "/index.html"
                read_html(htmladdr, client)
            

        elif (page=="/storage" or page=="/storage.html"):
            if request_method=="POST":
                user, pw=data[-1].split('&')
                user= user.split('=')[1]
                if(user=='' or pw==''):
                    pass
                else:
                    if not os.path.isdir("./{}".format(user)):
                        os.mkdir("./{}".format(user))
                    htmladdr="/storage.html"
                    read_html(htmladdr,client)

            #storage는 GET(주소창에 쳐도 되는 방식)으로 들어갈 수 없다. 
            elif request_method=="GET":
                client.send('HTTP/1.1 200 OK\r\n\r\n403Forbidden'.encode('utf-8'))
                #filename=page.split("?submitted_file")[1].split("&submit=Submit")[0]
                #filepath=os.path.join(page.split(filename)[0])
                #print(filepath)
                # upload(path,c)



            if "Cookie:" in data:
                if request_method=="GET":
                    htmladdr="/storage.html"
                    read_html(htmladdr,client)
                else:
                    client.send(str.encode("HTTP/1.1 302 redirect\n"))
                    client.send(str.encode("Location: {}\n".format("./index.html")))

        elif(page=="/cookie" or page == "/cookie.html"):
            #Cookie있으면 cookie접근 가능
            if "Cookie:" in data:
                htmladdr = "/cookie.html"
                read_html(htmladdr,client)
            #??
            else:
                client.send(('HTTP/1.1 200 OK\r\n\r\n403Forbidden').encode('utf-8'))
        
        client.close()

   

def read_html(html,c):
    f=open('.'+html,'rt', encoding='utf-8')
    htmlcode=f.read()
    c.send(('HTTP/1.1 200 OK\r\n\r\n'+htmlcode).encode('utf-8'))
    f.close()
    #print(htmlcode)

# def upload_file(path,c):
#     with open(path,'w') as f:
#         f.write()


if __name__=="__main__":
    main()

