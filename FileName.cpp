#include <iostream>
#include <algorithm>


#include <conio.h>
#include <stdio.h>



int const razpolei = 24;
int const razpoleg = 24;
int const razobpole = 8;

int const wf = 0, bf = 1, bfx = 2, bfy = 4, food_bfx = 100, food_bfy = 200, eat_bfx = 150, eat_bfy = 250, damka_y = 500, damka_x = 1000; // wf - белое поле, bf - черное поле, bfx - черное поле с икс, bfy - черное поле с игрик


void vpole(char pole[][razpoleg], int rpolei, int rpoleg, int obpole[][razobpole], int razobpole);
void nachras(int obpole[][razobpole], int razobpole);
void igra(int obpole[][razobpole], int razobpole, bool prov, int igrok);
bool provhoda(int obpole[][razobpole], int razobpole, int koordmesta_i, int koordmesta_g, int koordhod_i, int koordhod_g, int igr, bool eat);
bool proveat(int obpole[][razobpole], int razobpole, int igrok);
void eat(int obpole[][razobpole], int razobpole);
bool provpobeda(int obpole[][razobpole], int razobpole);
void prodeat(int obpole[][razobpole], int razobpole, int mestoig_i, int mestoig_g, int igrok);
void provnadamki(int obpole[][razobpole], int razobpole);


int main()
{
	system("color 9");
	
	setlocale(LC_ALL, "RU");
	
	

	char pole[razpolei][razpoleg];
	int obpole[razobpole][razobpole];

	nachras(obpole ,razobpole);
	vpole(pole, razpolei, razpoleg, obpole, razobpole);
	bool prov = true;
	int provpole{ 0 };
	int igr{ 1 };
	while (prov == true)
	{
		if (prov == true)
		{
			provnadamki(obpole, razobpole);


			igra(obpole, razobpole, prov, igr);

			provnadamki(obpole, razobpole);

			prov = provpobeda(obpole, razobpole);

			vpole(pole, razpolei, razpoleg, obpole, razobpole);
			
			provpole++;
			
			igr++;
		}
		if (igr == 3)
		{
			igr = 1;
		}
	}
	return 0;
}


void provnadamki(int obpole[][razobpole], int razobpole)
{
	for (int i = 0; i < razobpole;  i++)
	{
		for (int g = 0; g < razobpole; g++)
		{
			if (i == 0 && obpole[i][g] == bfy)
			{
				obpole[i][g] = damka_y;
			}
			else if (i == 7 && obpole[i][g] == bfx)
			{
				obpole[i][g] = damka_x;
			}
		}
	}
}

