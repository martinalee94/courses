
import socket
import os


def main():
    server=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind(("0.0.0.0",10090))
    server.listen()

    while True:
        client,address=server.accept()

        data=client.recv(65535)
        data=data.decode().split()
        request_method=data[0] 
        page=data[1]

        #처음 login할 때 "/"로 바로 들어가거나 주소창에서 "/index.html"를 붙여서 들어간다.
        if (page == "/" or page == "/index.html"):
            if request_method == "GET":
                index_addr = "/index.html"
                f=open('.'+index_addr,'rt', encoding='utf8')
                html_index=f.read()
                f.close()
                client.send(('HTTP/1.1 200 OK\r\n\r\n'+html_index).encode('utf-8'))
                
        elif (page=="/storage" or page=="/storage.html"):
            if 'multipart/form-data;' in data:
                pass

                    
            elif request_method=="POST":
                user, pw=data[-1].split('&')
                user= user.split('=')[1]
                
                #file받았을때
                if '.' in user:
                    filename=user
                    pass

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
                    

            #storage는 GET(주소창에 쳐도 되는 방식)으로 들어갈 수 없다. 
            elif request_method=="GET":
                client.send('HTTP/1.1 200 OK\r\n\r\n403Forbidden'.encode('utf-8'))


        elif(page=="/cookie" or page == "/cookie.html"):
            client.close()
            

def read_storage(html,user,c):
    f=open('.'+html,'rt', encoding='utf-8')
    htmlcode=f.read()
    f.close()
    user_htmlcode=htmlcode.split('user1')[0]+user+htmlcode.split('user1')[1]
    c.send(('HTTP/1.1 200 OK\r\n'+user_htmlcode).encode('utf-8'))



if __name__=="__main__":
    main()
   
