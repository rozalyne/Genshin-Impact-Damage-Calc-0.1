#include <iostream>
#include <sstream>
#include <string>

using namespace std;

float KonversiPersen(const string& input) {
    float hasil;
    stringstream ss(input);
    if (input.back() == '%') {
        ss >> hasil;
        hasil /= 100.0;
    } else {
        ss >> hasil;
    }
    return hasil;
}

float hitungnormaldamage(int baseatk, float damagebonus, float talentpersen, int levelkarakter, int levelmusuh, float resismusuh) {
	
    float enemyDef = static_cast<float>(levelkarakter + 100) / (levelkarakter+levelmusuh + 200);
    float resistanceMultiplier = 1.0 - resismusuh;
    float damage = baseatk * (1.0 + damagebonus) * talentpersen * enemyDef * resistanceMultiplier;
    return damage;
}

float calculateCritDamage(float normalDamage, float critDamage) {
	
    float damage = normalDamage * (1.0 + critDamage);
    return damage;
}

void garis(){
	cout << "=====================================\n";
}

int main() {
    bool exitProgram = false;

    while (!exitProgram) {
        int baseatk, levelkarakter, levelmusuh;
        string damagebonusInput, talentpersenInput, resismusuhInput, critDamageInput;
		cout << "Selemat Datang Di Genshin Damage Kalkulator\n\n";
		garis();
		cout << "Perhatikan Peringatan dibawah Ini ! \n\n";
		cout << "Masukan Inputan ( % ) dengan angka% contoh(50%)! \n";
		cout << "Hasil Kalkulasi DMG hanya bisa 99% Kemiripan dikarenakan sistem decimal genshin yang tidak bisa diprediksi \n";
		cout << "DAMAGE TIDAK TERMASUK DALAM ELEMENTAL REACTION MAUPUN DEBUFF \n";
		cout << "Masukan Persenan Dalam Konstelasi/Set Artifak/Efek Senjata Pada (Bonus Damage)\n";
		garis();
        cout << "\nMasukan Base ATK Karakter: ";
        cin >> baseatk;
        cout << "Masukan Bonus Damage%(Contoh :60%): ";
        cin >> damagebonusInput;
        cout << "Masukan Talent Skill Damage%: ";
        cin >> talentpersenInput;
        cout << "Masukan Level Karakter: ";
        cin >> levelkarakter;
        cout << "Masukan Level Musuh: ";
        cin >> levelmusuh;
        cout << "Masukan Resistensi Musuh%: ";
        cin >> resismusuhInput;
        cout << "Masukan Crit DMG%: ";
        cin >> critDamageInput;

        float damagebonus = KonversiPersen(damagebonusInput);
        float talentpersen = KonversiPersen(talentpersenInput);
        float resismusuh = KonversiPersen(resismusuhInput);
        float critDamage = KonversiPersen(critDamageInput);

        float normalDamage = hitungnormaldamage(baseatk, damagebonus, talentpersen, levelkarakter, levelmusuh, resismusuh);
        float critDamageResult = calculateCritDamage(normalDamage, critDamage);

        cout << "Normal Damage: " << normalDamage << endl;
        cout << "Crit Damage: " << critDamageResult << endl;

        string pilih;
        cout << "Mau Ngitung Lagi? (y/n): ";
        cin >> pilih;

        if (pilih != "y" && pilih != "Y") {
            cout <<"Terima Kasih! CR:Ricky Erlangga Handoko | 085022023";
            exitProgram = true;
        }else {
        	system("cls");
		}
    }

    return 0;
}