void prodeat(int obpole[][razobpole], int razobpole, int mestoig_i, int mestoig_g, int igrok)
{
	bool prov = false;
	int igrch{ 0 };
		if (igrok == 1 && obpole[mestoig_i][mestoig_g] != damka_x && obpole[mestoig_i][mestoig_g] != damka_y)
		{
			igrch = 1;
			if (
				( (obpole[mestoig_i + 1][mestoig_g + 1] == bfy || obpole[mestoig_i + 1][mestoig_g + 1] == damka_y) && obpole[mestoig_i + 2][mestoig_g + 2] == bf) ||
				( (obpole[mestoig_i + 1][mestoig_g - 1] == bfy || obpole[mestoig_i + 1][mestoig_g - 1] == damka_y) && obpole[mestoig_i + 2][mestoig_g - 2] == bf)
				)
			{
				std::cout << "Вам надо продолжить свой ход за ту же шашку(вам надо только ввести номер шашки которую хотите съесть)\n";
				if (obpole[mestoig_i + 1][mestoig_g + 1] == bfy || obpole[mestoig_i + 1][mestoig_g + 1] == damka_y)
				{
					if (obpole[mestoig_i + 1][mestoig_g + 1] == damka_y)
					{
						obpole[mestoig_i + 1][mestoig_g + 1] = food_bfy + 1;
					}
					else
					{
						obpole[mestoig_i + 1][mestoig_g + 1] = food_bfy;
					}
					std::cout << "ssssssss\n";
				}
				if (obpole[mestoig_i + 1][mestoig_g - 1] == bfy || obpole[mestoig_i + 1][mestoig_g - 1] == damka_y)
				{
					
					if (obpole[mestoig_i + 1][mestoig_g - 1] == damka_y)
					{
						obpole[mestoig_i + 1][mestoig_g - 1] = food_bfy + 1;
					}
					else
					{
						obpole[mestoig_i + 1][mestoig_g - 1] = food_bfy;
					}
					std::cout << "sggggggggggggg\n";
				}
				prov = true;
			}
			if (
				( (obpole[mestoig_i - 1][mestoig_g + 1] == bfy || obpole[mestoig_i - 1][mestoig_g + 1] == damka_y) && obpole[mestoig_i - 2][mestoig_g + 2] == bf) ||
				( (obpole[mestoig_i - 1][mestoig_g - 1] == bfy || obpole[mestoig_i - 1][mestoig_g - 1] == damka_y) && obpole[mestoig_i - 2][mestoig_g - 2] == bf)

				)
			{
				igrch = -1;
				std::cout << "Вам надо продолжить свой ход за ту же шашку(вам надо только ввести номер шашки которую хотите съесть)\n";
				if (obpole[mestoig_i - 1][mestoig_g + 1] == bfy || obpole[mestoig_i - 1][mestoig_g + 1] == damka_y)
				{
					if (obpole[mestoig_i - 1][mestoig_g + 1] == damka_y)
					{
						obpole[mestoig_i - 1][mestoig_g + 1] = food_bfy + 1;
					}
					else
					{
						obpole[mestoig_i - 1][mestoig_g + 1] = food_bfy;
					}

					std::cout << "ssssssssKKKKKKKKKKKKK\n";

				}
				if (obpole[mestoig_i - 1][mestoig_g - 1] == bfy || obpole[mestoig_i - 1][mestoig_g - 1] == damka_y)
				{
					obpole[mestoig_i - 1][mestoig_g - 1] = food_bfy;
					if (obpole[mestoig_i - 1][mestoig_g - 1] == damka_y)
					{
						obpole[mestoig_i - 1][mestoig_g - 1] = food_bfy + 1;
					}
					else
					{
						obpole[mestoig_i - 1][mestoig_g - 1] = food_bfy;
					}
					std::cout << "ssssssssHHHHHHHHHHHHHHHHHHH\n";
				}
			}
		}
		else if (obpole[mestoig_i][mestoig_g] != damka_y && igrok == 2 && obpole[mestoig_i][mestoig_g] != damka_x)
		{
			if (
				( (obpole[mestoig_i - 1][mestoig_g + 1] == bfx || obpole[mestoig_i - 1][mestoig_g + 1] == damka_x) && obpole[mestoig_i - 2][mestoig_g + 2] == bf) ||
				( (obpole[mestoig_i - 1][mestoig_g - 1] == bfx || obpole[mestoig_i - 1][mestoig_g - 1] == damka_x) && obpole[mestoig_i - 2][mestoig_g - 2] == bf)

				)
			{
				prov = true;
				igrch = -1;
				std::cout << "Вам надо продолжить свой ход за ту же шашку(вам надо только ввести номер шашки которую хотите съесть)\n";
				if (obpole[mestoig_i - 1][mestoig_g + 1] == bfx || obpole[mestoig_i - 1][mestoig_g + 1] == damka_x)
				{
					if (obpole[mestoig_i - 1][mestoig_g + 1] == damka_x)
					{
						obpole[mestoig_i - 1][mestoig_g + 1] = food_bfx + 1;
					}
					else
					{
						obpole[mestoig_i - 1][mestoig_g + 1] = food_bfx;
					}

					std::cout << "ssssssssKKKKKKKKKKKKK\n";

				}
				if (obpole[mestoig_i - 1][mestoig_g - 1] == bfx || obpole[mestoig_i - 1][mestoig_g - 1] == damka_x)
				{
					obpole[mestoig_i - 1][mestoig_g - 1] = food_bfx;
					if (obpole[mestoig_i - 1][mestoig_g - 1] == damka_x)
					{
						obpole[mestoig_i - 1][mestoig_g - 1] = food_bfx + 1;
					}
					else
					{
						obpole[mestoig_i - 1][mestoig_g - 1] = food_bfx;
					}
					std::cout << "ssssssssHHHHHHHHHHHHHHHHHHH\n";

				}
				
			}
			if (
				( (obpole[mestoig_i + 1][mestoig_g + 1] == bfx || obpole[mestoig_i + 1][mestoig_g + 1] == damka_x) && obpole[mestoig_i + 2][mestoig_g + 2] == bf) ||
				( (obpole[mestoig_i + 1][mestoig_g - 1] == bfx || obpole[mestoig_i + 1][mestoig_g - 1] == damka_x) && obpole[mestoig_i + 2][mestoig_g - 2] == bf)
				)
			{
				std::cout << "Вам надо продолжить свой ход за ту же шашку(вам надо только ввести номер шашки которую хотите съесть)\n";
				if (obpole[mestoig_i + 1][mestoig_g + 1] == bfy || obpole[mestoig_i + 1][mestoig_g + 1] == damka_y)
				{
					if (obpole[mestoig_i + 1][mestoig_g + 1] == damka_x)
					{
						obpole[mestoig_i + 1][mestoig_g + 1] = food_bfx + 1;
					}
					else
					{
						obpole[mestoig_i + 1][mestoig_g + 1] = food_bfx;
					}
					std::cout << "ssssssss\n";
				}
				if (obpole[mestoig_i + 1][mestoig_g - 1] == bfx || obpole[mestoig_i + 1][mestoig_g - 1] == damka_x)
				{

					if (obpole[mestoig_i + 1][mestoig_g - 1] == damka_x)
					{
						obpole[mestoig_i + 1][mestoig_g - 1] = food_bfx + 1;
					}
					else
					{
						obpole[mestoig_i + 1][mestoig_g - 1] = food_bfx;
					}
					std::cout << "sggggggggggggg\n";
				}
				prov = true;
		}
			else if (obpole[mestoig_i][mestoig_g] == damka_y || obpole[mestoig_i][mestoig_g] == damka_x)
			{
				if (
					((obpole[mestoig_i - 1][mestoig_g + 1] == bfx || obpole[mestoig_i - 1][mestoig_g + 1] == bfy || obpole[mestoig_i - 1][mestoig_g + 1] == damka_x || obpole[mestoig_i - 1][mestoig_g + 1] == damka_y) && obpole[mestoig_i - 2][mestoig_g + 2] == bf) ||
					((obpole[mestoig_i - 1][mestoig_g - 1] == bfx || obpole[mestoig_i - 1][mestoig_g - 1] == bfy || obpole[mestoig_i - 1][mestoig_g - 1] == damka_x || obpole[mestoig_i - 1][mestoig_g - 1] == damka_y) && obpole[mestoig_i - 2][mestoig_g - 2] == bf) ||
					((obpole[mestoig_i + 1][mestoig_g + 1] == bfx || obpole[mestoig_i + 1][mestoig_g + 1] == bfy || obpole[mestoig_i + 1][mestoig_g + 1] == damka_x || obpole[mestoig_i + 1][mestoig_g + 1] == damka_y) && obpole[mestoig_i + 2][mestoig_g + 2] == bf) ||
					((obpole[mestoig_i + 1][mestoig_g - 1] == bfx || obpole[mestoig_i + 1][mestoig_g - 1] == bfy || obpole[mestoig_i + 1][mestoig_g - 1] == damka_x || obpole[mestoig_i + 1][mestoig_g - 1] == damka_y) && obpole[mestoig_i + 2][mestoig_g - 2] == bf)
					)
				{
					std::cout << "Вам надо продолжить свой ход за ту же шашку(вам надо только ввести номер шашки которую хотите съесть)\n";
					prov = true;
					if (igrok == 2)
					{
						if (obpole[mestoig_i - 1][mestoig_g + 1] == bfx || obpole[mestoig_i - 1][mestoig_g + 1] == damka_x)
						{
							igrch = -1;
							std::cout << "1LLLLLLLLLLLLLL\n";
							if (obpole[mestoig_i - 1][mestoig_g + 1] == damka_x)
							{
								obpole[mestoig_i - 1][mestoig_g + 1] = food_bfy + 1;
							}
							else
							{
								obpole[mestoig_i - 1][mestoig_g + 1] = food_bfy;
							}
						}
						if (obpole[mestoig_i - 1][mestoig_g - 1] == bfx || obpole[mestoig_i - 1][mestoig_g - 1] == damka_x)
						{
							igrch = -1;
							std::cout << "2LLLLLLLLLLLLLL\n";
							if (obpole[mestoig_i - 1][mestoig_g - 1] == damka_x)
							{
								obpole[mestoig_i - 1][mestoig_g - 1] = food_bfy + 1;
							}
							else
							{
								obpole[mestoig_i - 1][mestoig_g - 1] = food_bfy;
							}
						}
						if (obpole[mestoig_i + 1][mestoig_g + 1] == bfx || obpole[mestoig_i + 1][mestoig_g + 1] == damka_x)
						{
							igrch = 1;
							std::cout << "3LLLLLLLLLLLLLL\n";
							if (obpole[mestoig_i + 1][mestoig_g + 1] == damka_x)
							{
								obpole[mestoig_i + 1][mestoig_g + 1] = food_bfy + 1;
							}
							else
							{
								obpole[mestoig_i + 1][mestoig_g + 1] = food_bfy;
							}
						}
						if (obpole[mestoig_i + 1][mestoig_g - 1] == bfx || obpole[mestoig_i + 1][mestoig_g - 1] == damka_x)
						{
							igrch = 1;
							std::cout << "4LLLLLLLLLLLLLL\n";
							if (obpole[mestoig_i + 1][mestoig_g - 1] == damka_x)
							{
								obpole[mestoig_i + 1][mestoig_g - 1] = food_bfy + 1;
							}
							else
							{
								obpole[mestoig_i + 1][mestoig_g - 1] = food_bfy;
							}
						}
					}
					if (igrok == 1)
					{
						if (obpole[mestoig_i - 1][mestoig_g + 1] == bfy || obpole[mestoig_i - 1][mestoig_g + 1] == damka_y)
						{
							igrch = -1;
							if (obpole[mestoig_i - 1][mestoig_g + 1] == damka_y)
							{
								obpole[mestoig_i - 1][mestoig_g + 1] = food_bfx + 1;
							}
							else
							{
								obpole[mestoig_i - 1][mestoig_g + 1] = food_bfx;
							}
						}
						if (obpole[mestoig_i - 1][mestoig_g - 1] == bfy || obpole[mestoig_i - 1][mestoig_g - 1] == damka_y)
						{
							igrch = -1;
							if (obpole[mestoig_i - 1][mestoig_g - 1] == damka_y)
							{
								obpole[mestoig_i - 1][mestoig_g - 1] = food_bfx + 1;
							}
							else
							{
								obpole[mestoig_i - 1][mestoig_g - 1] = food_bfx;
							}
						}
						if (obpole[mestoig_i + 1][mestoig_g + 1] == bfy || obpole[mestoig_i + 1][mestoig_g + 1] == damka_y)
						{
							igrch = 1;
							if (obpole[mestoig_i + 1][mestoig_g + 1] == damka_y)
							{
								obpole[mestoig_i + 1][mestoig_g + 1] = food_bfx + 1;
							}
							else
							{
								obpole[mestoig_i + 1][mestoig_g + 1] = food_bfx;
							}
						}
						if (obpole[mestoig_i + 1][mestoig_g - 1] == bfy || obpole[mestoig_i + 1][mestoig_g - 1] == damka_y)
						{
							igrch = 1;
							if (obpole[mestoig_i + 1][mestoig_g - 1] == damka_y)
							{
								obpole[mestoig_i + 1][mestoig_g - 1] = food_bfx + 1;
							}
							else
							{
								obpole[mestoig_i + 1][mestoig_g - 1] = food_bfx;
							}
						}
					}

				}


			}
		}
		
		
	if (prov == true)
	{
		std::cout << "Введите номер шашки которую хотите съесть(сначала цифра, потом буква)\n";
		int polhod_i{ 0 };
		int polhod_g{ 0 };
		char promhodpol_g;
		do
		{
			std::cin >> polhod_i;
			std::cin >> promhodpol_g;

			polhod_g = promhodpol_g - 65;
			polhod_i--;
			if (obpole[polhod_i][polhod_g] != food_bfx && obpole[polhod_i][polhod_g] != food_bfy && obpole[polhod_i][polhod_g] != (food_bfx + 1) && obpole[polhod_i][polhod_g] != (food_bfy + 1))
			{
				std::cout << "Вы не можете так походить\n";
			}
		} while (obpole[polhod_i][polhod_g] != food_bfx && obpole[polhod_i][polhod_g] != food_bfy && obpole[polhod_i][polhod_g] != (food_bfx + 1) && obpole[polhod_i][polhod_g] != (food_bfy + 1));

		


		int prom_polhod_g{ polhod_g };
		

		if (mestoig_g + 1 == polhod_g)
		{
			std::swap(obpole[mestoig_i][mestoig_g], obpole[polhod_i + igrch][polhod_g + 1]);
			prom_polhod_g += 1;
		}
		else if (mestoig_g - 1 == polhod_g)
		{
			std::swap(obpole[mestoig_i][mestoig_g], obpole[(polhod_i + igrch)][polhod_g - 1]);
			prom_polhod_g -= 1;
		}
		obpole[polhod_i][polhod_g] = bf;
		for (int i = 0; i < razobpole; i++)
		{
			for (int g = 0; g < razobpole; g++)
			{
				if (obpole[i][g] == eat_bfx || obpole[i][g] == food_bfx)
				{
					obpole[i][g] = bfx;
				}
				else if (obpole[i][g] == eat_bfy || obpole[i][g] == food_bfy)
				{
					obpole[i][g] = bfy;
				}
				else if (obpole[i][g] == eat_bfy + 1 || obpole[i][g] == food_bfy + 1)
				{
					obpole[i][g] = damka_y;
				}
				else if (obpole[i][g] == eat_bfx + 1 || obpole[i][g] == food_bfx + 1)
				{
					obpole[i][g] = damka_x;
				}
			}
		}
		   prodeat(obpole, razobpole, (polhod_i + igrch), prom_polhod_g, igrok);
	}
}

