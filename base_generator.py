from nickname_generator import generate
import random

s_gender = ["Мужской", "Женский"]
s_sity = ["Москва", "Санкт-Петербург", "Омск", "Волгоград", "Волгодонск",
          "Челябинск",  "Самара", "Тула", "Белгород",  "Воркута", "Грозный",
          "Улан-Удэ",  "Казань",  "Новосибирск", "Екатеринбург", "Ростов-на-Дону",
          "Нижний Новгород", "Краснодар", "Красноярск", "Воронеж", "Пермь"]
s_interest = ["Киберспорт", "Спорт", "Мода", "Путешествия", "Компьютерные игры",
              "Активизм", "Вязание", "Автоспорт", "Театр", "Животные", "Музыка",
              "Фитнес", "Бодибилдинг", "Кроссфит", "Рисование", "Фотография",
              "Астрономия", "Техника", "Физика", "Покер", "Философия"]

try:
    for count in range (1, 201):
        print("Запись элемента №" + str(count) + '\t')
        uid = generate()
        
        file_1 = open("user_info/" + str(count) + ".ub", 'w+')
        file_1.write(uid + '\n')
        file_1.write(random.choice(s_gender) + '\n')
        file_1.write(str(random.randint(18, 45)) + '\n')
        file_1.write(random.choice(s_sity) + '\n')
        for i in range (random.randint(1, 6)):
            file_1.write(random.choice(s_interest) + '\n')
        file_1.close()
        
        file_2 = open("user_dreams/" + str(count) + ".ub", 'w+')
        file_2.write(uid + '\n')
        file_2.write(random.choice(s_gender) + '\n')
        file_2.write(str(random.randint(18, 45)) + '\n')
        file_2.write(random.choice(s_sity) + '\n')
        for i in range (random.randint(1, 6)):
            file_2.write(random.choice(s_interest) + '\n')
        file_2.close()
    print("\nЗапись закончена")
except FileNotFoundError:
    print("Невозможно открыть файл")
