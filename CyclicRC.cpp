#include <iostream>
using namespace std;

class CRC{

    string msg;
    string gen;
    string msgSent;
    string remainder;

    public : 
        CRC(string msg , string gen){
            this->msg=msg;
            this->gen=gen;

            cout<<"\nThe message that would be sent to receiver would be : " <<binaryDiv();           
        }
   
        string XOR(string A , string B){
            int len=B.length();
            string result="";
            
            for(int i=0 ; i<len ; i++ ){
                if(A[i]==B[i]){
                    result+='0';
                }
                else{
                    result+='1';
                }
            }
            return result;
        }

        string binaryDiv(){
            int genLen=this->gen.length();
            int msgLen=this->msg.length();
            int dividentLen=msgLen+genLen-1;
            string temp=msg.substr(0,genLen);
            string remainder;

            string A;
            for(int i=0 ; i<genLen ; i++){
                A+='0';
            }

            for(int i=msgLen ; i<dividentLen ; i++){
                this->msg+='0';
            }
            
            for(int i=0 ; i<=dividentLen ; i++){
                if(i<=dividentLen-genLen){
                    if(temp[0]=='1'){
                        remainder=XOR(temp,gen);
                        temp=remainder+msg[i+genLen];
                        temp=temp.substr(1,temp.length());
                    }
                    else{
                        remainder=XOR(temp,A);
                        temp=remainder+msg[i+genLen];
                        temp=temp.substr(1,temp.length());
                    }
                }
            }
            msgSent=msg.substr(0,msgLen)+remainder.substr(1,remainder.length());
            return msgSent;
        }
};

int main(){
    string msg, gen;
    cout<<"Enter the message(in binary) you want to send : ";
    cin>>msg;
    cout<<"Enter the generator : " ;
    cin>>gen;
    
    CRC obj(msg,gen);
    

    return 0;
}