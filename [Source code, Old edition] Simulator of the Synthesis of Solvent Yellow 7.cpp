#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <time.h>
#include <cmath>
#include <math.h>
#include <algorithm>
#include <fstream>
#include <cstring>
#include <String>
#include <string.h>
#include <conio.h>

#define HSK_EPSILON 1e-10
#define HSK_INF_SERIES 3.5
#define HSK_PI 3.14159265358979323846

using namespace std;

int HCl;
int PhNH2;
int PhOH;
int NaNO2;
int NaOH;
int pipettor = 1000;
int startandend = 1;
int restreagent = 97;
int maxAbsset = 1;
int Am[4];
int groupsAmax = 0;
int maxA = 179037;
int groups[601];
int Abs[2400][601][10];
int cal[2400];
int dev;
double devt[100];
int vin;
int maxAv;
int maxAcal[601];
int maxAbs[601][10];
int maxAbsuncertainty[601][10];
int startaveragetime;
int savecode[601][10];
int HNO2[100];
int delmax[100];
int del[100];
int code = 0;
double X[100];
double Y[100];
float slope;
float intercept;
float um;
float ub;
float R2;


double HskErf(double x)
{
	double ans = 0;
	static double k = 2/sqrt(HSK_PI);
	if(x >= HSK_INF_SERIES)
	{
		double x2 = -1/(x*x);
		double an = k*exp(-x*x)/(x*2);
		double n;
		for(n=1; n < 5; ++n)
		{
			ans += an;
			an *= (n-0.5)*x2;
		}
		return (1-ans);
	}
	else
	{
		double x2 = -x*x;
		double an = k*x;
		double n;
		for(n = 1; 2*abs(an) > HSK_EPSILON; ++n)
		{
			ans += an;
			an *= (1-1/(n+0.5))*x2/n;
		}
		return ans;
	}
}

void pause()
{
//	cout << "Press enter to continue . . . ";
	system("pause");
	return;
}

int random100()
{
	int randnum,  r1, r2, r3;
	r1 = rand()%96;
	r2 = rand()%100;
	r3 = rand()%10;
	if(r1 == 95)
	{
		r2 = rand()%98;
		if(r2 == 97)
		{
			r3 = rand()%5;
		}
	}
	randnum = r1*1000+r2*10+r3;
	int r = rand()%2;
	int lastnum = rand()%10;
	lastnum -= 5;
	if(r)
	{
		if(randnum < 1080) return 800+lastnum;
		if(randnum < 2392) return 810+lastnum;
		if(randnum < 3972) return 820+lastnum;
		if(randnum < 5852) return 830+lastnum;
		if(randnum < 8070) return 840+lastnum;
		if(randnum < 10660) return 850+lastnum;
		if(randnum < 13654) return 860+lastnum;
		if(randnum < 17082) return 870+lastnum;
		if(randnum < 20966) return 880+lastnum;
		if(randnum < 25324) return 890+lastnum;
		if(randnum < 30164) return 900+lastnum;
		if(randnum < 35486) return 910+lastnum;
		if(randnum < 41280) return 920+lastnum;
		if(randnum < 47526) return 930+lastnum;
		if(randnum < 54190) return 940+lastnum;
		if(randnum < 61232) return 950+lastnum;
		if(randnum < 68598) return 960+lastnum;
		if(randnum < 76226) return 970+lastnum;
		if(randnum < 84046) return 980+lastnum;
		if(randnum < 91986) return 990+lastnum;
	}
	if(randnum < 1080) return 1200+lastnum;
	if(randnum < 2392) return 1190+lastnum;
	if(randnum < 3972) return 1180+lastnum;
	if(randnum < 5852) return 1170+lastnum;
	if(randnum < 8070) return 1160+lastnum;
	if(randnum < 10660) return 1150+lastnum;
	if(randnum < 13654) return 1140+lastnum;
	if(randnum < 17082) return 1130+lastnum;
	if(randnum < 20966) return 1120+lastnum;
	if(randnum < 25324) return 1110+lastnum;
	if(randnum < 30164) return 1100+lastnum;
	if(randnum < 35486) return 1090+lastnum;
	if(randnum < 41280) return 1080+lastnum;
	if(randnum < 47526) return 1070+lastnum;
	if(randnum < 54190) return 1060+lastnum;
	if(randnum < 61232) return 1050+lastnum;
	if(randnum < 68598) return 1040+lastnum;
	if(randnum < 76226) return 1030+lastnum;
	if(randnum < 84046) return 1020+lastnum;
	if(randnum < 91986) return 1010+lastnum;
	return 1000+lastnum;
}

int random30()
{
	int randnum, r1, r2, r3;
	r1 = rand()%32;
	r2 = rand()%100;
	r3 = rand()%10;
	if(r1 == 31)
	{
		r2 = rand()%66;
		if(r2 == 65)
		{
			r3 = rand()%7;
		}
	}
	randnum = r1*1000+r2*10+r3;
	int r = rand()%2;
	int lastnum = rand()%10;
	lastnum -= 5;
	if(r)
	{
		if(randnum < 1580) return 360+lastnum;
		if(randnum < 4170) return 350+lastnum;
		if(randnum < 8054) return 340+lastnum;
		if(randnum < 13376) return 330+lastnum;
		if(randnum < 20040) return 320+lastnum;
		if(randnum < 27668) return 310+lastnum;
	}
	if(randnum < 1580) return 240+lastnum;
	if(randnum < 4170) return 250+lastnum;
	if(randnum < 8054) return 260+lastnum;
	if(randnum < 13376) return 270+lastnum;
	if(randnum < 20040) return 280+lastnum;
	if(randnum < 27668) return 290+lastnum;
	return 300+lastnum;
}

int random5()
{
	int randnum, r1, r2;
	r1 = rand()%100;
	r2 = rand()%100;
	randnum = r1*100+r2;
	int lastnum = rand()%5;
	lastnum -= 2;
	if(randnum < 540) return 60+lastnum;
	if(randnum < 2960) return 55+lastnum;
	if(randnum < 5380) return 45+lastnum;
	if(randnum < 5920) return 40+lastnum;
	return 50+lastnum;
}

int randnuml()
{
	int r = rand()%13;
	r -= 6;
	r *= 5;
	r += 150;
	return r;
}

int randnums()
{
	int r = rand()%7;
	r -= 3;
	r *= 5;
	r += 50;
	return r;
}


