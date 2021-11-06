#include "iostream"

// 6.	Дан массив целых чисел: 17, -5, 3, -12, 24, 78, 61, 73, -9, 13. 
//		По данному массиву целых чисел найти их максимум и построить массив, 
//		элементы которого равны разности полученного максимума и исходных элементов.

int main()
{
	// ВНИМАНИЕ: СТРАННОЕ ПОВЕДЕНИЕ!
	// Выполнение случайным образом может быть правильным, так и выдавать мусор
	// Причину понять мне так и не удалось

	int mass[10] = { 17, -5, 3, -12, 24, 78, 61, 73, -9, 13 };
	int result[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int max = 0, mass_offset = 0;

	_asm
	{
		lea ebx, mass

		// Поиск наибольшего значения в массиве
		mov ecx, 10
		loop_one:
		cmp eax, dword ptr[ebx]
			jg if_greater
			mov eax, dword ptr[ebx]
			if_greater :
			add ebx, 4
			loop loop_one

			// Сохранение наибольшего
			mov max, eax

			// Создание нового массива на основе предыдущего
			mov ecx, 10
			loop_two:
		// Получение значения из i элемента основного массива
		lea ebx, mass
			mov eax, mass_offset
			add ebx, eax
			mov eax, dword ptr[ebx]

			// Разность полученного максимума и исходного элемента
			mov edx, max
			sub edx, eax

			// Запись в новый массив
			lea ebx, result
			mov eax, mass_offset
			add ebx, eax
			mov dword ptr[ebx], edx

			// Сохранение смещения индекса для обоих массивов
			mov eax, mass_offset
			add eax, 4
			mov mass_offset, eax
			loop loop_two
	}

	std::cout << "max:\t" << max << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << result[i] << " ";
	}

	return 0;
}
