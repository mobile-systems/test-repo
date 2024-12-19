#include <vector>
#include <functional>
#include <iostream>

#include "candle.h"

//массив всех тестов, который мы заполняем в функции initTests
static std::vector<std::function<bool()>> tests;

// 2.1. написать 3 теста для метода 'body_contains'
// Тест 1. Тело зелёной свечи включает значение?
bool test_body_contains1()
{
  // Формируем тестовую зелёную свечу (СМЗ, таймфрейм 1D, 15-02-2022, признаки Pump&Dump)
  Candle candle{ 9450.00, 13220.00, 9300.00, 13220.00 }; // OHLC
  
  return candle.body_contains(9450.00); //passed
}

// Тест 2. Тело красной свечи включает значение?
bool test_body_contains2()
{
  // Формируем тестовую красную свечу (Транснефть, таймфрейм 1W, 18-11-2024, новость об увеличении налога на эмитента)
  Candle candle{ 1277.00, 1278.50, 1024.00, 1072.00 }; // OHLC
  
  return candle.body_contains(1072.00); //passed
}

// Тест 3. Тело доджа включает значение (проверка свечи с одинаковыми значениями открытия и закрытия)?
bool test_body_contains3()
{
  // Формируем тестовую свечу додж (АЛРОСА, таймфрейм 1D, 17-11-2024)
  Candle candle{ 66.66, 66.99, 66.66, 65.67 }; // OHLC
  
  return candle.body_contains(66.66); //passed
}
// 2.2. написать 3 теста для метода 'contains'
// Тест 4. Зелёная свеча включает значение?
bool test_contains1()
{
  // Формируем тестовую зелёную свечу (СМЗ, таймфрейм 1D, 15-02-2022, признаки Pump&Dump)
  Candle candle{ 9450.00, 13220.00, 9300.00, 13220.00 }; // OHLC
  
  return candle.contains(9450.00); //passed
}

// Тест 5. Красная свеча включает значение?
bool test_contains2()
{
  // Формируем тестовую красную свечу (Транснефть, таймфрейм 1W, 18-11-2024, новость об увеличении налога на эмитента)
  Candle candle{ 1277.00, 1278.50, 1024.00, 1072.00 }; // OHLC
  
  return candle.contains(1072.00); //passed
}

// Тест 6. Додж включает значение (проверка свечи с одинаковыми значениями открытия и закрытия)?
bool test_contains3()
{
  // Формируем тестовую свечу додж (АЛРОСА, таймфрейм 1D, 17-11-2024)
  Candle candle{ 66.66, 66.99, 66.66, 65.67 }; // OHLC
  
  return candle.contains(66.66); //passed
}

// 2.3. написать 3 теста для метода 'full_size'
// Тест 7. Размер зелёной свечи в диапазоне?
bool test_full_size1()
{
  // Формируем тестовую зелёную свечу (СМЗ, таймфрейм 1D, 15-02-2022, признаки Pump&Dump)
  Candle candle{ 9450.00, 13220.00, 9300.00, 13220.00 }; // OHLC
  
  return candle.full_size() >= Price(0) && candle.full_size() < Price(4000); //passed
}

// Тест 8. Размер красной свечи в диапазоне?
bool test_full_size2()
{
  // Формируем тестовую красную свечу (Транснефть, таймфрейм 1W, 18-11-2024, новость об увеличении налога на эмитента)
  Candle candle{ 1277.00, 1278.50, 1024.00, 1072.00 }; // OHLC
  
  return candle.full_size() >= Price(0) && candle.full_size() < Price(300); //passed
}

// Тест 9. Додж в диапазоне (проверка свечи с одинаковыми значениями открытия и закрытия)?
bool test_full_size3()
{
  // Формируем тестовую свечу додж (АЛРОСА, таймфрейм 1D, 17-11-2024)
  Candle candle{ 66.66, 66.99, 66.66, 65.67 }; // OHLC
  
  return candle.full_size() >= Price(0) && candle.full_size() < Price(1); //passed
}

// 2.4. написать 3 теста для метода 'body_size'
// Тест 10. Размер зелёной свечи в диапазоне?
bool test_body_size1()
{
  // Формируем тестовую зелёную свечу (СМЗ, таймфрейм 1D, 15-02-2022, признаки Pump&Dump)
  Candle candle{ 9450.00, 13220.00, 9300.00, 13220.00 }; // OHLC
  
  return candle.body_size() >= Price(0) && candle.body_size() < Price(4000); //passed
}

// Тест 11. Размер красной свечи в диапазоне?
bool test_body_size2()
{
  // Формируем тестовую красную свечу (Транснефть, таймфрейм 1W, 18-11-2024, новость об увеличении налога на эмитента)
  Candle candle{ 1277.00, 1278.50, 1024.00, 1072.00 }; // OHLC
  
  return candle.body_size() >= Price(0) && candle.body_size() < Price(300); //passed
}

// Тест 12. Додж в диапазоне (проверка свечи с одинаковыми значениями открытия и закрытия)?
bool test_body_size3()
{
  // Формируем тестовую свечу додж (АЛРОСА, таймфрейм 1D, 17-11-2024)
  Candle candle{ 66.66, 66.99, 66.66, 65.67 }; // OHLC
  
  return candle.body_size() >= Price(0) && candle.body_size() < Price(1); //passed
}

void initTests()
{
  // 2.1. тесты для метода 'body_contains' (на вхождение значения цены в тело свечи)
  tests.push_back(test_body_contains1);
  tests.push_back(test_body_contains2);
  tests.push_back(test_body_contains3);
  // 2.2. тесты для метода 'contains' (на вхождение значения цены в свечу)
  tests.push_back(test_contains1);
  tests.push_back(test_contains2);
  tests.push_back(test_contains3);
  // 2.3 тесты для метода 'full_size' (на размер свечи в диапазоне)
  tests.push_back(test_full_size1);
  tests.push_back(test_full_size2);
  tests.push_back(test_full_size3);
  // 2.4 тесты для метода 'body_size' (на размер тела свечи в диапазоне)
  tests.push_back(test_body_size1);
  tests.push_back(test_body_size2);
  tests.push_back(test_body_size3);
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