void principles()
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	cout << "I. Principles of this Experiment" << endl;
	cout << "Nitric acid reacts with anilines to form diazonium in acids." << endl;
	cout << "In this experiment, we will prepare a solution of phenyldiazonium chloride from aniline hydrochloride and acidified sodium nitrite using this diazotization reaction." << endl;
	cout << "Then, phenyldiazonium chloride reacts with phenol when the HCl was partially neutralized, to form a para-sustituted product, solvent yellow 7 [4-(phenyldiazenyl)phenol]." << endl;
	cout << "[Figure 1]" << endl;
	pause();
	cout << "We will employ flow chemistry systems due to the hazardous and challenging nature of the reaction, stemming from the explosive and unstable phenyldiazonium chloride intermediate." << endl;
	cout << "The two-step process will be continuously conducted in coil reactors (each measuring 2.0 m in length with 1 mL internal volume), with a four-channel syringe pump positioned at the inlet to deliver reactants into the system at a constant flow rate." << endl;
	cout << "[Figure 2]" << endl;
	pause();
	cout << "The phenyldiazonium chloride intermediate, continuously formed within the coil reactors, undergoes immediate coupling with phenol upon their controlled combination in the secondary reactor." << endl;
	cout << "This sequential process ensures electrophilic aromatic substitution kinetics dominate over azobenzene cation generation, as evidenced by the substitution rate substantially outpacing cation formation." << endl;
	cout << "Literature-established reaction orders confirm the diazotization step follows third-order kinetics, first-order with respect to aniline concentration and second-order dependent on nitrite availability." << endl;
	cout << "Therefore, " << endl;
	cout << "[Equation 1]" << endl;
	cout << "This rate law was rewritten to reflect the concentration evolution along the reactor, assuming a constant flow rate." << endl;
	cout << "[Figure 3]" << endl;
	cout << "[Equation 2]" << endl;
	pause();
	cout << "Then, we can integrate the concentration evolution to find a linear relationship." << endl;
	cout << "[Equation 3]" << endl;
	cout << "Under low-flow-rate conditions, the reaction achieves near-completion status through residence time optimization." << endl;
	cout << "Triplicate absorbance measurements are conducted to determine the average maximum absorbance value (Am)." << endl;
	cout << "Subsequent experimental phases employ flow rate modulation to systematically vary reaction residence times." << endl;
	cout << "For each designated residence time (t), the corresponding absorbance measurement is recorded as At." << endl;
	pause();
	cout << "Bring them into Beer-Lambert Law:" << endl;
	cout << "[Equation 4]" << endl;
	cout << "Put the initial concentrations into the two equations, then:" << endl;
	cout << "[Equation 5]" << endl;
	cout << "Finnaly, [Formula 1] is marked as Y, and[Formula 2] is marked as X." << endl;
	cout << "Then there is Y=kX, where k is the observed rate constant. After measuring Ats for different ts and calculating corresponding Xs and Y, we can derive the rate constant for the synthesis of solvent yellow 7 from Y-X graph." << endl;
	pause();
	cout << endl;
	cout << "Then, let's calculate the theoritical weight of the reactants." << endl;
	cout << "Our target is to prepare 1000 mL 0.010 M aniline in 0.1% hydrochloric acid, 1000 mL 0.060 M sodium hydroxide in deionized water, 1000 mL 0.010 M phenol in deionized water." << endl;
	cout << "The 0.1% hydrochloric acid will be diluted from 37% HCl with deionized water. We will prepare 2000 mL at a time." << endl;
	cout << "100 mL 0.011 M sodium nitrite in 0.1% hydrochloric acid will be prepared just before each group of experiment." << endl;
	cout << "Our starting materials are listed below:" << endl;
	cout << "Hydrochloric aicd(37% aq, 1.19g/mL)" << endl;
	cout << "aniline(l, 1.022g/mL)" << endl;
	cout << "phenol(s)" << endl;
	cout << "sodium hydroxide(s)" << endl;
	cout << "sodium nitrite(s)" << endl;
	cout << "deionized water" << endl;
	cout << "100-1000uL pipette and 2000/1000/100 mL volume flasks will be provided." << endl;
	cout << "Hint: Your answer should be accurate to 5uL or 1mg." << endl;
	pause();
	int checkweight = 1;
	string calinput;
	while(checkweight)
	{
		cout << "You will pipette 37% HCl for 5 times, the volume each time should be (in uL):";
		cin >> calinput;
		if(calinput.length() == 3)
		{
			HCl = (int(calinput[0])-48)*100+(int(calinput[1])-48)*10+(int(calinput[2])-48);
		}
		else
		{
			HCl = 0;
		}
		if(HCl == 910)
		{
			cout << "Correct." << endl;
			checkweight = 0;
		}
		else
		{
			cout << "Your answer is incorrect." << endl;
		}
	}
	checkweight = 1;
	while(checkweight)
	{
		cout << "The volume of aniline should be (in uL):";
		cin >> calinput;
		if(calinput.length() == 3)
		{
			PhNH2 = (int(calinput[0])-48)*100+(int(calinput[1])-48)*10+(int(calinput[2])-48);
		}
		else
		{
			PhNH2 = 0;
		}
		if(PhNH2 == 910)
		{
			cout << "Correct." << endl;
			checkweight = 0;
		}
		else
		{
			cout << "Your answer is incorrect." << endl;
		}
	}
	checkweight = 1;
	while(checkweight)
	{
		cout << "The weight of phenol should be (in mg):";
		cin >> calinput;
		if(calinput.length() == 3)
		{
			PhOH = (int(calinput[0])-48)*100+(int(calinput[1])-48)*10+(int(calinput[2])-48);
		}
		else
		{
			PhOH = 0;
		}
		if(PhOH == 941)
		{
			cout << "Correct." << endl;
			checkweight = 0;
		}
		else
		{
			cout << "Your answer is incorrect." << endl;
		}
	}
	checkweight = 1;
	while(checkweight)
	{
		cout << "The weight of sodium hydroxide should be (in mg):" ;
		cin >> calinput;
		if(calinput.length() == 4)
		{
			NaOH = (int(calinput[0])-48)*1000+(int(calinput[1])-48)*100+(int(calinput[2])-48)*10+(int(calinput[3])-48);
		}
		else
		{
			NaOH = 0;
		}
		if(NaOH == 2400)
		{
			cout << "Correct." << endl;
			checkweight = 0;
		}
		else
		{
			cout << "Your answer is incorrect." << endl;
		}
	}
	checkweight = 1;
	while(checkweight)
	{
		cout << "The weight of sodium nitrite should be (in mg):";
		cin >> calinput;
		if(calinput.length() == 2)
		{
			NaNO2 = (int(calinput[0])-48)*10+(int(calinput[1])-48);
		}
		else
		{
			NaNO2 = 0;
		}
		if(NaNO2 == 76)
		{
			cout << "Correct." << endl;
			checkweight = 0;
		}
		else
		{
			cout << "Your answer is incorrect." << endl;
			cout << NaNO2;
		}
	}
}

void build()
{
	printf("\n\n\n\n\n");
	cout << "II. Setting up the Equipments" << endl;
	cout << "[image of the whole quipment]" << endl;
	cout << "Key in integers between 1 and 15, to move the part with same number." << endl;
	int buildstate = 15;
	string buildinginput;
	int buildinput;
	int buildpart[15] = {0};
	while(buildstate)
	{
		cout << "The moving part's number:" << endl;
		cin >> buildinginput;
		if(buildinginput.length() == 1)
		{
			buildinput = int(buildinginput[0]) - 48;
		}
		else if(buildinginput.length() == 2)
		{
			buildinput = (int(buildinginput[0]) - 48)*10+(int(buildinginput[1]) - 48);
		}
		else
		{
			buildinput = 0;
		}
		if(buildinput < 1)
		{
			cout << "invalid input" << endl;
		}
		else if(buildinput > 15)
		{
			cout << "invalid input" << endl;
		}
		else if(buildpart[buildinput-1])
		{
			cout << "You have already moved it to the right place. There is no need to move it again." << endl;
		}
		else
		{
			buildstate--;
			buildpart[buildinput-1] = 1;
			if(buildinput < 5)
			{
				cout << "Syringe " << buildinput << " is in place." << endl;
			}
			else if(buildinput < 8)
			{
				cout << "T-mixer " << (buildinput-4) << " is in place." << endl;
			}
			else if(buildinput < 10)
			{
				cout << "Coil reactor " << (buildinput-7) << " is in place." << endl;
			}
			else if(buildinput < 15)
			{
				cout << "Short tube " << (buildinput-9) << " is in place." << endl;
			}
			else
			{
				cout << "The spectroscope is in place." << endl;
			}
		}
	}
	cout << "You have finished this part." << endl << endl;
}