bool provpobeda(int obpole[][razobpole], int razobpole)
{
	setlocale(LC_ALL, "RU");
	int prov = true;
	int kolys{ 0 }, kolxs{ 0 };
	int koltuy{ 0 }, koltux{ 0 };

	for (int i = 0; i < razobpole; i++)
	{
		for (int g = 0; g < razobpole; g++)
		{
			if (obpole[i][g] == bfx || obpole[i][g] == damka_x)
			{
				kolxs++;
			}
			else if (obpole[i][g] == bfy || obpole[i][g] == damka_y)
			{
				kolys++;
			}
			if (obpole[i][g] == bfx && i < (razobpole))
			{
				if (
					(obpole[i + 1][g + 1] != bf && obpole[i + 1][g - 1] != bf) &&
					(obpole[i + 2][g + 2] != bf && obpole[i + 2][g - 2] != bf)
					)
				{
					koltux++;
				}
			}
			else if (obpole[i][g] == bfy && i > 0)
			{
				if (
					
					(obpole[i - 1][g + 1] != bf && obpole[i - 1][g - 1] != bf) &&
					(obpole[i - 2][g + 2] != bf && obpole[i - 2][g - 2] != bf)
					)
				{
					koltuy++;
				}
				
			}
		}
	}
	if (kolys == 0 || koltuy == kolys)
	{
		std::cout << "Выйграл игрок X\n";
		prov = false;
	}
	else if (kolxs == 0 || koltux == kolxs)
	{
		std::cout << "Выйграл игрок Y\n";
		prov = false;
	}
  
	return prov;


}


