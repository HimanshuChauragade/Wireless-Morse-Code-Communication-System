#include <LiquidCrystal.h>


const int rs = A4, en = A5, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define dashButtonPin A0
#define dotButtonPin A1
#define spaceButtonPin A2
#define backButtonPin A3



int dashButtonState = 1;
int dashButtonLastState = 1;
int dotButtonState = 1;
int dotButtonLastState = 1;
int spaceButtonState = 1;
int spaceButtonLastState = 1;
int backButtonState = 1;
int l = 0;

char la;

String tonesBuffer;
String text;
String expectedText;
String last;


String  symbolsAlphabet[][2] =
{
	{ ".-","A" },
	{ "-...","B" },
	{ "-.-.","C" },
	{ "-..","D" },
	{ ".","E" },
	{ "..-.","F" },
	{ "--.","G" },
	{ "....","H" },
	{ "..","I" },
	{ ".---","J" },
	{ "-.-","K" },
	{ ".-..","L" },
	{ "--","M" },
	{ "-.","N" },
	{ "---","O" },
	{ ".--.","P" },
	{ "--.-","Q" },
	{ ".-.","R" },
	{ "...","S" },
	{ "-","T" },
	{ "..-","U" },
	{ "...-","V" },
	{ ".--","W" },
	{ "-..-","X" },
	{ "-.--","Y" },
	{ "--..","Z" },
	{ ".----","1" },
	{ "..---","2" },
	{ "...--","3" },
	{ "....-","4" },
	{ ".....","5" },
	{ "-....","6" },
	{ "--...","7" },
	{ "---..","8" },
	{ "----.","9" },
	{ "-----","0"}
};

char getInput()
{

	if (!dashButtonState&& dashButtonLastState)
		return '-';
	if (!dotButtonState && dotButtonLastState)
		return '.';
	if (!spaceButtonState && spaceButtonLastState)
		return ' ';

	return (char)0;

}


char getSymbolFromBuffer()
{
	if (tonesBuffer == "")
		return ' ';

	for (int i = 0; i < sizeof symbolsAlphabet / sizeof symbolsAlphabet[0]; i++)
		if (tonesBuffer == symbolsAlphabet[i][0])
			return symbolsAlphabet[i][1][0];

	return (char)0;
}

void extractActionFromTonesBuffer()
{
	if (tonesBuffer == "......")
		text.remove(text.length() - 1, 1);
	if (tonesBuffer == "------")
		text = "";
}


void setup() {

  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.clear();

	pinMode(dashButtonPin, INPUT_PULLUP);
	pinMode(dotButtonPin, INPUT_PULLUP);
	pinMode(spaceButtonPin, INPUT_PULLUP);
	pinMode(backButtonPin, INPUT_PULLUP);

  
    lcd.setCursor(0, 0);  
    lcd.print("Text :");

    lcd.setCursor(0, 1);
    lcd.print("Input:");

}

void loop() {

	dashButtonState = digitalRead(dashButtonPin);
	dotButtonState = digitalRead(dotButtonPin);
	spaceButtonState = digitalRead(spaceButtonPin);
	backButtonState = digitalRead(backButtonPin);

	char tone = getInput();
  delay(50);

	if (tone != (char)0)
	{
		if (tone == ' ')
		{
			char symbol = getSymbolFromBuffer();

			if (symbol != (char)0)
			{
				text += symbol;
				if (text.length() > 16)
				{
					text = (String)symbol;
				}
			}
      

			else
			{
				extractActionFromTonesBuffer();
			}
			tonesBuffer = "";
		}
		else//čárka nebo tečka
		{
			tonesBuffer += tone;
			if (tonesBuffer.length() > 10)
			{
				tonesBuffer = (String)tone;
			}
		}



    lcd.clear();
    

    lcd.setCursor(0, 0);
    lcd.print("Text :");
    lcd.setCursor(6, 0);
    lcd.print(text);

    lcd.setCursor(0, 1);
    lcd.print("Input:");
    lcd.setCursor(7, 1);
    lcd.print(tonesBuffer);



		Serial.print("text:  ");
		Serial.println(text);
		Serial.print("tonesBuffer:  ");
		Serial.println(tonesBuffer);


	}
  if (backButtonState == 0)
	{
    l = text.length();
    text.remove(l-1);
		Serial.print("text:  ");
		Serial.println(text);
    delay(150);
  }

	dashButtonLastState = dashButtonState;
	dotButtonLastState = dotButtonState;
	spaceButtonLastState = spaceButtonState;

}