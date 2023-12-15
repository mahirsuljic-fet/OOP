// Mahir Suljic - OOP Zadaca 2023. - Zadatak 1

#include <iostream>

namespace Temperature
{
  const double CelsiusKelvinCoef = 273.15;
  const double CelsiusFahrenheitMultCoef = 1.8;
  const double CelsiusFahrenheitAddCoef = 32.0;
  const double KelvinFahrenheitMultCoef = 5.0 / 9.0;
  const double KelvinFahrenheitAddCoef = 459.67;
  const double minCelsius = -273.15;
  const double minFahrenheit = -459.67;
  const double minKelvin = 0.0;
}

namespace Speed
{
  const double KilometerMileCoef = 1.60934;
  const double minSpeed = 0.0;
}

namespace Length
{
  const double LightYearKilometerCoef = 9460730472580.8;
  const double FeetMeterCoef = 0.3048;
  const double InchCentimeterCoef = 2.54;
  const double maxDoubleInteger = 1L << __DBL_MANT_DIG__;
  // (1L << __DBL_MANT_DIG__), odnosno 2 na 53 daje najveci cijeli broj koji se moze sa sigurnoscu pohraniti u double
  // u ovom slucaju koristi se da bi se ogranicio i osigurao
  // tacan rezultat pri konverziji svjetlosnih godina u kilometre
  // 1L oznacava da je broj 1 tipa long sto cini left-shift-ovanje sa 53 (__DBL_MANT_DIG__) moguce
  const double maxLyToKm = maxDoubleInteger / LightYearKilometerCoef - 1;
  const double minLength = 0.0;
}

namespace Weight
{
  const double KilogramPountCoef = 2.20462;
  const double minWeight = 0.0;
}

namespace FuelEconomy
{
  const double KmMPGCoef = 235.215;
  const double minFuelEconomy = 0.0;
}