void phenolprint()
{
	cout << "Theoritical weight: 0.941 g" << endl;
	cout << "Current weight: " << PhOH/10000 << "." << (PhOH/1000)%10 << (PhOH/100)%10 << (PhOH/10)%10 << PhOH%10 << " g" << endl;
}

int phenolcheck()
{
	if(PhOH < 9410)
	{
		return 0;
	}
	if(PhOH > 9882)
	{
		return 0;
	}
	return 1;
}

void phenol()
{
	cout << "You are preparing 1000 mL 0.010 M phenol solution:" << endl;
	cout << "Weigh 0.941 g phenol." << endl;
	PhOH = 0;
	cout << "You can finish the part when your current value is between 1 and 1.05 times of theoritical weight." << endl;
	cout << "Key in +++ to add about 100 mg, ++ to add about 30 mg, + to add about 5 mg, - to restart, OK to finish." << endl;
	int state = 1;
	string input;
	while(state)
	{
		phenolprint();
		cin >> input;
		if(input == "+++")
		{
			PhOH += random100();
		}
		else if(input == "++")
		{
			PhOH += random30();
		}
		else if(input == "+")
		{
			PhOH += random5();
		}
		else if(input == "-")
		{
			PhOH = 0;
		}
		else if(input == "OK")
		{
			if(phenolcheck())
			{
				cout << "You have completed the weighing of phenol." << endl;
				cout << "The actual weight of phenol: " << PhOH/10000 << "." << (PhOH/1000)%10 << (PhOH/100)%10 << (PhOH/10)%10 << PhOH%10 << " g" << endl;
				state = 0;
				cout << "Dissolve phenol in deionized water, and transfer into a 1000 mL volume flask, fixing to 1000 mL ..." << endl;
				pause();
				cout << "You have completed the preparation of phenol solution." << endl;
				printf("\n\n\n\n\n");
			}
			else
			{
				cout << "The current weight cannot reach the requirements." << endl;
			}
		}
		else
		{
			cout << "invalid input" << endl;
		}
	}
}

void sodiumhydroxideprint()
{
	cout << "Theoritical weight: 2.400 g" << endl;
	cout << "Current weight: " << NaOH/10000 << "." << (NaOH/1000)%10 << (NaOH/100)%10 << (NaOH/10)%10 << NaOH%10 << " g" << endl;
}

int sodiumhydroxidecheck()
{
	if(NaOH < 22800)
	{
		return 0;
	}
	if(NaOH > 25200)
	{
		return 0;
	}
	return 1;
}

void Sodium_hydroxide()
{
	cout << "You are preparing 1000 mL 0.060 M sodium hydroxide solution:" << endl;
	cout << "Weigh 2.400 g sodium hydroxide." << endl;
	NaOH = 0;
	cout << "You can finish the part when your current value is between 0.95 and 1.05 times of theoritical weight." << endl;
	cout << "Key in +++ to add about 100 mg, ++ to add about 30 mg, + to add about 5 mg, - to restart, OK to finish." << endl;
	int state = 1;
	string input;
	while(state)
	{
		sodiumhydroxideprint();
		cin >> input;
		if(input == "+++")
		{
			NaOH += random100();
		}
		else if(input == "++")
		{
			NaOH += random30();
		}
		else if(input == "+")
		{
			NaOH += random5();
		}
		else if(input == "-")
		{
			NaOH = 0;
		}
		else if(input == "OK")
		{
			if(sodiumhydroxidecheck())
			{
				cout << "You have completed the weighing of sodium hydroxide." << endl;
				cout << "The actual weight of sodium hydroxide: " << NaOH/10000 << "." << (NaOH/1000)%10 << (NaOH/100)%10 << (NaOH/10)%10 << NaOH%10 << " g" << endl;
				state = 0;
				cout << "Dissolve sodium hydroxide in deionized water, and transfer into a 1000 mL volume flask, fixing to 1000 mL ..." << endl;
				pause();
				cout << "You have completed the preparation of phenol solution." << endl;
				printf("\n\n\n\n\n");
			}
			else
			{
				cout << "The current weight cannot reach the requirements." << endl;
			}
		}
		else
		{
			cout << "invalid input" << endl;
		}
	}
}

void pipettorprint()
{
	cout << "Target volume: 0.910 mL" << endl;
	cout << "Current volume: " << pipettor/1000 << "." << (pipettor/100)%10 << (pipettor/10)%10 << pipettor%10 << " mL" << endl;
}

void changevolume()
{
	cout << "The volume of HCl and PhNH2 is the same: 0.910 mL." << endl;
	cout << "The maximum volume of the pipette is 1000 uL" << endl;
	cout << "Key in +++/---/++/-- to adjust the volume faster, or +/- to adjust accurately." << endl;
	pipettorprint();
	int state = 1;
	while(state)
	{
		string input;
		cin >> input;
		if(input == "+++")
		{
			pipettor += randnuml();
			if(pipettor > 1000)
			{
				pipettor = 1000;
			}
		}
		else if(input == "---")
		{
			pipettor -= randnuml();
			if(pipettor < 0)
			{
				pipettor = 0;
			}
		}
		else if(input == "++")
		{
			pipettor += randnums();
			if(pipettor > 1000)
			{
				pipettor = 1000;
			}
		}
		else if(input == "--")
		{
			pipettor -= randnums();
			if(pipettor < 0)
			{
				pipettor = 0;
			}
		}
		else if(input == "+")
		{
			if(pipettor < 1000)
			{
				pipettor += 5;
			}
		}
		else if(input == "-")
		{
			if(pipettor > 0)
			{
				pipettor -= 5;
			}
		}
		else
		{
			cout << "invalid input" << endl;
		}
		pipettorprint();
		if(pipettor == 910)
		{
			cout << "You have adjusted the pipette to the correct volume." << endl;
			pause();
			printf("\n\n\n");
			state = 0;
		}
	}
}

void hydrochloride()
{
	cout << "You are preparing 2000 mL 0.1% hydrochloric acid solution:" << endl;
	cout << "Transfer 37% hydrochloric acid into a 2000 mL volume flask for 5 times..." << endl;
	pause();
	cout << "4.550 mL 37% hydrochloric acid have been transfered in total. Deionized water is used to fix the volume to 2000 mL..." << endl;
	pause();
	cout << "You have finished the preparation of hydrochloric acid solution." << endl;
	printf("\n\n\n\n\n");
	HCl = 2000;
}

