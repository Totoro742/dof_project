# Opis projektu

Celem projektu było napisanie oprogramowania, dzięki któremu dla danego
pliku o nieskończonej głębi ostrości posiadającego mapę głębokości
będzie można symulować efekt skończonej głębi. Upraszczając użytkownik
może wczytać obraz oraz odpowiadającą mu mapę głębokości, a także dobrać
współczynnik rozmycia obrazu i dokonać korekty obrazu wyjściowego.

# Założenia wstępne przyjęte w realizacji projektu

Program pozwalał na wczytanie dwóch plików, doboru wartości głębi oraz
rozmycia za pomocą suwaków, podgląd oryginalnego obrazu a także
umożliwiał zmianę jasności, kontrastu oraz korektę gamma. Zmiany te
mogły być cofnięte za pomocą przycisku reset. Zmodyfikowany obraz można
zapisać do pliku.

# Analiza projektu

## Specyfikacja danych wejściowych i wyjściowych

Za pomocą przycisków do programu można było wczytać obraz, który będzie
modyfikowany oraz mapę głębi. Zdecydowaliśmy się na wybór formatu JPG,
ponieważ najlepiej nadaję się do zapisywania zdjęć.

## Opis oczekiwanych danych wyjściowych

Oczekiwanym wyjściem był obraz, który został poddany rozmyciu oraz
korekcie gamma a także zmianie kontrastu lub jasności.

## Zdefiniowanie struktur danych

Obraz wejściowy, mapa głębi oraz obrazy wyjściowe były przechowywane
jako obiekty klasy wxImage. Podgląd generowany w programie był
przechowywany jako obiekt klasy wxBitmap. Kolejne rozmycia były
przechowywane w wektorze obiektów wxImage.

## Specyfikacja interfejsu użytkownika

Pierwsze trzy przyciski interfejsu od góry pełnią kolejno funkcję
wczytywania obrazu, wczytywania mapy głębi oraz zapisu do pliku. Poniżej
znajdują pola tekstowe, które umożliwiają wybór pierwszej i ostatniej
bitmapy. Przycisk pod nimi pozwala zastosować zmianę pól tekstowych na
obrazie. Niżej znajdują się dwa suwaki oraz pole wyboru. Pierwszy suwak
odpowiada za dobór głębokości, natomiast drugi za rozmycie. Pole wyboru
pozwala na podgląd oryginalnego obrazu. Ostatni segment interfejsu
pozwala na zmianę jasności, kontrastu oraz korekty gamma. Przycisk reset
przywraca wartości suwaków do domyślnych wartości. Panel na środku
programu wyświetla obraz po modyfikacjach.

## Decyzja o wyborze narzędzi programistycznych

Do zaimplementowania programu opisanego w projekcie została wykorzystana
biblioteka wxWidgets, ponieważ posiada szereg wbudowanych funkcji, które
znacząco ułatwiają zrealizowanie projektu. Do tworzenia interfejsu
graficznego została wykorzystana aplikacja wxFormBuilder, ponieważ
ułatwia stworzenie czytelnego interfejsu. Projekt był realizowany w
środowisku programistycznym Microsoft Visual Studio 2019. Został użyty
domyślny kompilator MS Visual Studio, czyli MSVC (Microsoft C++
compiler). Standard języka to C++14. Korzystaliśmy także z systemu
kontroli wersji w postaci Git'a. Kompilacja odbywała się w systemie Windows 10/11
(64bit). Został stworzony także prosty obrazek oraz mapa głębokości przy
pomocy oprogramowania Blender.

# Podział pracy i analiza czasowa

Większość projektu realizowaliśmy wspólnie. Na początku stworzyliśmy
koncept, który reprezentował jak powinien wyglądać finalny program.
Następnie został stworzony podstawowy interfejs graficzny oraz
podstawowe funkcje pozwalające na prostą symulację głębi ostrości. W
następnym kroku zostały stworzone funkcje odpowiadające za wczytywanie
oraz zapisywanie plików, możliwość wyboru pierwszej i ostatniej bitmapy
oraz podgląd oryginalnego obrazu. W ostatniej fazie tworzenia
oprogramowania została zaimplementowana możliwość zmiany jasności,
kontrastu oraz korekta gamma, a także ochrona przed wprowadzeniem
nieprawidłowych wartości do pól tekstowych pierwszej i ostatniej
bitmapy.

# Opracowanie niezbędnych algorytmów

-   wxImage::Blur() funkcja z biblioteki
    wxWidgets służąca do rozmywania obrazów
    GUIMyFrame::Blur_Frames() korzystając z
    powyższej funkcji tworzy ciąg bitmap o różnym poziomie rozmycia.
    Zapisuje je w std::vector\<wxImage\>blur_map

-   void GUIMyFrame::Blur_IMG() w zależności
    od podanych przez użytkownika wartości Depth (współczynnik
    \"odległości ostrej\") oraz Blur (wspołczynnik rozmycia
    maksymalnego), składa obrazy o różnym poziomie rozmycia z
    std::vector\<wxImage\>blur_maps w jedną
    całość

-   GUIMyFrame::Transform() dokonuje korekty
    kontrastu, jasności lub gamma zależnie od podanych parametrów

