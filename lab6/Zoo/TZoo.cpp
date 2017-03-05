#include "TZoo.h"


using namespace std;

TZoo::TZoo(size_t capacity)
	: Capacity(capacity)
	, Time(0)
{
	NumAnimals = Animals.size();
}

bool TZoo::AddNewAnimal(TAnimal ** newAnimal)
{
	// Ïðîâåðÿåì êîððåêòíîñòü âõîäíîãî ïàðàìåòðà
	if (newAnimal == nullptr)
		return false;

	// Çîîïàðê ïîëîí, íåëüçÿ äîáàâèòü íîâîãî çâåðÿ
	if (NumAnimals == Capacity)
		return false;

	// Äîáàâëÿåì çâåðÿ â ìàññèâ
	Animals.push_back(*newAnimal);

	// Çàáèðàåì çâåðÿ ó ñòàðîãî âëàäåëüöà, ÷òîáû íå óäàëèòü çâåðÿ äâàæäû
	*newAnimal = nullptr;

	// Óâåëè÷èâàåì ñ÷åò÷èê
	NumAnimals = Animals.size();

	return true;
}

void TZoo::Work()
{
	cout << "Time is " << Time << '\n';
	for (size_t i = 0; i < NumAnimals; ++i)
	{
		if (Animals[i] != nullptr)
		{
			// Äåìîíñòðàöèÿ ðàáîòû äèíàìè÷åñêîãî ïîëèìîðôèçìà
			Animals[i]->Live(Time);
			if (Animals[i]->Death(Time))
			{
				Kill(Animals[i]);
			}
		}
	}
	Time += STEP;
	if (Time == 24)
		Time -= 24;
}

void TZoo::Kill(TAnimal * animal)
{
	int ind = -1;
	for (int i = 0; i < NumAnimals; i++)
	{
		if (Animals[i]->GetName() == animal->GetName())
		{
			ind = i;
		}
	}
	if (ind != -1)
	{
		cout << animal->GetName() << " is dead!!" << '\n';
		Animals.erase(Animals.begin() + ind);
		NumAnimals = Animals.size();
	}
}

void TZoo::FinishDay()
{
	for (int i = 0; i < NumAnimals; i++)
	{
		Animals[i]->EndDay();
	}
}

void TZoo::Print()
{
	cout << "The Zooolaaanndddd" << '\n';
	cout << "|------|-------|------|" << '\n';
	for (int i = 0; i < NumAnimals; i++)
	{
		cout << Animals[i]->GetName() << " It is " << Animals[i]->GetAge() << " year" << '\n';
	}
	cout << "|------|-------|------|" << '\n';
	cout << '\n';
}

void TZoo::CheckBirthday(int day)
{
	for (int i = 0; i < NumAnimals; i++)
	{
		Animals[i]->Birthday(day);
	}
}

bool TZoo::Empty()
{
	if (NumAnimals == 0)
		return true;
	else
		return false;
}

void TZoo::Born()
{
	vector<TPtrAnimal> An1;
	for (int i = 0; i < NumAnimals; i++)
	{
		if (Animals[i]->GetDayChild() <= 0)
		{
			An1.push_back(Animals[i]);
		}
	}
	if (An1.size() > 1)
	{
		for (int i = 0; i < An1.size() - 1; i++)
		{
			for (int j = i + 1; j < An1.size(); j++)
			{
				if (!An1[i]->GetFlagChild() && !An1[j]->GetFlagChild())
				{
					if (An1[i]->GetKey() == An1[j]->GetKey())
					{
						TAnimal * NewAnimal;
						NewAnimal = GetNewAnimal(An1[i]->GetKey());
						if (!AddNewAnimal(&NewAnimal))
						{
							cout << "Add new animal is Not succeed" << '\n';
							delete NewAnimal;
						}
						else
						{
							cout << " Add new animal is succeed " << '\n';
							An1[i]->ChangeFlagChild();
							An1[j]->ChangeFlagChild();
						}
					}
				}
			}
		}
	}
}

TAnimal * TZoo::Delete(std::string name)
{
	int ind = -1;
	for (int i = 0; i < NumAnimals; i++)
	{
		if (Animals[i]->GetName() == name)
		{
			ind = i;
			break;
		}
	}
	if (ind == -1)
		return nullptr;

	TAnimal * RemoveAnimal = Animals[ind];
	Animals.erase(Animals.begin() + ind);
	NumAnimals = Animals.size();

	return RemoveAnimal;
}

TZoo::~TZoo()
{
	Animals.clear();
}

TAnimal * GetNewAnimal(int key)
{
	string NewName;
	TAnimal * NewAnimal = nullptr;
	int year = 1;

	switch (key)
	{
	case 1:
	{
		NewName = "Giraffa";
		NewAnimal = new TGiraffa(NewName, year);
		break;
	}
	case 2:
	{
		NewName = "Hippopotamus";
		NewAnimal = new THippopotamus(NewName, year);
		break;
	}
	case 3:
	{
		NewName = "Elephas";
		NewAnimal = new TElephas(NewName, year);
		break;
	}
	case 4:
	{
		NewName = "Loxodonta";
		NewAnimal = new TLoxodonta(NewName, year);
		break;
	}
	case 5:
	{
		NewName = "Leo";
		NewAnimal = new TLeo(NewName, year);
		break;
	}
	case 6:
	{
		NewName = "Tigris";
		NewAnimal = new TTigr(NewName, year);
		break;
	}
	}
	return NewAnimal;
}

TAnimal * NewAnimal(string name, int kind, int year)
{
	TAnimal * NewAnimal = nullptr;
	switch (kind)
	{
	case 1:
	{
		NewAnimal = new TGiraffa(name, year);
		break;
	}
	case 2:
	{
		NewAnimal = new THippopotamus(name, year);
		break;
	}
	case 3:
	{
		NewAnimal = new TElephas(name, year);
		break;
	}
	case 4:
	{
		NewAnimal = new TLoxodonta(name, year);
		break;
	}
	case 5:
	{
		NewAnimal = new TLeo(name, year);
		break;
	}
	case 6:
	{
		NewAnimal = new TTigr(name, year);
		break;
	}
	}
	return NewAnimal;
}