void aniline()
{
	cout << "You are preparing 1000 mL 0.010 M aniline solution:" << endl;
	cout << "Transfer aniline into a 1000 mL volume flask..." << endl;
	pause();
	cout << "0.910 mL aniline have been transfered in total. Deionized water is used to fix the volume to 2000 mL..." << endl;
	pause();
	cout << "You have finished the preparation of aniline solution." << endl;
	printf("\n\n\n\n\n");
	HCl -= 1000;
}

void sodiumnitriteprint()
{
	cout << "Theoritical weight: 0.076 g" << endl;
	cout << "Current weight: " << NaNO2/10000 << "." << (NaNO2/1000)%10 << (NaNO2/100)%10 << (NaNO2/10)%10 << NaNO2%10 << " g" << endl;
}

int sodiumnitritecheck()
{
	if(NaNO2 < 760)
	{
		return 0;
	}
	if(NaNO2 > 840)
	{
		return 0;
	}
	return 1;
}

void sodiumnitrite()
{
	cout << "You are preparing 100 mL 0.011 M sodium nitrite solution:" << endl;
	cout << "Weigh 0.076 g sodium nitrite." << endl;
	NaNO2 = 0;
	if(HCl < 100)
	{
		cout << "0.1% HCl is not enough. Prepare 2000 mL 0.1% HCl again." << endl;
		hydrochloride();
	}
	cout << "You can finish the part when your current value is between 1 and 1.05 times of theoritical weight." << endl;
	cout << "Key in +++ to add about 100 mg, ++ to add about 30 mg, + to add about 5 mg, - to restart, OK to finish." << endl;
	int state = 1;
	string input;
	while(state)
	{
		sodiumnitriteprint();
		cin >> input;
		if(input == "+++")
		{
			NaNO2 += random100();
		}
		else if(input == "++")
		{
			NaNO2 += random30();
		}
		else if(input == "+")
		{
			NaNO2 += random5();
		}
		else if(input == "-")
		{
			NaNO2 = 0;
		}
		else if(input == "OK")
		{
			if(sodiumnitritecheck())
			{
				cout << "You have completed the weighing of sodium hydroxide." << endl;
				cout << "The actual weight of sodium nitrite: " << NaNO2/10000 << "." << (NaNO2/1000)%10 << (NaNO2/100)%10 << (NaNO2/10)%10 << NaNO2%10 << "g" << endl;
				state = 0;
				cout << "Dissolve sodium nitrite in deionized water, and transfer into a 100 mL volume flask, fixing to 100 mL ..." << endl;
				HCl -= 100;
				pause();
				cout << "You have completed the preparation of phenol solution." << endl;
			}
			else
			{
				cout << "The current weight cannot reach the requirements." << endl;
			}
		}
		else
		{
			cout << "invalid input" << endl;
		}
	}
}

int speedinput()
{
	string s;
	cin >> s;
	int v[2];
	v[0] = 0;
	v[1] = 0;
	int tp = 0;
	for(int i = 0; i < int(s.size()); i++)
	{
		if(s[i] == '.')
		{
			tp++;
		}
		else
		{
			if(tp == 0)
			{
				v[0] = int(s[i])-48;
			}
			else if(tp == 1)
			{
				v[1] = int(s[i])-48;
				v[1] *= 10;
				tp++;
			}
			else
			{
				v[1] += int(s[i])-48;
				return v[0]*100+v[1];
			}
		}
	}
	return v[0]*100+v[1];
}

int testcheck()
{
	int checking = 0;
	for(int i = 50; i < 601; i++)
	{
		if(groups[i])
		{
			checking++;
		}
		if(checking > 4)
		{
			return 1;
		}
	}
	return 0;
}

int Absmaxcal(int HNO2, int speed)
{
	double c1, c2;
	c1 = (910*1.022)/93.126*0.001;
	c2 = (double(HNO2)/690)*0.01;
	int Absmaxcalculate;
	double dif = 1000;
	double t = 12000/speed;
	for(int i = 20000; i < 179000; i++)
	{
		double dift = 3053*t*(c2-c1)*(c2-c1);
		dift -= 1;
		dift -= (log(c1/c2));
		dift += (c1/c2);
		dift += (maxA*(c2-c1)/(maxA*c2-i*c1));
		dift += log((maxA-i)*c1/(maxA*c2-i*c1));
		if(dift < 0)
		{
			dift = -dift;
		}
		if(dift < dif)
		{
			dif = dift;
			Absmaxcalculate = i;
		}
	}
	return Absmaxcalculate;
}

void calculate(int speed)
{
	maxAv = Absmaxcal(NaNO2, speed);
	int diffusechk = 1;
	double residencetime = 12000/speed;
	double diffusetime;
	double diffusecoefficient;
	for(int i = 0; i < 2400; i++)
	{
		if(diffusechk == 1)
		{		
			diffusetime = (1280-2000/residencetime*i)/sqrt(200*i);
			
			diffusecoefficient = 1-HskErf(diffusetime);
			diffusecoefficient /= 2;
			if(diffusecoefficient >= 0.9999)
			{
				diffusechk = 0;
				startaveragetime = i;
			}
		}
		if(diffusechk == 1)
		{
			cal[i] = diffusecoefficient*maxAv;
		}
		else
		{
			cal[i] = maxAv;
		}
	}
}

int random()
{
	int r = rand()%401;
	r -= 200;
	return r;
}

int deviation()
{
	int randnum, r1, r2, r3;
	r1 = rand()%49;
	r2 = rand()%100;
	r3 = rand()%10;
	randnum = r1*1000+r2*10+r3;
	int r = rand()%2;
	int lastnum = rand()%51;
	lastnum -= 25;
	if(r)
	{
		if(randnum < 1080) return 500+lastnum;
		if(randnum < 2660) return 450+lastnum;
		if(randnum < 4878) return 400+lastnum;
		if(randnum < 7872) return 350+lastnum;
		if(randnum < 11756) return 300+lastnum;
		if(randnum < 16596) return 250+lastnum;
		if(randnum < 22390) return 200+lastnum;
		if(randnum < 29054) return 150+lastnum;
		if(randnum < 36420) return 100+lastnum;
		if(randnum < 44240) return 50+lastnum;
	}
	if(randnum < 1080) return -500+lastnum;
	if(randnum < 2660) return -450+lastnum;
	if(randnum < 4878) return -400+lastnum;
	if(randnum < 7872) return -350+lastnum;
	if(randnum < 11756) return -300+lastnum;
	if(randnum < 16596) return -250+lastnum;
	if(randnum < 22390) return -200+lastnum;
	if(randnum < 29054) return -150+lastnum;
	if(randnum < 36420) return -100+lastnum;
	if(randnum < 44240) return -50+lastnum;
	return lastnum;
}

