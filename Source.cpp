#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include"clsMainScreen.h"
#include <iomanip>
#include "clsUtil.h"
#include"clsLoginScreen.h"




int main() {


	while (true)
	{
		if (!clsLoginScreen::ShowLoginScreen())
		{
			break;
		}
	}
    
    return 0;
}