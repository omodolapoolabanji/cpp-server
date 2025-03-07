#include "http_tcpServer.h"
#include <iostream>
#include <sstream>
#include <unistd.h>

namespace{
  //logging functions 
  void log(const std::string &message){
    std::cout << message << std::endl; 
  }
  void exitWithError(const std::string &errorMessage){
    log("EXITING WITH ERROR: "+errorMessage);
    exit(1); 
  }
  }
namespace http
{
  TcpServer::TcpServer(std::string ip_address, int port):
    m_ip_address(ip_address), m_port(port), m_socket(), m_new_socket(), m_incomingMessage(), m_socketAddress(), m_socketAddress_len(sizeof(m_socketAddress)), m_serverMessage(buildResponse()){
    startServer(); //start the server
  }
  TcpServer::~TcpServer(){
    closeServer(); //close the server on destroy
  }
  int TcpServer::startServer(){
    m_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(m_socket < 0){
      exitWithError("cannot start the server | cause: cannot create socket");
      return 1; 
    }
    return 0;
  }
  void TcpServer::closeServer(){
    close(m_socket);
    close(m_new_socket);
    exit(0); 
  }
  
}