void output()
{
	FILE *fp;
	fp = fopen("D:\\Abs-t.txt", "w");
	fprintf(fp, "phenol: 0.%d g\n", PhOH);
	fprintf(fp, "sodium hydroxide: 0.%d g\n", NaOH);
	for(int i = 250; i < 6010; i++)
	{
		if(savecode[i/10][i%10])
		{
			fprintf(fp, "\n(%d) v = %d.%d%d mL/min\n", savecode[i/10][i%10], i/1000, (i/100)%10, (i/10)%10);
			fprintf(fp, "maxAbs = %d.%d%d%d%d%d\n", maxAbs[i/10][i%10]/100000, (maxAbs[i/10][i%10]/10000)%10, (maxAbs[i/10][i%10]/1000)%10, (maxAbs[i/10][i%10]/100)%10, (maxAbs[i/10][i%10]/10)%10, maxAbs[i/10][i%10]%10);
			fprintf(fp, "s = %d.%d%d%d%d%d\n", maxAbsuncertainty[i/10][i%10]/100000, (maxAbsuncertainty[i/10][i%10]/10000)%10, (maxAbsuncertainty[i/10][i%10]/1000)%10, (maxAbsuncertainty[i/10][i%10]/100)%10, (maxAbsuncertainty[i/10][i%10]/10)%10, maxAbsuncertainty[i/10][i%10]%10);
			for(int j = 0; j < 60000/(i/10); j++)
			{
				fprintf(fp, "%d %d.%d%d%d%d%d\n", j+1, Abs[j][i/10][i%10]/100000, (Abs[j][i/10][i%10]/10000)%10, (Abs[j][i/10][i%10]/1000)%10, (Abs[j][i/10][i%10]/100)%10, (Abs[j][i/10][i%10]/10)%10, Abs[j][i/10][i%10]%10);
			}
		}
	}
	fprintf(fp, "\nend\n");
}

void displayAbs(int speed)
{
	int finaltime = 60000/speed;
	dev = deviation();
	for(int i = 0; i < 1200; i++)
	{
		Abs[i][speed][groups[speed]] = cal[i] * (1+random()*0.00002) * (1+dev*0.00005);
		if(i < finaltime)
		{
			int t[4], a[6];
			t[0] = i/1000;
			t[1] = (i/100)%10;
			t[2] = (i/10)%10;
			t[3] = i%10;
			a[0] = Abs[i][speed][groups[speed]]/100000;
			a[1] = (Abs[i][speed][groups[speed]]/10000)%10;
			a[2] = (Abs[i][speed][groups[speed]]/1000)%10;
			a[3] = (Abs[i][speed][groups[speed]]/100)%10;
			a[4] = (Abs[i][speed][groups[speed]]/10)%10;
			a[5] = Abs[i][speed][groups[speed]]%10;
			if(t[0] == 0)
			{
				if(t[1] == 0)
				{
					if(t[2] == 0)
					{
						
						printf("   %d ", t[3]);
					}
					else
					{
						printf("  %d%d ", t[2], t[3]);
					}
				}
				else
				{
					printf(" %d%d%d ", t[1], t[2], t[3]);
				}
			}
			else
			{
				printf("%d%d%d%d ", t[0], t[1], t[2], t[3]);
			}
			printf("%d.%d%d%d%d%d\n", a[0], a[1], a[2], a[3], a[4], a[5]);
		}
	}
	cout << "The syringes are empty. The program is analyzing data ...";
	pause();
	startaveragetime++;
	maxAbs[speed][groups[speed]] = 0;
	double sum = 0;
	for(int i = startaveragetime; i < finaltime; i++)
	{
		sum += Abs[i][speed][groups[speed]]*0.00001;
	}
	sum /= (finaltime - startaveragetime);
	maxAbs[speed][groups[speed]] = sum*100000;
	maxAbsuncertainty[speed][groups[speed]] = 0;
	for(int i = startaveragetime; i < finaltime; i++)
	{
		maxAbsuncertainty[speed][groups[speed]] += (Abs[i][speed][groups[speed]] - maxAbs[speed][groups[speed]])*(Abs[i][speed][groups[speed]] - maxAbs[speed][groups[speed]]);
	}
	maxAbsuncertainty[speed][groups[speed]] /= (finaltime - startaveragetime);
	double sqrtroot = sqrt(maxAbsuncertainty[speed][groups[speed]]);
	maxAbsuncertainty[speed][groups[speed]] = sqrtroot;
	maxAbsuncertainty[speed][groups[speed]] %= 1000000;
	printf("maxAbs: %d.%d%d%d%d%d s=%d.%d%d%d%d%d\n", maxAbs[speed][groups[speed]]/100000, (maxAbs[speed][groups[speed]]/10000)%10, (maxAbs[speed][groups[speed]]/1000)%10, (maxAbs[speed][groups[speed]]/100)%10, (maxAbs[speed][groups[speed]]/10)%10, maxAbs[speed][groups[speed]]%10, maxAbsuncertainty[speed][groups[speed]]/100000, (maxAbsuncertainty[speed][groups[speed]]/10000)%10, (maxAbsuncertainty[speed][groups[speed]]/1000)%10, (maxAbsuncertainty[speed][groups[speed]]/100)%10, (maxAbsuncertainty[speed][groups[speed]]/10)%10, maxAbsuncertainty[speed][groups[speed]]%10);
	cout << "Key in save to save this group of data, or key in any other characters to continue: " << endl;
	string input;
	cin >> input;
	if(input == "save")
	{
		code++;
		savecode[speed][groups[speed]] = code;
		HNO2[code] = NaNO2;
		groups[speed]++;
		groups[speed] %= 10;
		if(code == 1)
		{
			cout << "1 group of data has been saved." << endl;
		}
		else
		{
			cout << code << " groups of data have been saved." << endl;
		}
		pause();
	}
	else
	{
		maxAbs[speed][groups[speed]] = 0;
		maxAbsuncertainty[speed][groups[speed]] = 0;
	}
}

