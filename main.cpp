#include <vector>
#include <functional>
#include <iostream>

#include "candle.h"

//массив всех тестов, который мы заполняем в функции initTests
static std::vector<std::function<bool()>> tests;

//Тест 1. Тело зелёной свечи включает значение?
bool test_body_contains1()
{
  // Формируем тестовую зелёную свечу (СМЗ, таймфрейм 1D, 15-02-2022, признаки Pump&Dump)
  Candle candle{ 9450.00, 13220.00, 9300.00, 13220.00 }; // OHLC
  
  return candle.body_contains(9450.00); //passed
}

//Тест 2. Тело красной свечи включает значение?
bool test_body_contains2()
{
  // Формируем тестовую красную свечу (Транснефть, таймфрейм 1W, 18-11-2024, новость об увеличении налога на эмитента)
  Candle candle{ 1277.00, 1278.50, 1024.00, 1072.00 }; // OHLC
  
  return candle.body_contains(1072.00); //passed
}

//тест 3. Тело доджа включает значение (проверка свечи с одинаковыми значениями открытия и закрытия)?
bool test_body_contains3()
{
  // Формируем тестовую свечу додж (АЛРОСА, таймфрейм 1D, 17-11-2024)
  Candle candle{ 66.66, 66.99, 66.66, 65.67 }; // OHLC
  
  return candle.body_contains(66.66); //passed
}

void initTests()
{
  // Тесты вхождения значения цены в тело свечи
  tests.push_back(test_body_contains1);
  tests.push_back(test_body_contains2);
  tests.push_back(test_body_contains3);
}

int launchTests()
{
  int total = 0;
  int passed = 0;

  for (const auto& test : tests)
  {
    std::cout << "test #" << (total + 1);
    if (test())
    {
      passed += 1;
      std::cout << " passed\n";
    }
    else
    {
      std::cout << " failed\n";
    }
    total += 1;
  }

  std::cout << "\ntests " << passed << "/" << total << " passed!" << std::endl;

  //0 = success
  return total - passed;
}

int main()
{
  initTests();
  return launchTests();
}
