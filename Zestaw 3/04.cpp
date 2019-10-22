/**
 * Notka od autora: podejscie autorskie, polegajace na tym, ze liczbe "silniowana"
 * reprezentuje jako tablice "segmentow", tj. kazdy segment to 16 kolejnych cyfr liczby
 * "silniowanej". Mnoze kazdy z tych segmentow przez kolejne liczby do n i po kazdym
 * mnozeniu danego segmentu cyfry niemieszczace sie w tym segmencie dodaje do kolejnego
 */
#include <iostream>
#include <iomanip>

using namespace std;
/**
 * w kazdym segmencie trzymamy kolejne 16 cyfr liczby
 * trzymamy akurat tyle, bo w kazdym segmencie liczbe w nim
 * pomnozona przez n (maksymalnie 1000) musimy zmiescic w tym typie
 * u nas ten typ to uint64_t, wiec jest to 10^floor(log10((2^64 - 1)/1000))
 */
const uint64_t DZIELNIK = 10'000'000'000'000'000;
/**
 * 1000 silnia ma 2568 cyfr, a w kazdym segmencie trzymamy 16 cyfr
 * wiec segmentow bedzie ceil(2568/16) = 161 
 */
const int N_SEGMENTOW = 161;
uint64_t segmenty[N_SEGMENTOW] = {0};

int n;

int main() {
    cin >> n;
    //zaczynamy silnie od 1ki oczywiscie
    segmenty[0] = 1;

    //dla kazdego i = 2 .. n
    for (int i = 2; i <= n; i++) {
        //przemnazamy kazdy segment przez i poczynajac od najwiekszych segmentow, czyli od konca
        for (int j = N_SEGMENTOW - 1; j >= 0; j--) {
            //jak ten segment wynosi 0 to go pomijamy
            if (segmenty[j] == 0) {
                continue;
            }
            uint64_t pomnozony_segment = segmenty[j] * i;
            uint64_t nowy_segment = pomnozony_segment % DZIELNIK;
            uint64_t dodatek_seg_wyzej = pomnozony_segment / DZIELNIK;
            segmenty[j] = nowy_segment;

            //jesli segment*n nie miesci sie w 16 cyfrach, to cyfry nadmiarowe przenosimy do segmentu wyzej
            //takie zdarzenie moze oczywiscie zajsc kaskadowo, wiec petla
            int k = j + 1;
            while (dodatek_seg_wyzej > 0) {
                pomnozony_segment = segmenty[k] + dodatek_seg_wyzej;
                nowy_segment = pomnozony_segment % DZIELNIK;
                dodatek_seg_wyzej = pomnozony_segment / DZIELNIK;

                segmenty[k] = nowy_segment;
                k++;
            }
        }
    }

    //szukamy miejsca, od ktorego bedziemy wypisywac zawartosc
    int poczatek_silni;
    for (int i = N_SEGMENTOW - 1; i >= 0; i--) {
        if (segmenty[i] != 0) {
            poczatek_silni = i;
            break;
        }
    }

    //wypisujemy pierwszy segment
    cout << segmenty[poczatek_silni];
    
    //i dla kazdego kolejnego bedziemy musieli uzupelnic zera z przodu segmentu
    cout << setfill('0');
    for (int i = poczatek_silni - 1; i >= 0; i--) {
        cout << setw(16) << segmenty[i];
    }
}