void displayAbsmax(int speed)
{
	int finaltime = 60000/speed;
	dev = deviation();
	for(int i = 0; i < 2400; i++)
	{
		Abs[i][speed][groups[speed]] = cal[i] * (1+random()*0.00002) * (1+dev*0.00005);
		if(i < finaltime)
		{
			int t[4], a[6];
			t[0] = i/1000;
			t[1] = (i/100)%10;
			t[2] = (i/10)%10;
			t[3] = i%10;
			a[0] = Abs[i][speed][groups[speed]]/100000;
			a[1] = (Abs[i][speed][groups[speed]]/10000)%10;
			a[2] = (Abs[i][speed][groups[speed]]/1000)%10;
			a[3] = (Abs[i][speed][groups[speed]]/100)%10;
			a[4] = (Abs[i][speed][groups[speed]]/10)%10;
			a[5] = Abs[i][speed][groups[speed]]%10;
			if(t[0] == 0)
			{
				if(t[1] == 0)
				{
					if(t[2] == 0)
					{
						
						printf("   %d ", t[3]);
					}
					else
					{
						printf("  %d%d ", t[2], t[3]);
					}
				}
				else
				{
					printf(" %d%d%d ", t[1], t[2], t[3]);
				}
			}
			else
			{
				printf("%d%d%d%d ", t[0], t[1], t[2], t[3]);
			}
			printf("%d.%d%d%d%d%d\n", a[0], a[1], a[2], a[3], a[4], a[5]);
		}
	}
	cout << "The syringes are empty. The program is analyzing data ...";
	pause();
	startaveragetime++;
	maxAbs[speed][groups[speed]] = 0;
	double sum = 0;
	for(int i = startaveragetime; i < finaltime; i++)
	{
		sum += Abs[i][speed][groups[speed]]*0.00001;
	}
	sum /= (finaltime - startaveragetime);
	maxAbs[speed][groups[speed]] = sum*100000;
	maxAbsuncertainty[speed][groups[speed]] = 0;
	for(int i = startaveragetime; i < finaltime; i++)
	{
		maxAbsuncertainty[speed][groups[speed]] += (Abs[i][speed][groups[speed]] - maxAbs[speed][groups[speed]])*(Abs[i][speed][groups[speed]] - maxAbs[speed][groups[speed]]);
	}
	maxAbsuncertainty[speed][groups[speed]] /= (finaltime - startaveragetime);
	double sqrtroot = sqrt(maxAbsuncertainty[speed][groups[speed]]);
	maxAbsuncertainty[speed][groups[speed]] = sqrtroot;
	maxAbsuncertainty[speed][groups[speed]] %= 1000000;
	printf("maxAbs: %d.%d%d%d%d%d s=%d.%d%d%d%d%d\n", maxAbs[speed][groups[speed]]/100000, (maxAbs[speed][groups[speed]]/10000)%10, (maxAbs[speed][groups[speed]]/1000)%10, (maxAbs[speed][groups[speed]]/100)%10, (maxAbs[speed][groups[speed]]/10)%10, maxAbs[speed][groups[speed]]%10, maxAbsuncertainty[speed][groups[speed]]/100000, (maxAbsuncertainty[speed][groups[speed]]/10000)%10, (maxAbsuncertainty[speed][groups[speed]]/1000)%10, (maxAbsuncertainty[speed][groups[speed]]/100)%10, (maxAbsuncertainty[speed][groups[speed]]/10)%10, maxAbsuncertainty[speed][groups[speed]]%10);
	cout << "Key in save to save this group of data, or key in any other characters to continue: " << endl;
	string input;
	cin >> input;
	if(input == "save")
	{
		groupsAmax++;
		savecode[speed][groups[speed]] = groupsAmax;
		groups[speed]++;
		groups[speed] %= 10;
		pause();
		if(groupsAmax == 1)
		{
			cout << "1 group of data has been saved." << endl;
		}
		else
		{
			cout << groupsAmax << " groups of data have been saved." << endl;
		}
		pause();
	}
	else
	{
		maxAbs[speed][groups[speed]] = 0;
		maxAbsuncertainty[speed][groups[speed]] = 0;
	}
}

void analyseAbsmax()
{
	cout << "The serial number is consistent with the order of your experiments." << endl;
	cout << "Data is sorted by pump rate." << endl;
	for(int i = 250; i < 510; i++)
	{
		if(groups[i/10] > i%10)
		{
			printf("(%d) %d.%d%d%d%d%d s=%d.%d%d%d%d%d\n", savecode[i/10][i%10], maxAbs[i/10][i%10]/100000, (maxAbs[i/10][i%10]/10000)%10, (maxAbs[i/10][i%10]/1000)%10, (maxAbs[i/10][i%10]/100)%10, (maxAbs[i/10][i%10]/10)%10, maxAbs[i/10][i%10]%10, maxAbsuncertainty[i/10][i%10]/100000, (maxAbsuncertainty[i/10][i%10]/10000)%10, (maxAbsuncertainty[i/10][i%10]/1000)%10, (maxAbsuncertainty[i/10][i%10]/100)%10, (maxAbsuncertainty[i/10][i%10]/10)%10, maxAbsuncertainty[i/10][i%10]%10);
		}
	}
	for(int i = 0; i < 100; i++)
	{
		delmax[i] = 0;
	}
	cout << "Key in how many groups of data you would like to discard: ";
	int deletenum, deln;
	cin >> deletenum;
	int delnum = deletenum;
	while(delnum)
	{
		cout << "You are deleting a group of data. Its serial number: ";
		cin >> deln;
		delmax[deln] = 1;
		delnum--;
	}
	int averagemaxAbs = 0;
	int averagemaxAbsuncertainty = 0;
	for(int i = 250; i < 510; i++)
	{
		if(groups[i/10] > i%10)
		{
			if(delmax[savecode[i/10][i%10]])
			{
				;
			}
			else
			{
				printf("(%d) %d.%d%d%d%d%d s=%d.%d%d%d%d%d\n", savecode[i/10][i%10], maxAbs[i/10][i%10]/100000, (maxAbs[i/10][i%10]/10000)%10, (maxAbs[i/10][i%10]/1000)%10, (maxAbs[i/10][i%10]/100)%10, (maxAbs[i/10][i%10]/10)%10, maxAbs[i/10][i%10]%10, maxAbsuncertainty[i/10][i%10]/100000, (maxAbsuncertainty[i/10][i%10]/10000)%10, (maxAbsuncertainty[i/10][i%10]/1000)%10, (maxAbsuncertainty[i/10][i%10]/100)%10, (maxAbsuncertainty[i/10][i%10]/10)%10, maxAbsuncertainty[i/10][i%10]%10);
				averagemaxAbs += maxAbs[i/10][i%10];
			}
		}
	}
	averagemaxAbs /= (groupsAmax-deletenum);
	for(int i = 250; i < 510; i++)
	{
		if(groups[i/10] > i%10)
		{
			if(delmax[savecode[i/10][i%10]])
			{
				;
			}
			else
			{
				averagemaxAbsuncertainty += (maxAbs[i/10][i%10]-averagemaxAbs)*(maxAbs[i/10][i%10]-averagemaxAbs);
			}
		}
	}
	averagemaxAbsuncertainty /= (groupsAmax-deletenum);
	double sqrtroot = sqrt(averagemaxAbsuncertainty);
	averagemaxAbsuncertainty = sqrtroot;
	averagemaxAbsuncertainty %= 1000000;
	cout << "Absorbance of the complete reations: " << endl;
	printf("%d.%d%d%d%d%d s=%d.%d%d%d%d%d\n", averagemaxAbs/100000, (averagemaxAbs/10000)%10, (averagemaxAbs/1000)%10, (averagemaxAbs/100)%10, (averagemaxAbs/10)%10, averagemaxAbs%10, averagemaxAbsuncertainty/100000, (averagemaxAbsuncertainty/10000)%10, (averagemaxAbsuncertainty/1000)%10, (averagemaxAbsuncertainty/100)%10, (averagemaxAbsuncertainty/10)%10, averagemaxAbsuncertainty%10);
	pause();
	Am[0] = averagemaxAbs;
}

