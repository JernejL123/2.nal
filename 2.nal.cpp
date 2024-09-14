#include <iostream>
#include <stack>

using namespace std;

stack<int> stolp_1;
stack<int> stolp_2;
stack<int> stolp_3;

void zacetno_stanje(int st_ploscic) {
    while (st_ploscic > 0) {
        stolp_1.push(st_ploscic);
        st_ploscic--;
    }
}

void izprazni_stolpce() {
    while (!stolp_1.empty()) stolp_1.pop();
    while (!stolp_2.empty()) stolp_2.pop();
    while (!stolp_3.empty()) stolp_3.pop();
}

void izris_stolpa(stack<int> &stolp) {
    stack<int> temp = stolp;
    while (!temp.empty()) {
        int st_zvezdic = temp.top();
        for (int i = 0; i < st_zvezdic; ++i) {
            cout << "*";
        }
        temp.pop();
        cout << endl;
    }
    cout << endl;
}

bool je_prazen(stack<int> &stolp) {
    return stolp.empty();
}

int main() {
    while (true) {
        cout << endl;
        cout << "1. Nastavi zacetno stanje igre" << endl;
        cout << "2. Prestavi zgornji element iz stolpa Y na stolp Z" << endl;
        cout << "3. Izpisi vse stolpe" << endl;
        cout << "4. Konec" << endl;

        int izbira;
        cout << "vnesite steviko menija: " << endl;
        cin >> izbira;

        if (izbira == 1) {
            int velikost;
            cout << "Vnesite velikost stolpa: " << endl;
            cin >> velikost;
            izprazni_stolpce();
            zacetno_stanje(velikost);

        } else if (izbira == 2) {
            stack<int> *vsi_stolpi[3] = {&stolp_1, &stolp_2, &stolp_3};
            int Y, Z;
            cout << endl;
            cout << "izberite stolp iz katerega hocete izbrat vrednost: ";
            cin >> Y;
            cout << "izberite stolp na katerega hocete dodati izbrano vrednost: ";
            cin >> Z;
            if (je_prazen(*vsi_stolpi[Y - 1])) {
                cout << "NAPAKA" << endl;
            } else if (!je_prazen(*vsi_stolpi[Z - 1]) && vsi_stolpi[Z - 1]->top() < vsi_stolpi[Y - 1]->top()) {
                cout << "NAPACNA POTEZA" << endl;
            } else {
                vsi_stolpi[Z - 1]->push(vsi_stolpi[Y - 1]->top());
                vsi_stolpi[Y - 1]->pop();
            }
        } else if (izbira == 3) {
            cout << endl;
            cout << "Stolp 1:" << endl;
            izris_stolpa(stolp_1);
            cout << "Stolp 2:" << endl;
            izris_stolpa(stolp_2);
            cout << "Stolp 3:" << endl;
            izris_stolpa(stolp_3);

            if ((stolp_1.empty() && stolp_2.empty()) || (stolp_1.empty() && stolp_3.empty())) {
                cout << "BRAVO ZMAGAL SI" << endl;
            }

        } else if (izbira == 4) {
            break;
        }
    }
    return 0;
}