void eat(int obpole[][razobpole], int razobpole)
{
	setlocale(LC_ALL, "RU");
	for (int i = 0; i < razobpole; i++)
	{
		for (int g = 0; g < razobpole; g++)
		{
			
		}
	}

}

bool proveat(int obpole[][razobpole], int razobpole, int igrok)
{
	bool proveat = false;
	for (int i = 0; i < razobpole; i++)
	{
		for (int g = 0; g < razobpole; g++)
		{
			int promplus_g{ g };
			int promplus_i{ i };
			int prommin_i{ i };
			int prommin_g{ g };
			if (igrok == bfx && obpole[i][g] == bfx)
			{
				
					if
						(
							( (obpole[i + 1][g + 1] == bfy || obpole[i + 1][g + 1] == food_bfy || obpole[i + 1][g + 1] == eat_bfy || obpole[i + 1][g + 1] == damka_y)  && obpole[i + 2][g + 2] == bf) ||
							( (obpole[i + 1][g - 1] == bfy || obpole[i + 1][g - 1] == food_bfy || obpole[i + 1][g - 1] == eat_bfy || obpole[i + 1][g - 1] == damka_y) && obpole[i + 2][g - 2] == bf)
						)
					{
						proveat = true;
						obpole[i][g] = eat_bfx;
						if (obpole[i + 1][g + 1] == bfy || obpole[i + 1][g + 1] == food_bfy || obpole[i + 1][g + 1] == eat_bfy || obpole[i + 1][g + 1] == damka_y)
						{
							if (obpole[i + 1][g + 1] == damka_y)
							{
								obpole[i + 1][g + 1] = food_bfy + 1;
							}
							else
							{
								obpole[i + 1][g + 1] = food_bfy;
							}
							
						}
						if (obpole[i + 1][g - 1] == bfy || obpole[i + 1][g - 1] == food_bfy || obpole[i + 1][g - 1] == eat_bfy || obpole[i + 1][g - 1] == damka_y)
						{
							if (obpole[i + 1][g - 1] == damka_y)
							{
								obpole[i + 1][g - 1] = food_bfy + 1;
							}
							else
							{
								obpole[i + 1][g - 1] = food_bfy;
							}
						}
					}
			}
			
			else if (igrok == bfy && obpole[i][g] == bfy)
			{
				
					if
						(
							( (obpole[i - 1][g + 1] == bfx || obpole[i - 1][g + 1] == food_bfx || obpole[i - 1][g + 1] == eat_bfx || obpole[i - 1][g + 1] == damka_x) && obpole[i - 2][g + 2] == bf ) ||
							( (obpole[i - 1][g - 1] == bfx || obpole[i - 1][g - 1] == food_bfx || obpole[i - 1][g - 1] == eat_bfx || obpole[i - 1][g - 1] == damka_x) && obpole[i - 2][g - 2] == bf )
						)
					{
						proveat = true;
						obpole[i][g] = eat_bfy;
						
						if (obpole[i - 1][g + 1] == bfx || obpole[i - 1][g + 1] == food_bfx || obpole[i - 1][g + 1] == eat_bfx || obpole[i - 1][g + 1] == damka_x)
						{
							
							if (obpole[i - 1][g + 1] == damka_x)
							{
								obpole[i - 1][g + 1] = food_bfx + 1;
							}
							else
							{
								obpole[i - 1][g + 1] = food_bfx;
							}
						}
						if (obpole[i - 1][g - 1] == bfx || obpole[i - 1][g - 1] == food_bfx || obpole[i - 1][g - 1] == eat_bfx || obpole[i - 1][g - 1] == damka_x)
						{
							
							if (obpole[i - 1][g - 1] == damka_x)
							{
								obpole[i - 1][g - 1] = food_bfx + 1;
							}
							else
							{
								obpole[i - 1][g - 1] = food_bfx;
							}
						}
					}
				

			}
			else if (obpole[i][g] == damka_y || obpole[i][g] == damka_x)
			{
				
				
				while ( (promplus_g < razobpole || promplus_i < razobpole) || (prommin_g > 0 || prommin_i > 0 ) )
				{
					
					promplus_g++;
					promplus_i++;
					prommin_g--;
					prommin_i--;

					if (igrok == bfy)
					{
						
						if (
							(  (obpole[prommin_i][prommin_g] == bfx || obpole[prommin_i][prommin_g] == damka_x || obpole[prommin_i][prommin_g] == food_bfx) && obpole[prommin_i - 1][prommin_g - 1] == bf ) || 
							(  (obpole[prommin_i][promplus_g] == bfx || obpole[prommin_i][promplus_g] == damka_x || obpole[prommin_i][promplus_g] == food_bfx) && obpole[prommin_i - 1][promplus_g + 1] == bf ) ||
							(  (obpole[promplus_i][prommin_g] == bfx || obpole[promplus_i][prommin_g] == damka_x || obpole[promplus_i][prommin_g] == food_bfx) && obpole[promplus_i + 1][prommin_g - 1] == bf )  ||
							(  (obpole[promplus_i][promplus_g] == bfx || obpole[promplus_i][promplus_g] == damka_x || obpole[promplus_i][promplus_g] == food_bfx) && obpole[promplus_i + 1][promplus_g + 1] == bf )
							)
						{
							
							obpole[i][g] = eat_bfy + 1;
							if (obpole[prommin_i][prommin_g] == bfx || obpole[prommin_i][prommin_g] == damka_x || obpole[prommin_i][prommin_g] == food_bfx)
							{
								if (obpole[prommin_i][prommin_g] == damka_x)
								{
									obpole[prommin_i][prommin_g] = food_bfx + 1;
								}
								else
								{
									obpole[prommin_i][prommin_g] = food_bfx;
								}
								proveat = true;
							}
							else if (obpole[prommin_i][promplus_g] == bfx || obpole[prommin_i][promplus_g] == damka_x || obpole[prommin_i][promplus_g] == food_bfx)
							{
								if (obpole[prommin_i][promplus_g] == damka_x)
								{
									obpole[prommin_i][promplus_g] = food_bfx + 1;
								}
								else
								{
									obpole[prommin_i][promplus_g] = food_bfx;
								}
								proveat = true;
							}
							else if (obpole[promplus_i][prommin_g] == bfx || obpole[promplus_i][prommin_g] == damka_x || obpole[promplus_i][prommin_g] == food_bfx)
							{
								if (obpole[promplus_i][prommin_g] == damka_x)
								{
									obpole[promplus_i][prommin_g] = food_bfx + 1;
								}
								else
								{
									obpole[promplus_i][prommin_g] = food_bfx;
								}
								proveat = true;
							}
							else if (obpole[promplus_i][promplus_g] == bfx || obpole[promplus_i][promplus_g] == damka_x || obpole[promplus_i][promplus_g] == food_bfx)
							{
								if (obpole[promplus_i][promplus_g] == damka_x)
								{
									obpole[promplus_i][promplus_g] = food_bfx + 1;
								}
								else
								{
									obpole[promplus_i][promplus_g] = food_bfx;
								}
								proveat = true;
							}
						}
					}
					else if (igrok == bfx)
					{
						
						if (
							(obpole[prommin_i][prommin_g] == bfy || obpole[prommin_i][prommin_g] == damka_y || obpole[prommin_i][prommin_g] == food_bfy) && obpole[prommin_i - 1][prommin_g - 1] == bf ||
							(obpole[prommin_i][promplus_g] == bfy || obpole[prommin_i][promplus_g] == damka_y || obpole[prommin_i][promplus_g] == food_bfy) && obpole[prommin_i - 1][promplus_g + 1] == bf ||
							(obpole[promplus_i][prommin_g] == bfy || obpole[promplus_i][prommin_g] == damka_y || obpole[promplus_i][prommin_g] == food_bfy) && obpole[promplus_i + 1][prommin_g - 1] == bf ||
							(obpole[promplus_i][promplus_g] == bfy || obpole[promplus_i][promplus_g] == damka_y || obpole[promplus_i][promplus_g] == food_bfy) && obpole[promplus_i + 1][promplus_g + 1] == bf
							)
						{
							obpole[i][g] = eat_bfx + 1;
							proveat = true;
							if (obpole[prommin_i][prommin_g] == bfy || obpole[prommin_i][prommin_g] == damka_y || obpole[prommin_i][prommin_g] == food_bfy)
							{
								if (obpole[prommin_i][prommin_g] == damka_y)
								{
									obpole[prommin_i][prommin_g] = food_bfy + 1;
								}
								else
								{
									obpole[prommin_i][prommin_g] = food_bfy;
								}
							}
							else if (obpole[prommin_i][promplus_g] == bfy || obpole[prommin_i][promplus_g] == damka_y || obpole[prommin_i][promplus_g] == food_bfy)
							{
								if (obpole[prommin_i][promplus_g] == damka_y)
								{
									obpole[prommin_i][promplus_g] = food_bfy + 1;
								}
								else
								{
									obpole[prommin_i][promplus_g] = food_bfy;
								}
							}
							else if (obpole[promplus_i][prommin_g] == bfy || obpole[promplus_i][prommin_g] == damka_y || obpole[promplus_i][prommin_g] == food_bfy)
							{
								if (obpole[promplus_i][prommin_g] == damka_y)
								{
									obpole[promplus_i][prommin_g] = food_bfy + 1;
								}
								else
								{
									obpole[promplus_i][prommin_g] = food_bfy;
								}
							}
							else if (obpole[promplus_i][promplus_g] == bfy || obpole[promplus_i][promplus_g] == damka_y || obpole[promplus_i][promplus_g] == food_bfy)
							{
								if (obpole[promplus_i][promplus_g] == damka_y)
								{
									obpole[promplus_i][promplus_g] = food_bfy + 1;
								}
								else
								{
									obpole[promplus_i][promplus_g] = food_bfy;
								}
								proveat = true;
							}
						}
					}
				}
			}
			
		}
		
	}
	return proveat;
}


