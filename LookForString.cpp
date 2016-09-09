/*
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Written by Jean Cuiller
*/

#include <Arduino.h>
#include "LookForString.h"

LookForStr::LookForStr (String *PcommandList[maxCommandNumber], int commandNumber)
	{
		_commandNumber=commandNumber;
	}

int LookForStr::InitCommandsList (String *PcommandList[maxCommandNumber], int commandNumber)
	{
		_commandNumber=commandNumber;
//		Serial.print(_commandNumber);
		for (int i=0;i<min(_commandNumber,maxCommandNumber);i++)
		{
			_PcommandList[i]=PcommandList[i];
//			Serial.print(*_PcommandList[i]);
//			Serial.print(".");
		}	
//		Serial.println();
	}

int LookForStr::GetMaxCommandNumber() 
{
	return maxCommandNumber;
}

commandReturn LookForStr::GetCommand(String Srequest) 

{
  commandReturn rc = { -1, -1};
//  Serial.print("request:");
//  Serial.println(Srequest);
  for (int cmdIdx = 0; cmdIdx < _commandNumber; cmdIdx++)
  {
    String needle = *_PcommandList[cmdIdx];
//	Serial.println(needle);
//	Serial.println(needle.length());
    if (Srequest.length() >= needle.length() ) {
      for (int posIdx = 0; (posIdx < Srequest.length() - needle.length() + 1); posIdx++) {
//		  Serial.println(Srequest.substring(posIdx, needle.length() + posIdx));
        if (Srequest.substring(posIdx, needle.length() + posIdx) == needle) {
          commandReturn rc = {cmdIdx, posIdx + needle.length()};
          return (rc);
        }
      }
    }
  }
  return (rc);
}
