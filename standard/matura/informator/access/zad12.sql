SELECT samochody.marka, samochody.model
FROM samochody
WHERE samochody.rocznik BETWEEN 2010 AND 2020 AND samochody.moc > 100
GROUP BY samochody.marka, samochody.model

-- //////////////////////////////////////////////////////////////////////

SELECT klienci.imie, klienci.nazwisko, Count(samochody.id) AS ile
FROM klienci LEFT JOIN samochody ON klienci.Id = samochody.wlasciciel
GROUP BY klienci.imie, klienci.nazwisko
ORDER BY Count(samochody.id) DESC;