bool provhoda(int obpole[][razobpole], int razobpole, int koordmesta_i, int koordmesta_g, int koordhod_i, int koordhod_g, int igr, bool eat)
{
	bool prov = true;
	if (eat == false)
	{
		if (obpole[koordmesta_i][koordmesta_g] != igr )
		{
			if (igr == bfx && obpole[koordmesta_i][koordmesta_g] != damka_x)
			{
				std::cout << "Координаты клетки указывают не на вашу фишку. Перепишите координаты фишки\n";
				prov = false;
			}
			if (igr == bfy && obpole[koordmesta_i][koordmesta_g] != damka_y)
			{
				std::cout << "Координаты клетки указывают не на вашу фишку. Перепишите координаты фишки\n";
				prov = false;
			}
		}
	    if (obpole[koordmesta_i][koordmesta_g] == damka_x || obpole[koordmesta_i][koordmesta_g] == damka_y)
		{
			
			int raz_i{ 0 }, raz_g{ 0 };
			raz_i = abs(koordmesta_i - koordhod_i);
			raz_g = abs(koordmesta_g - koordhod_g);
			if (raz_i != raz_g)
			{
				prov = false;
				std::cout << "Ход невозможен\n";
			}
		}
		else if ( (igr == bfx) && (koordmesta_i != koordhod_i - 1) || (koordmesta_g != koordhod_g + 1 && koordmesta_g != koordhod_g - 1))
		{
			std::cout << "Ваш ход невозможен\n";
			prov = false;
		}
		else if ( (igr == bfy) && (koordmesta_i != koordhod_i + 1) || (koordmesta_g != koordhod_g + 1 && koordmesta_g != koordhod_g - 1))
		{
			std::cout << "Ваш ход невозможен\n";
			prov = false;
		}
		else if ((igr == bfx) && (obpole[koordhod_i][koordhod_g] != bf))
		{
			std::cout << "Это поле уже занято. Вам придётся написать другие координаты\n";
			
			prov = false;
		}
		
	}
	else
	{
		if (igr  == bfx  && (obpole[koordmesta_i][koordmesta_g] != eat_bfx && obpole[koordmesta_i][koordmesta_g] != eat_bfx + 1) )
		{
			prov = false;
			std::cout << "Ход невозможен11111111111111\n";
		}
		else if (igr == bfy && (obpole[koordmesta_i][koordmesta_g] != eat_bfy && obpole[koordmesta_i][koordmesta_g] != eat_bfy + 1) )
		{
			prov = false;
			std::cout << "Ход невозможен2222222222222\n";
		}
		if (igr == bfx && (obpole[koordhod_i][koordhod_g] != food_bfy && obpole[koordhod_i][koordhod_g] != food_bfy + 1) )
		{
			prov = false;
			std::cout << "Ход невозможен333333\n";
		}
		else if (igr == bfy && (obpole[koordhod_i][koordhod_g] != food_bfx && obpole[koordhod_i][koordhod_g] != food_bfx + 1) )
		{
			prov = false;
			std::cout << "Ход невозможен4444444444\n";
		}
	}
	return prov;
}

