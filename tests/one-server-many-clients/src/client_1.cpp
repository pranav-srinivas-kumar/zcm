/** @file    client_1.cpp 
 *  @author  Pranav Srinivas Kumar
 *  @date    2016.04.24
 *  @brief   This file contains definitions for the Client_1 class
 */

#include "client_1.hpp"

namespace zcm {

  /**
   * @brief Function required to dynamically load client.so
   */    
  extern "C" {
    Component* create_component() {
      return new Client_1();
    }
  }  

  /**
   * @brief Construct a client component
   * Register all operations exposed by this component
   */     
  Client_1::Client_1() {
    register_functionality("call_the_server",
			   std::bind(&Client_1::call_the_server, this));
  }

  /**
   * @brief Call the server
   * This operation is used to call the server!
   * Bind this operation to a periodic timer in the JSON configuration
   */   
  void Client_1::call_the_server() {

    // Create new message
    std::string new_message = "Client_1 calling...";

    // Call server
    try {
      std::string response = client("client_port")->call(new_message);
      std::cout << "Client_1 : Received response: " << response << std::endl;
    }
    catch (std::runtime_error &e) {
      std::cout << "Client_1 Exception: " << e.what() << std::endl;
    }
  }  

}