void least_square()
{
	double n, sxy, sx, sy, sx2;
	n = 0;
	sxy = 0;
	sx = 0;
	sy = 0;
	sx2 = 0;
	for(int i = 1; i <= code; i++)
	{
		if(del[i])
		{
			;
		}
		else
		{
			sxy += X[i]*Y[i];
			sx += X[i];
			sy += Y[i];
			sx2 += X[i]*X[i];
			n++;
		}
	}
	double m, b, D;
	D = sx2*n-sx*sx;
	m = sxy*n-sx*sy;
	b = sx2*sy-sxy*sx;
	slope = m/D;
	intercept = b/D;
	double sdi2, sdy, rup, rdown;
	sdi2 = 0;
	rup = 0;
	rdown = 0;
	for(int i = 1; i <= code; i++)
	{
		if(del[i])
		{
			;
		}
		else
		{
			sdi2 += (Y[i] - slope*X[i] - intercept)*(Y[i] - slope*X[i] - intercept);
			rup += (Y[i] - slope*X[i] - intercept)*(Y[i] - slope*X[i] - intercept);
			rdown += (Y[i] - sy/n)*(Y[i] - sy/n);
		}
	}
	sdy = sqrt(sdi2/(n-2));
	um = sdy*sqrt(n/D);
	ub = sdy*sqrt(sx2/D);
	R2 = 1-(rup/rdown);
	slope *= 10000;
}

int analyse()
{
	cout << "The serial number is consistent with the order of your experiments." << endl;
	cout << "Data is sorted by pump rate." << endl;
	for(int i = 500; i < 6010; i++)
	{
		if(savecode[i/10][i%10])
		{
			if(savecode[i/10][i%10] < 10)
			{
				printf(" (%d) ", savecode[i/10][i%10]);
			}
			else
			{
				printf("(%d) ", savecode[i/10][i%10]);
			}
			printf("v=%d.%d%d ", i/1000, (i/100)%10, (i/10)%10);
			printf("Abs=%d.%d%d%d%d%d s=%d.%d%d%d%d%d\n", maxAbs[i/10][i%10]/100000, (maxAbs[i/10][i%10]/10000)%10, (maxAbs[i/10][i%10]/1000)%10, (maxAbs[i/10][i%10]/100)%10, (maxAbs[i/10][i%10]/10)%10, maxAbs[i/10][i%10]%10, maxAbsuncertainty[i/10][i%10]/100000, (maxAbsuncertainty[i/10][i%10]/10000)%10, (maxAbsuncertainty[i/10][i%10]/1000)%10, (maxAbsuncertainty[i/10][i%10]/100)%10, (maxAbsuncertainty[i/10][i%10]/10)%10, maxAbsuncertainty[i/10][i%10]%10);
		}
	}
	for(int i = 0; i < 100; i++)
	{
		del[i] = 0;
	}
	cout << "Key in how many groups of data you would like to discard: ";
	int deletenum, deln;
	cin >> deletenum;
	int delnum = deletenum;
	while(delnum)
	{
		cout << "You are deleting a group of data. Its serial number: ";
		cin >> deln;
		del[deln] = 1;
		delnum--;
	}
	pause();
	printf("No.  maxAbs  At/Am    X       Y\n");
	for(int i = 50; i < 601; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			if(savecode[i][j])
			{
				if(del[savecode[i][j]])
				{
					;
				}
				else
				{
					if(savecode[i][j] < 10)
					{
						printf(" ");
					}
					printf("(%d) %d.%d%d%d%d%d ", savecode[i][j], maxAbs[i][j]/100000, (maxAbs[i][j]/10000)%10, (maxAbs[i][j]/1000)%10, (maxAbs[i][j]/100)%10, (maxAbs[i][j]/10)%10, maxAbs[i][j]%10);
					double AtAm = double(maxAbs[i][j])/double(Am[0]);
					int Atm = int(AtAm*1000000);
					printf("0.%d%d%d%d%d%d ", Atm/100000, (Atm/10000)%10, (Atm/1000)%10, (Atm/100)%10, (Atm/10)%10, Atm%10);
					double c1, c2;
					c1 = (double(HNO2[savecode[i][j]])/690)*0.01;
					c2 = (910*1.022)/93.126*0.001;
					X[savecode[i][j]] = (12000/i)*(c1-c2)*100*(c1-c2)*100;
					X[savecode[i][j]] /= 2;
					double YA, YB, YC;
					YA = (Am[0]-maxAbs[i][j])*c2;
					YB = Am[0]*c1-maxAbs[i][j]*c2;
					YC = Am[0]*(c1-c2);
					Y[savecode[i][j]] = log(YB/YA);
					Y[savecode[i][j]] -= (YC/YB);
					Y[savecode[i][j]] += log(c2/c1);
					Y[savecode[i][j]] -= c2/c1;
					Y[savecode[i][j]] += 1;
					if(X[savecode[i][j]] < 1)
					{
						printf("%.2lfE-5 %.4lf\n", X[savecode[i][j]]*10, Y[savecode[i][j]]);
					}
					else
					{
						printf("%.2lfE-4 %.4lf\n", X[savecode[i][j]], Y[savecode[i][j]]);
					}
					X[savecode[i][j]] *= 2;
//					cout << HNO2[savecode[i][j]] << " " << X[savecode[i][j]] << " " << c1 << " " << c2 << " " << Y[savecode[i][j]] << YA << " " << YB << " " << endl;
				}
			}
		}
	}
	printf("Apply least square method to the above data: ");
	pause();
	least_square();
	printf("No.  maxAbs   X       Y      deviation\n");
	for(int i = 50; i < 601; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			X[savecode[i][j]] /= 2;
			if(savecode[i][j])
			{
				if(del[savecode[i][j]])
				{
					;
				}
				else
				{
					if(savecode[i][j] < 10)
					{
						printf(" ");
					}
					printf("(%d) %d.%d%d%d%d%d ", savecode[i][j], maxAbs[i][j]/100000, (maxAbs[i][j]/10000)%10, (maxAbs[i][j]/1000)%10, (maxAbs[i][j]/100)%10, (maxAbs[i][j]/10)%10, maxAbs[i][j]%10);
					if(X[savecode[i][j]] < 1)
					{
						printf("%.2lfE-5 %.4lf ", X[savecode[i][j]]*10, Y[savecode[i][j]]);
					}
					else
					{
						printf("%.2lfE-4 %.4lf ", X[savecode[i][j]], Y[savecode[i][j]]);
					}
					devt[savecode[i][j]] = Y[savecode[i][j]] - slope*X[savecode[i][j]]*0.0001 - intercept;
					printf("%.4lf\n", devt[savecode[i][j]]);
				}
			}
			X[savecode[i][j]] *= 2;
		}
	}
	printf("slope:      %.2f(¡À%.2f)\n", slope*2, um);
	printf("intercept:  %.4f (¡À%.4f)\n", intercept*2, ub);
	printf("R2  =       %.4f\n", R2);
	printf("\nY = %.2f X ", slope*2);
	if(intercept < 0)
	{
		printf("-");
		printf(" %.4f\n\n", -intercept*2);
	}
	else
	{
		printf("+");
		printf(" %.4f\n\n", intercept*2);
	}
	cout << "Key in OK to save the results, or discard any groups of data and then analyse again." << endl;
	string input;
	cin >> input;
	if(input == "OK")
	{
		return 1;
	}
	return 0;
}