void igra(int obpole[][razobpole], int const razobpole, bool prov, int igrok)
{
	setlocale(LC_ALL, "RU");

	char buc;
	bool proverkaeat = false;
	int igrch{ 1 };
	
	
	if (igrok == 1)
	{
		buc = 'x';
	}
	else
	{
		buc = 'y';
	}
	int shahki{ 0 };
	if (igrok == 1)
	{
		shahki = bfx;
		igrch = 1;
	}
	else if (igrok == 2)
	{
		shahki = bfy;
		igrch = -1;
	}

	
	proverkaeat = proveat(obpole, razobpole, shahki);
	

	if (prov == true )
	{
		bool provhod = false;
		int mesto_i, mesto_g;
		char prommesto_g;
		int polhod_i, polhod_g;
		char promhodpol_g;
		while (provhod == false)
		{
			if (proverkaeat == true)
			{
				std::cout << "Игроку " << buc <<  " надо обязательно 'съесть' шашку.введите шашку который хотите съесть, затем введите номер шашки которую хотите съесть\n";
				std::cout << "Напишите координаты шашки которой хотите съесть(сначала цифра, потом буква)\n";
			}
			else
			{
				std::cout << "Сейчас ход игрока " << buc << ". Напишите координаты клетки шашки которой хотите сходить (сначала цифра, потом буква)\n";
			}
			
			do
			{
				std::cin >> mesto_i;
				std::cin >> prommesto_g;
			} while (mesto_i < 1 && mesto_i > 9 || prommesto_g < 65 && prommesto_g < 72 );
			mesto_g = prommesto_g - 65;
			mesto_i--;
			if (proverkaeat == true)
			{
				std::cout << "Теперь, напишите координаты клетки шашки которой хотите съесть, пожалуйста (сначала цифра, потом буква)\n";
			}
			else
			{
				std::cout << "Теперь, напишите координаты клетки куда хотите сходить, пожалуйста (сначала цифра, потом буква)\n";
			}
			do
			{
				std::cin >> polhod_i;
				std::cin >> promhodpol_g;
			} while (mesto_i < 1 && mesto_i > 9 || prommesto_g < 65 && prommesto_g < 72);
			
			polhod_g = promhodpol_g - 65;
			polhod_i--;
			

			

			provhod = provhoda(obpole, razobpole, mesto_i, mesto_g, polhod_i, polhod_g, shahki, proverkaeat);
		}
		if (proverkaeat == false)
		{
			std::swap(obpole[mesto_i][mesto_g], obpole[polhod_i][polhod_g]);
		}
		else
		{
			int raz_g{ 0 }, raz_i{ 0 };
			raz_g = (mesto_g - polhod_g);
			raz_i = ( polhod_i - mesto_i);
			if (raz_i > 0)
			{
				igrch = 1;
			}
			else
			{
				igrch = -1;
			}
			int prom_polhod_g = polhod_g;
			if (mesto_g + 1 == polhod_g)
			{
				std::swap( obpole[mesto_i][mesto_g], obpole[polhod_i + igrch][polhod_g + 1]);
				prom_polhod_g = prom_polhod_g + 1;
			}
			else if ( (obpole[mesto_i][mesto_g] == (eat_bfx + 1) || obpole[mesto_i][mesto_g] == (eat_bfy + 1) ) && raz_g > 0)
			{
				std::swap(obpole[mesto_i][mesto_g], obpole[polhod_i + igrch][polhod_g - 1]);
				prom_polhod_g = prom_polhod_g - 1;
			}
			else if (mesto_g - 1 == polhod_g)
			{
				std::swap(obpole[mesto_i][mesto_g], obpole[ (polhod_i + igrch) ][polhod_g - 1]);
				prom_polhod_g = prom_polhod_g - 1;
			}
			else if ((obpole[mesto_i][mesto_g] == (eat_bfx + 1) || obpole[mesto_i][mesto_g] == (eat_bfy + 1)) && raz_g < 0)
			{
				std::swap(obpole[mesto_i][mesto_g], obpole[polhod_i + igrch][polhod_g + 1]);
				prom_polhod_g = prom_polhod_g + 1;
			}
			obpole [polhod_i][polhod_g] = bf;
			for (int i = 0; i < razobpole; i++)
			{
				for (int g = 0; g < razobpole; g++)
				{
					if (obpole[i][g] == eat_bfx || obpole[i][g] == food_bfx)
					{
						obpole[i][g] = bfx;
					}
					else if (obpole[i][g] == eat_bfy || obpole[i][g] == food_bfy)
					{
						obpole[i][g] = bfy;
					}
					else if (obpole[i][g] == (food_bfx + 1) || obpole[i][g] == (eat_bfx + 1))
					{
						obpole[i][g] = damka_x;
					}
					else if ( obpole[i][g] == (food_bfy + 1) || obpole[i][g] == (eat_bfy + 1))
					{
						obpole[i][g] = damka_y;
					}
					
				}
			}
			
			prodeat(obpole, razobpole, (polhod_i + igrch), prom_polhod_g, igrok);
		}
	

		
	}

	
}

