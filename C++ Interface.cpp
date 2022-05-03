#include <iostream>
using namespace std;

class materials
{
protected:
    //Varible declaration for the volume fractions of all metal components
    //v1 corresponds to the volume fraction of component 1, v2 the volume fraction of compenent 2, and so on
    double v1, v2, v3, v4;

    //Varible declaration for the densities of all metal components
    //d1 corresponds to the density of component 1, v2 the density of compenent 2, and so on
    double d1, d2, d3, d4;

public:
    virtual void getVolumeFraction() = 0;

    virtual void getDensity() = 0;

    virtual double computeDensity() = 0;
};

class metal : public materials
{
public:
    metal()
    {
        //constructor
    }

    void getVolumeFraction()
    {
        //Get volume fractions of each component by user input
        cout << "Enter Volume Frcation of Component 1: ";
        cin >> v1;
        cout << "\n";
        cout << "Enter Volume Frcation of Component 2: ";
        cin >> v2;
        cout << "\n";
        cout << "Enter Volume Frcation of Component 3: ";
        cin >> v3;
        cout << "\n";
        cout << "Enter Volume Frcation of Component 4: ";
        cin >> v4;
        cout << "\n";
    }

    void getDensity()
    {
        //Get volume fractions of each component by user input
        cout << "Enter Density of Component 1: ";
        cin >> d1;
        cout << "\n";
        cout << "Enter Density of Component 2: ";
        cin >> d2;
        cout << "\n";
        cout << "Enter Density of Component 3: ";
        cin >> d3;
        cout << "\n";
        cout << "Enter Density of Component 4: ";
        cin >> d4;
        cout << "\n";
    }

    double computeDensity()
    {
        //Variable declaration for the metal density
        double D;

        //Metal density calculation
        //Summation of the product of individual volume fractions with the corresponding densities gives the material density
        D = (v1 * d1) + (v2 * d2) + (v3 * d3) + (v4 * d4);

        return D;
    }
};

class porousCeramics : public materials
{
protected:
    double v5; //volume of pores
public:
    void getVolumeFraction()
    {
        //Get volume fractions of each component by user input
        cout << "Enter Volume Frcation of Component 1: ";
        cin >> v1;
        cout << "\n";
        cout << "Enter Volume Frcation of Component 2: ";
        cin >> v2;
        cout << "\n";
        cout << "Enter Volume Frcation of Component 3: ";
        cin >> v3;
        cout << "\n";
        cout << "Enter Volume Frcation of Component 4: ";
        cin >> v4;
        cout << "\n";
        cout << "Enter Volume Frcation of Pores: ";
        cin >> v5;
        cout << "\n";
    }

    void getDensity()
    {
        //Varible declaration for the densities of all porous ceramic components
        //d1 corresponds to the density of component 1, v2 the density of compenent 2, and so on
        double d1, d2, d3, d4;

        //Get volume fractions of each component by user input
        cout << "Enter Density of Component 1: ";
        cin >> d1;
        cout << "\n";
        cout << "Enter Density of Component 2: ";
        cin >> d2;
        cout << "\n";
        cout << "Enter Density of Component 3: ";
        cin >> d3;
        cout << "\n";
        cout << "Enter Density of Component 4: ";
        cin >> d4;
        cout << "\n";
    }

    double computeDensity()
    {
        //Porous ceramic density calculation
        //Summation of the product of individual volume fractions with the corresponding densities gives the material density
        //Density of air is 1.225 kg/m^3
        //Desnity of air or pores is to be subtracted to get the material density
        double D = (v1 * d1) + (v2 * d2) + (v3 * d3) + (v4 * d4) - (v5 * 1.225);

        return D;
    }
};

class polymerMatrix : public materials
{
public:
    void getVolumeFraction()
    {
        //Varible declaration for the volume fractions of all polymer matrix components
        //v1 corresponds to the volume fraction of component 1, v2 the volume fraction of compenent 2, and so on
        double v1, v2, v3, v4;

        //Get volume fractions of each component by user input
        cout << "Enter Volume Frcation of Component 1: ";
        cin >> v1;
        cout << "\n";
        cout << "Enter Volume Frcation of Component 2: ";
        cin >> v2;
        cout << "\n";
        cout << "Enter Volume Frcation of Component 3: ";
        cin >> v3;
        cout << "\n";
        cout << "Enter Volume Frcation of Component 4: ";
        cin >> v4;
        cout << "\n";
    }

    void getDensity()
    {
        //Varible declaration for the densities of all polymer matrix components
        //d1 corresponds to the density of component 1, v2 the density of compenent 2, and so on
        double d1, d2, d3, d4;

        //Get density of each component by user input
        cout << "Enter Density of Component 1: ";
        cin >> d1;
        cout << "\n";
        cout << "Enter Density of Component 2: ";
        cin >> d2;
        cout << "\n";
        cout << "Enter Density of Component 3: ";
        cin >> d3;
        cout << "\n";
        cout << "Enter Density of Component 4: ";
        cin >> d4;
        cout << "\n";
    }

    double computeDensity()
    {
        //Variable declaration for the polymer matrix density
        double D;

        //Polymer matrix density calculation
        //Summation of the product of individual volume fractions with the corresponding densities gives the material density
        D = (v1 * d1) + (v2 * d2) + (v3 * d3) + (v4 * d4);

        return D;
    }
};

class Controller
{
public:
    static void solve()
    {
        while (1)
        {
            //Develope a switch case interface to calculate densities of three types of material
            cout << "Welcome to the material density calculation interface \n";
            cout << "Press 1 to calculate density of metal \n";
            cout << "Press 2 to calculate density of porous ceramic \n";
            cout << "Press 3 to calculate density of polymer matrix composite \n";
            cout << "Press 4 to exit \n";

            int n;
            cout << "Enter the type of material :";
            cin >> n;
            cout << "\n";

            metal obj1;
            porousCeramics obj2;
            polymerMatrix obj3;
            switch (n)
            {
            case 1:
            {
                obj1.getVolumeFraction();
                obj1.getDensity();
                cout << "Net Density of metal object :- " << obj1.computeDensity();
                break;
            }
            case 2:
            {
                obj2.getVolumeFraction();
                obj2.getDensity();
                cout << "Net Density of porous ceramic object :- " << obj2.computeDensity();
                break;
            }
            case 3:
            {
                obj3.getVolumeFraction();
                obj3.getDensity();
                cout << "Net Density of polymer matrix composite object :- " << obj3.computeDensity();
                break;
            }
            default:
                exit(0);
            }
            cout << "\n";
        }
    }
};

int main()
{
    Controller::solve();
    return 0;
}
