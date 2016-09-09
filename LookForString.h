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
/*
this function provide an object that look for a string ("command") inside a string ("Srequest") 
commands are part of a list - defined in an array commandList
function return {-1,-1} in case no matching found
function return {number,position} if found: 
				number of the matching element in the array (commandList) (in order to be used as a command)
				position in the position inside SRequest of the first byte just after the match (command) (in order to be used as parameter of the command)
*/

#include <Arduino.h>
#ifndef LookForString_h_included
#define LookForString_h_included
#define maxCommandNumber 100

typedef struct  {int idxCommand; int idxPos;} commandReturn;
class LookForStr
{
public:
LookForStr(String *PcommandList[maxCommandNumber], int commandNumber);
int InitCommandsList(String *PcommandList[maxCommandNumber], int commandNumber);
int GetMaxCommandNumber();
commandReturn GetCommand(String Srequest);
int _commandNumber;
String *_PcommandList[maxCommandNumber];
};
#endif