void nachras(int obpole[][razobpole], int razobpole)
{
	for (int i = 0; i < razobpole; i++)
	{
		for (int g = 0; g < razobpole; g++)
		{
			if (i % 2 == 0)
			{
				if (g % 2 != 0)
				{
					obpole[i][g] = bf;
					if (i < 3)
					{
						obpole[i][g] = bfx;
					}
					else if (i > 4)
					{
						obpole[i][g] = bfy;
					}
				}
			
				else
				{
					obpole[i][g] = 0;
				}

			}
			else if (i % 2 != 0)
			{
				if (g % 2 != 0)
				{
					obpole[i][g] = wf;
				}
				else
				{
					obpole[i][g] = bf;
					if (i < 3)
					{
						obpole[i][g] = bfx;
					}
					if (i > 4)
					{
						obpole[i][g] = bfy;
					}
				}
			}
			
		}
		
	}
	
	
}

void vpole(char pole[][razpoleg], int rpolei, int rpoleg, int obpole[][razobpole], int razobpole)
{
	for (int i = 0, max_i = 3; i < razobpole; i++)
	{
		
		for (int g = 0, max_g = 3; g < razobpole; g++)
		{
			
			if (obpole[i][g] == wf)
			{
				for (int ki = (max_i - 3); ki < max_i; ki++)
				{
					for (int kg = (max_g - 3); kg < max_g; kg++)    
					{


						pole[ki][kg] = '+';


					}

				}
			}
			else if (obpole[i][g] == bf || obpole[i][g] == bfx || obpole[i][g] == bfy || obpole[i][g] == damka_x || obpole[i][g] == damka_y )
			{
				int prov = 0;
				for (int ki = (max_i - 3); ki < max_i; ki++)
				{
					for (int kg = (max_g - 3); kg < max_g; kg++)
					{
						
						pole[ki][kg] = ' ';
						if ((obpole[i][g]) == bfx && prov == 4)
						{
							pole[ki][kg] = 'x';
							
						}
						else if (obpole[i][g] == bfy && prov == 4)
						{
							pole[ki][kg] = 'y';
						}
						else if (obpole[i][g] == damka_x && prov == 4)
						{
							pole[ki][kg] = 'X';
						}
						else if (obpole[i][g] == damka_y && prov == 4)
						{
							pole[ki][kg] = 'Y';
						}
						prov++;
					

					}


				}
				
			}
			max_g = max_g + 3;
		}
		max_i = max_i + 3;

		
	}
	int promchisla{ 1 };
	int provchisla{ 0 };
	char promb = 65;
	int provb{ 0 };
	for (int i = -1; i < razpolei; i++)
	{
		if (i >= 0)
		{
			std::cout << promchisla;
			provchisla++;
			if (provchisla == 3)
			{
				promchisla++;
				provchisla = 0;
			}
		}
		for (int g = 0; g < razpoleg; g++)
		{
			
			if (i == -1)
			{
				provb++;
				if (g == 0)
				{
					std::cout << " " << promb;
				}
				else
				{
					std::cout << promb;
				}
				if (provb == 3)
				{
					promb++;
					provb = 0;
				}
				
			}
			else
			{
				std::cout << pole[i][g];
			}
			
			
		}
		std::cout << "\n";
	}
}