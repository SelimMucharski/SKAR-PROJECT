# SKAR PROJECT

Projekt stworzony przez Selima Mucharskiego na potrzeby rekrutacji do koła naukowego SKAR.

Projekt zawiera opis rozwiązania dotyczącego ważenia próbki pobranej przez wiertło.

Rozwiązanie polega na najpierw zważeniu samego wiertła, po czym odjęciu jego od wagi wiertła z próbką. Do odczytu służyć będą belki tensometryczne (3-4 w zależności od faktycznych potrzeb w kwestii łazika). Sygnał z belki, przepuszczony przez wzmacniacz, dostarczany jest do microkontrolera (w moim projekcie użyłem Arduino Micro). Następnie odczyt może zostać przesłany poprzez moduł CAN. Program pozwala również na dostarczenie do microkontrolera różnych komend, również poprzez moduł CAN.

Belka tensometryczna: 5kg każda

# Opis kodu

Kod podzielony jest na 3 główne klasy: Loadcell, Sensor i Can.

Kalsa Loadcell reprezentuje pojedyńczą belkę tensometryczną. Możliwe jest ustawienie jej offestu oraz skali. Pozwala różenież na odczyt.

Klasa Sensor posiada jako jedno z pól tablicę zawierającą kilka obiektów klasy Loadcell. Przy pomocy funkcji get_sum() można odczytać sumę odczytów z jej loadcelli przeskalowanych przez określoną amplitudę.

Klasa Can pozwala na używanie modułu CAN. Dzięki niej można w prosty sposób wysyłać informacje z microkontrolera do magistrali oraz odbierać z niej dane.