-   limit() pilnuje żeby wartości nie
    wychodziły poza zakres unsigned char'a

    $$limit(x) = \left\{\begin{array}{rcl}
            \label{lmit}
                &0 &dla\quad x<0\\
                &255 &dla\quad x>255\\
                &x &w\quad przeciwnym\quad wypadku
    \end{array} \right.$$

-   Kontrast - dana wartość $C$ z przedziału $<-255,255>$

    Obliczmy współczynnik poprawy kontrastu:
    $$F = \frac{259\cdot(C+255)}{255\cdot(255-C)}$$ Następnie
    współczynnik ten możemy wykorzystać do korekcji barwy:
    $$\label{contrast}
        \begin{array}.
          R'= limit(F\cdot(R -128)+128)\\ 
          G'= limit(F\cdot(G -128)+128)\\ 
          B'= limit(F\cdot(B -128)+128)
          \end{array}$$

-   Jasność - dana wartość $I$ z przedziału $<-255,255>$

    Korekcja barwy: $$\label{brigtnes}
        \begin{array}.
          R'= limit(R + I)\\ 
          G'= limit(G + I)\\ 
          B'= limit(B + I)
          \end{array}$$

-   Korekcja gamma - dany współczynnik gamma $\gamma$ z przedziału
    $<0,2>$

    Następnie współczynnik ten możemy wykorzystać do korekcji:
    $$\label{gamma}
        \begin{array}.
          R'= 255\cdot{(\frac{R}{255})}^{\gamma}\\ 
          G'= 255\cdot{(\frac{G}{255})}^{\gamma}\\ 
          B'= 255\cdot{(\frac{B}{255})}^{\gamma}
          \end{array}$$

# Kodowanie

## Opis klas

W programie znajdowały się dwie klasy zaimplementowane przez nas oraz
jedna, która była wygenerwowana przez wxFormBuilder:

-   MyApp to klasa która odpowiada za
    inicjalizowanie programu

-   MyFrame to klasa wygenerowana przez
    program wxFormBuilder, znajdują się w niej elementy interfejsu oraz
    sizery odpowiadające za poprawne położenie elementów interfejsu

-   GUIMyFrame to klasa w której znajdują się
    struktury danych oraz metody obsługujące między innymi symulowanie
    głębi ostrości, wczytywanie i zapisywanie obrazów oraz zmianę
    kontrastu, jasności oraz korektę gamma.

## Opis zmiennych

-   std::vector\<wxImage\>blur_maps
    przechowuje bitmapy o różnym stopniu rozmycia

-   wxImage image przechowuje oryginalny obraz
    wczytany do programu

-   wxImage map przechowuje mapę głębi

-   wxImage image_blured przechowuje obraz
    poddany operacji symulowania głębi ostrości

-   wxImage image_transformed przechowuje
    obraz poddany korekcji gamma, zmianie kontrastu i jasności

-   wxImage image_final przechowuje obraz,
    który jest wyświetlany i ostatecznie zapisywany

-   wxBitmap buffer przechowuje bitmapę, która
    jest rysowana na podglądzie

-   char t_flag flaga oznaczająca jakiej
    transformacji ostatnio poddano obraz, ważne do wybrania przez
    program kolejności wykonania korekt

## Opis metod oraz funkcji

-   limit zapewnia że wartości barw nie wyjdą
    poza zakres unsigned char'a

-   Contrast liczy nową wartość barwy,
    wykonując korektę kontrastu

-   Brightness liczy nową wartość barwy,
    wykonując korektę jasności

-   Gamma liczy nową wartość barwy, wykonując
    korektę gamma

-   load_picure metoda wczytująca obraz do
    programu. Jest on przechowywany w zmiennej
    image

-   load_map metoda wczytująca mapę głębi do
    programmu. Jest ona przechowywana w zmiennej
    map

-   repaint metoda rysująca obraz po
    transformacji

-   m_scrolledWindow metoda wywołująca
    repaint po zmianie wielkości okna

-   save_image metoda zapisująca obraz
    wyjściowy do pliku

-   m_s_blur metoda wywołująca
    GUIMyFrame::Blur_IMG()] podczas zmiany
    wartości suwaków Blur lub Depth

-   button_resetOnButtonClick metoda
    wywołująca repaint po zmianie stanu pola
    wyboru

-   button_applyOnButtonClick metoda
    resetująca wartości suwaków jasności, kontrastu oraz korekcji gamma.

-   slider_brightnessOnScroll metoda
    wywoływana, gdy zmienia się wartość suwaka jasności

-   slider_contrastOnScroll metoda wywoływana,
    gdy zmienia się wartość suwaka kontrastu

-   slider_gammaOnScroll metoda wywoływana,
    gdy zmienia się wartość suwaka korekcji gamma

-   prewiev_mode metoda wywoływana, gdy
    zmienia się wartość pola wyboru odpowiadającego za podgląd

# Testowanie

Działanie programu było testowane manualnie, za pomocą przykładowych
obrazów oraz odpowiednich dla nich map ostrości.

# Wdrożenie, raport, wnioski

Udało się spełnić podstawowe oraz w większości rozszerzone wymagania.
Dzięki programowi da się symulować głębie ostrości dla obrazu, który
posiada mapę głębokości. Użytkownik jest w stanie dobrać współczynniki
które pozwalają na zwiększenie lub zmniejszenie rozmycia, a także które
miejsce ma być wyostrzone. Można podejrzeć jak wygląda oryginalny obraz.
Program pozwala także na korekcje gamma, zmianę jasności oraz kontrastu.
Możliwe jest także wybranie pierwszej i ostatniej bitmapy i
wygenerowanie dla nich ciągu bitmap, które zmieniają położenie punktu
ostrości.
W przyszłości należałoby poprawić funkcję rozmywającą obraz, aby lekko
zmniejszyć rozmycie, która powoduje halo effect na krawędziach obrazu.
Należy także poprawić szybkość działania programu, zwłaszcza dla obrazów
o dużej rozdzielczości.