void outputresult()
{
	FILE *fp;
	fp = fopen("D:\\Abs-t_result.txt", "w");
	fprintf(fp, "slope = %.2f\n", slope);
	fprintf(fp, "intercept = %.3f\n", intercept);
	fprintf(fp, "R2 = %.4f\n", R2);
	fprintf(fp, "Phenol: 0.%d g\n", PhOH);
	fprintf(fp, "Sodium hydroxide: 0.%d g\n", NaOH);
	fprintf(fp, "Aniline: 0.910 mL\n\n");
	for(int i = 50; i < 601; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			if(savecode[i][j])
			{
				if(del[savecode[i][j]])
				{
					;
				}
				else
				{
					if(savecode[i][j] < 10)
					{
						fprintf(fp, " ");
					}
					fprintf(fp, "(%d) %d.%d%d%d%d%d ", savecode[i][j], maxAbs[i][j]/100000, (maxAbs[i][j]/10000)%10, (maxAbs[i][j]/1000)%10, (maxAbs[i][j]/100)%10, (maxAbs[i][j]/10)%10, maxAbs[i][j]%10);
					if(X[savecode[i][j]] < 0.1)
					{
						fprintf(fp, "%.4lf %.4lf ", X[savecode[i][j]], Y[savecode[i][j]]);
					}
					else
					{
						fprintf(fp, "%.3lf  %.4lf ", X[savecode[i][j]], Y[savecode[i][j]]);
					}
					fprintf(fp, "%.4lf\n", devt[savecode[i][j]]);
				}
			}
		}
	}
	for(int i = 250; i < 6010; i++)
	{
		if(savecode[i/10][i%10])
		{
			fprintf(fp, "\n(%d) v = %d.%d%d mL/min\n", savecode[i/10][i%10], i/1000, (i/100)%10, (i/10)%10);
			if(i < 500)
			{
				;
			}
			else
			{
				fprintf(fp, "NaNO2 0.0%d g\n", HNO2[savecode[i/10][i%10]]);
			}
			fprintf(fp, "maxAbs = %d.%d%d%d%d%d\n", maxAbs[i/10][i%10]/100000, (maxAbs[i/10][i%10]/10000)%10, (maxAbs[i/10][i%10]/1000)%10, (maxAbs[i/10][i%10]/100)%10, (maxAbs[i/10][i%10]/10)%10, maxAbs[i/10][i%10]%10);
			fprintf(fp, "s = %d.%d%d%d%d%d\n", maxAbsuncertainty[i/10][i%10]/100000, (maxAbsuncertainty[i/10][i%10]/10000)%10, (maxAbsuncertainty[i/10][i%10]/1000)%10, (maxAbsuncertainty[i/10][i%10]/100)%10, (maxAbsuncertainty[i/10][i%10]/10)%10, maxAbsuncertainty[i/10][i%10]%10);
			for(int j = 0; j < 60000/(i/10); j++)
			{
				fprintf(fp, "%d %d.%d%d%d%d%d\n", j+1, Abs[j][i/10][i%10]/100000, (Abs[j][i/10][i%10]/10000)%10, (Abs[j][i/10][i%10]/1000)%10, (Abs[j][i/10][i%10]/100)%10, (Abs[j][i/10][i%10]/10)%10, Abs[j][i/10][i%10]%10);
			}
		}
	}
	fprintf(fp, "\nend\n");
	printf("The results are saved in D:\\Abs-t_result.txt .\n");
}

int main()
{
	srand(time(NULL));
	principles();
	build();
	while(startandend)
	{
		cout << endl << endl << endl << endl << "III. Preparation of the Solutions" << endl;
		phenol();
		Sodium_hydroxide();
		changevolume();
		hydrochloride();
		aniline();
		cout << "IV. Start the Pump to Conduct Experiments" << endl;
		cout << "Before each experiment, 76 mg of sodium nitrite is required to be weighed." << endl;
		cout << "First, at least three groups at low pump rate (0.25-0.50 mL/min) are required to be tested." << endl;
		cout << "We can consider them as reaction of infinite residence time approximately, and take the absorbance at steady state as when aniline has reacted completely." << endl;
		cout << "As you finished the step, you can key in 0 to test normal residence time conditions." << endl;
		cout << "The pump rate should be set between 0.50 and 6.00 mL/min, accurate to two decimal places or less." << endl;
		cout << "It is advised that you can take three tests at the same pump rate." << endl;
		cout << "You can finish the whole experiment process after you achieved at least five groups of data from tests of different pump rates." << endl;
		cout << "After choosing an appropriate pump rate, the test will begin. For the same pump rate, you can save up to ten groups of data." << endl;
		cout << "Also, if you finished the step, just key in 0 to finish." << endl;
		cout << "During this part, 0.1% HCl will be consumed fast." << endl;
		cout << "If it has been used up, you have to prepare it again." << endl;
		cout << "If aniline and phenol solutions are used up before you achieved all the data, you have to restart from preparing the solutions." << endl;
		pause();
		printf("\n\n\n\n\n");
		while(restreagent > 0)
		{
			srand(time(NULL));
			while(maxAbsset)
			{
				cout << "Set the pump rate (0.25-0.50, unit:mL/min): ";
				vin = speedinput();
				if(vin == 0)
				{
					if(groupsAmax > 2)
					{
						maxAbsset = 0;
						int confirmAbsmax = 1;
						while(confirmAbsmax)
						{
							analyseAbsmax();
							cout << "Key in OK to continue, or discard current data and restart: ";
							string input;
							cin >> input;
							if(input == "OK")
							{
								confirmAbsmax = 0;
							}
						}
					}
					else
					{
						cout << "You cannot continue until you have tested three times." << endl;
					}
				}
				else if(vin < 25)
				{
					cout << "invalid input" << endl;
				}
				else if(vin > 50)
				{
					cout << "invalid input" << endl;
				}
				else
				{
					printf("\n\n");
					sodiumnitrite();
					cout << "Filling the syringes with the solutions..." << endl;
					pause();
					printf("\n\n");
					calculate(vin);
					displayAbsmax(vin);
					restreagent--;
				}
			}
			cout << "Set the pump rate (0.50-6.00, unit:mL/min): ";
			vin = speedinput();
			if(vin == 0)
			{
				if(testcheck())
				{
					output();
					cout << "You have completed the experiment. Your data is recorded in D:\\Abs-t.txt ." << endl;
					pause();
					startandend = 0;
					restreagent = -1;
				}
				else
				{
					cout << "You cannot finish until you have saved at least five groups of data from tests of different pump rates." << endl;
				}
			}
			else if(vin < 50)
			{
				cout << "invalid input" << endl;
			}
			else if(vin > 600)
			{
				cout << "invalid input" << endl;
			}
			else
			{
				printf("\n\n");
				sodiumnitrite();
				cout << "Filling the syringes with the solutions..." << endl;
				pause();
				printf("\n\n");
				calculate(vin);
				displayAbs(vin);
				restreagent--;
			}
		}
		if(restreagent == 0)
		{
			cout << "The solutions have been used up." << endl;
			if(testcheck())
			{
				output();
				cout << "You have completed the experiment. Your data is recorded in D:\\Abs-t.txt ." << endl;
				pause();
				startandend = 0;
			}
			else
			{
				cout << "Restart the experiment." << endl;
				pause();
			}
		}
	}
	printf("\n\n\n\n\n");
	cout << "V. Analysing the Data" << endl;
	int result = 1;
	while(result)
	{
		if(analyse())
		{
			result = 0;
			outputresult();
		}
	}
	pause();
	return 0;
}
