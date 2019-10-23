/**
 * Notka od autora: podejscie autorskie, polegajace na tym, ze liczbe "silniowana"
 * reprezentuje jako tablice "segmentow", tj. kazdy segment to 16 kolejnych cyfr liczby
 * "silniowanej". Mnoze kazdy z tych segmentow przez kolejne liczby do n i po kazdym
 * mnozeniu danego segmentu cyfry niemieszczace sie w tym segmencie dodaje do kolejnego
 * 
 * A w sumie segment to taka cyfra, tyle ze 16 xD
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
uint64_t segmenty[N_SEGMENTOW];

//koniec oznacza indeks najwyzszego segmentu zawierajacego jakies cyfry
int koniec = 0;
int n;

int main() {
    cin >> n;
    segmenty[0] = 1;

    for (int i = 1; i < N_SEGMENTOW; i++) {
        segmenty[i] = 0;
    }

    for (int i = 2; i <= n; i++) {
        uint64_t dodatek_seg_wyzej = 0; //analogicznie jak w mnozeniu pisemnym

        for (int j = 0; j <= koniec; j++) {
            if (segmenty[j] > 0 || dodatek_seg_wyzej > 0) {
                uint64_t pomnozony_segment = segmenty[j] * i + dodatek_seg_wyzej;
                uint64_t nowy_segment = pomnozony_segment % DZIELNIK;
                dodatek_seg_wyzej = pomnozony_segment / DZIELNIK;
                segmenty[j] = nowy_segment;

                if (dodatek_seg_wyzej > 0 && j == koniec) {
                    koniec++;
                }
            }
        }
    }

    cout << segmenty[koniec];
    
    cout << setfill('0');
    for (int i = koniec - 1; i >= 0; i--) {
        cout << setw(16) << segmenty[i];
    }
}