# Car Rental Service

## Описание на задачата

Задачата реализира система за отдаване на коли под наем чрез класовете `User`, `RentableCar` и основния клас `CarRentalService`.

---

## Класове и функционалности

### ✅ User

Моделира потребител на системата с:
- **Потребителско име** – текст без интервали
- **Шофьорска книжка** – точно 10 алфанумерични символа
- **Възраст** – цяло число над 18

**Методи:**
- `getUsername()`, `getLicense()`, `getAge()`
- `setUsername()`, `setLicense()`, `setAge()`
- Сериализация към/от поток: `writeToStream(std::ostream&)`, `readFromStream(std::istream&)`

---

### 🚗 RentableCar

Представлява кола, която може да се наеме. Има:
- Уникално ID (автоматично генерирано)
- Конски сили (`horsePowers`)
- Капацитет на резервоара (`fuelCapacity`)
- Показател дали е наета и от кого

**Методи:**
- `rent(const User*)` – наема колата (хвърля изключение, ако вече е наета)
- `returnToDealer()` – връща колата и изчислява печалбата от наема:
  
  `profit = 10 * HP + 5 * FuelCapacity + 2 * RenterAge`

- `isRented()`, `getId()`, `getHorsePowers()`, `getFuelCapacity()`
- Сериализация: `writeToStream()`, `readFromStream()`

---

### 🏢 CarRentalService

Основният клас, който управлява колекция от коли за наемане. Съдържа:
- Динамичен масив от `RentableCar`
- Максимален капацитет, зададен при създаване
- Общата натрупана печалба от всички наеми

**Функции:**
- `addCar(const RentableCar&)`
- `removeCar(unsigned id)` – хвърля изключение, ако колата е наета
- `rentCar(unsigned id, const User*)` – наема кола
- `returnCar(unsigned id)` – връща кола и добавя печалбата
- `findCar(unsigned id)` – намира кола по ID
- Сериализация: `writeToStream()`, `readFromStream()`
