#include <iostream>

using namespace std;

class weight
{
    private:
        double L_int, L_gen, w;
        bool aux;
    public:
        weight () {};
        
        void weight_constructor(unsigned int N_gen, float sigma)
        {
            L_int = 300000;
            L_gen = 0;
            w = 0;
            
            do
            {
                L_gen = N_gen/sigma; 
                w = L_int/L_gen;

                if (w > 0.0001 && w < 10000)
                {
                    cout << "The ideal weight is: " << w << endl;
                    break;
                }

                else 
                {
                    cout << "Please try again..." << endl;
                    cout << "You have entereded: " << N_gen << endl;
                    cout << "Your actual weight is: " << w << endl;
                    cout << "Please enter a new number of generated events: " << endl;
                    cin >> N_gen;
                    cout << "Please enter the cross section: " << endl;
                    cin >> sigma;
                }

            } while(w < 0.0001 || w > 10000);
        
        }

        virtual ~ weight() {};
};

int main()
{
    unsigned int GeneratedEvents;
    double SigmaInput;
    
    cout << "Please enter the number of generated events: " << endl;
    cin >> GeneratedEvents;

    cout << "Please enter the cross section in pb: " << endl;
    cin >> SigmaInput;

    weight *obj1 = new weight();
    obj1 -> weight_constructor(GenratedEvents, SigmaInput);

    return 0;
}
