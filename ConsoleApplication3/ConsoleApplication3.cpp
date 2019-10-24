// ConsoleApplication3.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <omp.h>
#include <iomanip>     


uint32_t fibonacci(uint32_t n) {

	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return fibonacci(n - 2) + fibonacci(n - 1);

}

int main()
{
	using namespace std;

	const int N = 40;
	uint32_t fib[N] = {};
	int watek[N] = {};

	auto czas_startu = omp_get_wtime();

# pragma omp parallel for num_threads(4)

	for (int i = 0; i < N; ++i) {

		fib[i] = fibonacci(i);
		watek[i] = omp_get_thread_num();

	}

	auto czas_konca = omp_get_wtime();


	cout << setw(4) << "L.p." << setw(10) << "Element" << setw(6) << "Watek\n";


	for (int i = 0; i < N; ++i)
	{
		cout << setw(4) << (i + 1) << setw(10) << fib[i] << setw(6) << watek[i] << "\n";

	}

	cout << "\nCzas:" << (czas_konca - czas_startu) << "sek.";



	//cin.get(); //system ("pause")
	return EXIT_SUCCESS;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
