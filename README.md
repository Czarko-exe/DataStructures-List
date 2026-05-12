# Struktury Danych - Miniprojekt 1: Lista (DataStructures-List)

Projekt zrealizowany w ramach przedmiotu **Struktury Danych**. Celem zadania była samodzielna implementacja podstawowych struktur danych w języku C++ oraz przeprowadzenie empirycznych badań czasu wykonywania poszczególnych operacji. 

Projekt został zrealizowany w parach.

## 🛠 Zaimplementowane struktury danych

Zgodnie z wymogami projektu na ocenę 5.0, wdrożyliśmy następujące struktury:
1. **Tablica dynamiczna (Dynamic Array)** - z początkowo zadanym rozmiarem, powiększająca się dwukrotnie w przypadku braku miejsca.
2. **Lista jednokierunkowa (Singly Linked List)** - oparta na wskaźnikach `head` oraz `tail`.
3. **Lista dwukierunkowa (Doubly Linked List)**.

## ⚙️ Badane operacje

Dla każdej z powyższych struktur przygotowaliśmy testy badające czas wykonywania następujących operacji:
* **Dodawanie i usuwanie elementów:**
  * Na początku struktury
  * Na końcu struktury
  * W losowym miejscu struktury
* **Wyszukiwanie:** Szukanie wylosowanej wartości w obrębie struktury.

## 🚀 Jak uruchomić projekt

Projekt został utworzony w środowisku Visual Studio.

1. Sklonuj repozytorium:
   ```bash
   git clone [https://github.com/TwojaNazwaUzytkownika/DataStructures-List.git](https://github.com/TwojaNazwaUzytkownika/DataStructures-List.git)
2. Otwórz plik rozwiązania `DataStructures-List.slnx` w programie Visual Studio.
3. Skompiluj projekt (zaleceane użycie trybu `Release` dla dokładniejszych wyników badań wydajnościowych).
4. Uruchom aplikację. Obsługa programów testujących odbywa się za pomocą interaktywnego menu w konsoli.

## 📊 Wyniki badań (Sprawozdanie)

Przeprowadzone badania empiryczne (dla zestawów danych od 1000 do 128 000 elementów) pozwoliły na wyciągnięcie następujących wniosków z działania poszczególnych struktur:

* **Tablica dynamiczna (Dynamic Array):** Dzięki zachowaniu ciągłości zajmowanej pamięci, struktura ta pozwala na indeksowanie i łatwiejszy, bezpośredni dostęp do konkretnych pozycji. Przekłada się to na nieznacznie lepsze czasy przy wyszukiwaniu (operacja `find`) czy działaniach wewnątrz struktury w porównaniu do list, mimo tej samej złożoności teoretycznej $O(n)$. Operacje na początku struktury są jednak kosztowne czasowo ($O(n)$), ponieważ wymagają przesunięcia wszystkich elementów.
* **Listy wiązane (Singly & Doubly Linked List):** Posiadają wysoce zoptymalizowane, stałoczasowe operacje $O(1)$ na skrajach struktury (wstawianie i usuwanie na początku oraz dodawanie na końcu). Dostęp do elementów wewnątrz listy jest jednak ograniczony koniecznością liniowego przejścia przez poprzedzające je węzły ($O(n)$).
* **Zarządzanie pamięcią:** Użycie wskaźników w listach pozwala na modyfikowanie struktury bez konieczności kosztownego przesuwania całych bloków pamięci (jak ma to miejsce w tablicy dynamicznej). Wiąże się to jednak z dodatkowym obciążeniem i większym zużyciem pamięci na same wskaźniki.
* [cite_start]**Doubly vs Singly Linked List:** Lista dwukierunkowa, pomimo wykorzystania większej ilości zasobów na dodatkowe wskaźniki `prev`, deklasuje listę jednokierunkową m.in. przy operacji `popBack` (usuwanie z końca). W liście jednokierunkowej usunięcie ostatniego elementu wymaga iteracji niemal całej listy ($O(n)$) , podczas gdy lista dwukierunkowa robi to w czasie stałym $O(1)$ Dodatkowo ułatwia dostęp do elementów wewnątrz dzięki możliwości nawigacji z obu stron.

## 👨‍💻 Autorzy
[github.com/Czarko-exe](github.com/Czarko-exe)  
[github.com/R0-0F](github.com/R0-0F)