int main()
{
  short choice = 0;
  short subchoice = 0;

  // MAIN MENU
  while (choice < 1 || choice > 5)
  {
    std::cout << "Welcome to Unit converter. Please enter one of the following "
                 "options:\n"
                 "1. Temperature\n"
                 "2. Speed\n"
                 "3. Length\n"
                 "4. Weight\n"
                 "5. Fuel economy\n\nYour choice: ";

    std::cin >> choice;

    switch (choice)
    {
    // TEMPERATURE MENU
    case 1:
    {
      while (subchoice < 1 || subchoice > 6)
      {
        std::cout << "Please choose converter:\n"
                     "1. Celsius to Fahrenheit\n"
                     "2. Fahrenheit to Celsius\n"
                     "3. Celsius to Kelvin\n"
                     "4. Kelvin to Celsius\n"
                     "5. Fahrenheit to Kelvin\n"
                     "6. Kelvin to Fahrenheit\n\nYour choice: ";

        std::cin >> subchoice;

        if (!subchoice)
          std::cout << "Invalid input!\n\n";
      }

      double t = Temperature::minFahrenheit - 1; // manje od bilo kojeg dozvoljenog unosa
      switch (subchoice)
      {
      // Celsius to Fahrenheit
      case 1:
        while (t < Temperature::minCelsius)
        {
          std::cout << "Enter temperature in degrees Celsius: ";
          std::cin >> t;

          if (t < Temperature::minCelsius)
            std::cout << "Invalid input!\n\n";
        }

        std::cout << t << " degrees Celsius is "
                  << t * Temperature::CelsiusFahrenheitMultCoef +
                         Temperature::CelsiusFahrenheitAddCoef
                  << " degrees Fahrenheit.\n";
        break;
      // Fahrenheit to Celsius
      case 2:
        while (t < Temperature::minFahrenheit)
        {
          std::cout << "Enter temperature in degrees Fahrenheit: ";
          std::cin >> t;

          if (t < Temperature::minFahrenheit)
            std::cout << "Invalid input!\n\n";
        }

        std::cout << t << " degrees Fahrenheit is "
                  << (t - Temperature::CelsiusFahrenheitAddCoef) / Temperature::CelsiusFahrenheitMultCoef
                  << " degrees Celsius.\n";
        break;
      // Celsius to Kelvin
      case 3:
        while (t < Temperature::minCelsius)
        {
          std::cout << "Enter temperature in degrees Celsius: ";
          std::cin >> t;

          if (t < Temperature::minCelsius)
            std::cout << "Invalid input!\n\n";
        }

        std::cout << t << " degrees Celsius is "
                  << t + Temperature::CelsiusKelvinCoef
                  << " Kelvin.\n";
        break;
      // Kelvin to Celsius
      case 4:
        while (t < Temperature::minKelvin)
        {
          std::cout << "Enter temperature in Kelvin: ";
          std::cin >> t;

          if (t < Temperature::minKelvin)
            std::cout << "Invalid input!\n\n";
        }

        std::cout << t << " Kelvin is "
                  << t - Temperature::CelsiusKelvinCoef
                  << " degrees Celsius.\n";
        break;
      // Fahrenheit to Kelvin
      case 5:
        while (t < Temperature::minFahrenheit)
        {
          std::cout << "Enter temperature in degrees Farenheit: ";
          std::cin >> t;

          if (t < Temperature::minFahrenheit)
            std::cout << "Invalid input!\n\n";
        }

        std::cout << t << " degrees Farenheit is "
                  << (t + Temperature::KelvinFahrenheitAddCoef) * Temperature::KelvinFahrenheitMultCoef
                  << " Kelvin.\n";
        break;
      // Kelvin to Fahrenheit
      case 6:
        while (t < Temperature::minKelvin)
        {
          std::cout << "Enter temperature in Kelvin: ";
          std::cin >> t;

          if (t < Temperature::minKelvin)
            std::cout << "Invalid input!\n\n";
        }

        std::cout << t << " Kelvin is "
                  << t / Temperature::KelvinFahrenheitMultCoef - Temperature::KelvinFahrenheitAddCoef
                  << " degrees Farenheit.\n";
        break;
      }
      break;
    }
    // SPEED MENU
    case 2:
    {
      while (subchoice < 1 || subchoice > 2)
      {
        std::cout << "Please choose converter:\n"
                     "1. Kilometers per hour to miles per hour\n"
                     "2. Miles per hour to kilometers per hour\n\nYour choice: ";

        std::cin >> subchoice;

        if (!subchoice)
          std::cout << "Invalid input!\n\n";
      }

      double v = -1;
      switch (subchoice)
      {
      // Kilometers per hour to miles per hour
      case 1:
        while (v < Speed::minSpeed)
        {
          std::cout << "Enter speed in kilometers per hour (km/h): ";
          std::cin >> v;

          if (v < Speed::minSpeed)
            std::cout << "Invalid input!\n\n";
        }

        std::cout << v << " kilometers per hour (km/h) is "
                  << v * Speed::KilometerMileCoef
                  << " miles per hour (mph).\n";
        break;
      // Miles per hour to kilometers per hour
      case 2:
        while (v < Speed::minSpeed)
        {
          std::cout << "Enter speed in miles per hour (mph): ";
          std::cin >> v;

          if (v < Speed::minSpeed)
            std::cout << "Invalid input!\n\n";
        }

        std::cout << v << " miles per hour (mph) is "
                  << v / Speed::KilometerMileCoef
                  << " kilometers per hour (km/h).\n";
        break;
      }
      break;
    }
    // LENGTH MENU
    case 3:
    {
      while (subchoice < 1 || subchoice > 6)
      {
        std::cout << "Please choose converter:\n"
                     "1. Light years to kilometers\n"
                     "2. Kilometers to light years\n"
                     "3. Feet to meters\n"
                     "4. Meters to feet\n"
                     "5. Inches to centimeters\n"
                     "6. Centimeters to inches\n\nYour choice: ";

        std::cin >> subchoice;

        if (!subchoice)
          std::cout << "Invalid input!\n\n";
      }

      double l = -1;
      switch (subchoice)
      {
      // Light year to kilometer
      case 1:
      {
        while (l < Length::minLength || l > Length::maxLyToKm)
        {
          std::cout << "Enter length in light years: ";
          std::cin >> l;

          if (l < Length::minLength)
            std::cout << "Invalid input!\n\n";
        }

        std::cout << l << " light years is "
                  << l * Length::LightYearKilometerCoef
                  << " kilometers.\n";
        break;
      }
      // Kilometer to light year
      case 2:
      {
        while (l < Length::minLength || l > Length::maxDoubleInteger - 1)
        {
          std::cout << "Enter length in kilometers: ";
          std::cin >> l;

          if (l < Length::minLength)
            std::cout << "Invalid input!\n\n";
        }

        std::cout << l << " kilometers is "
                  << l / Length::LightYearKilometerCoef
                  << " light years.\n";
        break;
      }
      // Feet to meters
      case 3:
      {
        while (l < Length::minLength)
        {
          std::cout << "Enter length in feet: ";
          std::cin >> l;

          if (l < Length::minLength)
            std::cout << "Invalid input!\n\n";
        }

        std::cout << l << " feet is "
                  << l * Length::FeetMeterCoef
                  << " meters.\n";
        break;
      }
      // Meters to feet
      case 4:
      {
        while (l < Length::minLength)
        {
          std::cout << "Enter length in meters: ";
          std::cin >> l;

          if (l < Length::minLength)
            std::cout << "Invalid input!\n\n";
        }

        std::cout << l << " meters is "
                  << l / Length::FeetMeterCoef
                  << " feet.\n";
        break;
      }
      // Inches to centimeters
      case 5:
      {
        while (l < Length::minLength)
        {
          std::cout << "Enter length in inches: ";
          std::cin >> l;

          if (l < Length::minLength)
            std::cout << "Invalid input!\n\n";
        }

        std::cout << l << " inches is "
                  << l * Length::InchCentimeterCoef
                  << " centimeters.\n";
        break;
      }
      // Centimeters to inches
      case 6:
      {
        while (l < Length::minLength)
        {
          std::cout << "Enter length in centimeters: ";
          std::cin >> l;

          if (l < Length::minLength)
            std::cout << "Invalid input!\n\n";
        }

        std::cout << l << " centimeters is "
                  << l / Length::InchCentimeterCoef
                  << " inches.\n";
        break;
      }
      }
      break;
    }
    // WEIGHT MENU
    case 4:
    {
      while (subchoice < 1 || subchoice > 2)
      {
        std::cout << "Please choose converter:\n"
                     "1. Kilograms to pounds\n"
                     "2. Pounds to kilograms\n\nYour choice: ";

        std::cin >> subchoice;

        if (!subchoice)
          std::cout << "Invalid input!\n\n";
      }

      double m = -1;
      switch (subchoice)
      {
      // Kilograms to pounds
      case 1:
        while (m < Weight::minWeight)
        {
          std::cout << "Enter weight in kilograms: ";
          std::cin >> m;

          if (m < Weight::minWeight)
            std::cout << "Invalid input!\n\n";
        }

        std::cout << m << " kilograms is "
                  << m * Weight::KilogramPountCoef
                  << " pounds.\n";
        break;
      // Pounds to kilograms
      case 2:
        while (m < Weight::minWeight)
        {
          std::cout << "Enter weight in pounds: ";
          std::cin >> m;

          if (m < Weight::minWeight)
            std::cout << "Invalid input!\n\n";
        }

        std::cout << m << " pounds is "
                  << m / Weight::KilogramPountCoef
                  << " kilograms.\n";
        break;
      }
      break;
    }
    // FUEL ECONOMY MENU
    case 5:
    {
      while (subchoice < 1 || subchoice > 2)
      {
        std::cout << "Please choose converter:\n"
                     "1. Liters per 100 kilometers (l/100km) to miles per gallon (mpg)\n"
                     "2. Miles per gallon (mpg) to liters per 100 kilometers (l/100km)\n\nYour choice: ";

        std::cin >> subchoice;

        if (!subchoice)
          std::cout << "Invalid input!\n\n";
      }

      double e = -1;
      switch (subchoice)
      {
      // Liters per 100 kilometers to miles per gallon
      case 1:
        while (e < FuelEconomy::minFuelEconomy)
        {
          std::cout << "Enter fuel economy in liters per 100 kilometers (l/100km): ";
          std::cin >> e;

          if (e < FuelEconomy::minFuelEconomy)
            std::cout << "Invalid input!\n\n";
        }

        std::cout << e << " liters per 100 kilometers (l/100km) is "
                  << FuelEconomy::KmMPGCoef / e
                  << " miles per gallon (mpg).\n";
        break;
      // Miles per gallon to liters per 100 kilometers
      case 2:
        while (e < FuelEconomy::minFuelEconomy)
        {
          std::cout << "Enter fuel economy in miles per gallon (mpg): ";
          std::cin >> e;

          if (e < FuelEconomy::minFuelEconomy)
            std::cout << "Invalid input!\n\n";
        }

        std::cout << e << " miles per gallon (mpg) is "
                  << FuelEconomy::KmMPGCoef / e
                  << " liters per 100 kilometers (l/100km).\n";
        break;
      }
      break;
    }
    default:
    {
      choice = 0;
      std::cout << "Invalid input!\n\n";
      break;
    }
    }
  }

  return 0;
}