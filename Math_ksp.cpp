#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

using ll = long long;
using ld = long double;

const ld g0 = 9.80665; // ускорение свободного падения
const ld e_num = 2.71828; // число Эйлера

const ld w = 2164; // скорость истечения топлива из сопла двигателя

const ll m0 = 690000; // масса ракеты на 1 стадии с толпливом (gross mass)
const ll mf = 122576; // масса ракеты после 1 стадии

// Характеристическая скорость
void deltaVelocity() {
    const ld dv1 = w * log(ld(m0) / mf); // До Луны


    cout << "Характеристическая скорость от Земли до Луны = " << dv1 << " m/s" << '\n';

    cout << '\n';
}

// Удельный импульс
void Impulse() {
    ld I0 = ld(w) / g0; // Удельный импульс у Земли
    cout << "Удельный импульс ракеты у Земли = " << I0 << " sec" << '\n';

    cout << '\n';
}

// Первая стадия
const ll mp1 = 480000; // масса топлива, сгоревшая за стадию
const ll t1 = 574; // время сгорания топлива за данную стадию
const ll thrust1 = 1200000; // максимальная сила тяги на стадии


const ll v1 = 4500; // характериcтичеcкая скорость, необходимая для выхода на околоземную орбиту Земли

void burnTime() {
    ld power1 = -(v1 / w);
    ld dT1 = (m0 * w * (1 - pow(e_num, power1))) / thrust1;

    cout << "Время горения для 1 стадии ракеты: " << dT1 << " sec" << '\n';
    cout << "Отличие от реального значения: " << t1 - dT1 << " sec" << '\n';

    cout << '\n';

}

void burnAmount() {
    ld power = v1 / w;
    ld p1 = m0 - (m0 / pow(e_num, power));


    cout << "Масса топлива, сгоревшего за 1 стадию: " << p1 << " kg" << '\n';
    cout << "Отличие от реального значения: " << abs(mp1 - p1) << " kg" << '\n';
    cout << '\n';
}

void propellantFlow() {
    ld pf1 = thrust1 / w;

    cout << "Скорость расхода топлива на 1 стадии: " << pf1 << " kg/s" << '\n';
    cout << '\n';
}

int main() {

    cout << fixed << setprecision(2);

    Impulse();
   
    deltaVelocity();

    burnTime();

    burnAmount();

    propellantFlow();
    
    return 0;
}