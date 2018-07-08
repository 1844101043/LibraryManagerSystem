#include"PublicFunction.h"


int main(void)
{
	
    User TheUser;
	
	
	
	switch (TheUser.Login())
	{
	case 0: {SystemManager SYS(TheUser.PersonalInfo); c.Show(); break; }
	case 1: {BookManager BOO(TheUser.PersonalInfo); b.Show(); break; }
	case 2: {Teacher  TEA(TheUser.PersonalInfo);t.Show(); break;}
	case 3: {Student STU(TheUser.PersonalInfo); s.Show(); break; }
	default:break;

	}
    

	return 0;
}
