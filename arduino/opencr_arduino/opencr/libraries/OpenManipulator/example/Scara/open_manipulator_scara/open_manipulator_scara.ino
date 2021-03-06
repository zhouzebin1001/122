/*******************************************************************************
* Copyright 2018 ROBOTIS CO., LTD.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

/* Authors: Darby Lim, Hye-Jong KIM, Ryan Shim, Yong-Ho Na */

#include <scara_libs.h>
#include "remotecontroller100.h"
#include "processing.h"
#include "demo.h"

Scara scara;

void setup()
{
  scara.initDebug();

  initRC100();

  initProcessing();  

  initDemo();

  scara.initOpenManipulator(true); // true:  using actual hardware
                                   // false: using only visualization tool 
}

void loop()
{ 
  receiveDataFromRC100(&scara);      

  receiveDataFromProcessing(&scara); 
  sendDataToProcessing(&scara); 

  scara.processOpenManipulator(millis()/1000.0);    

  runDemo(&scara); 
}
