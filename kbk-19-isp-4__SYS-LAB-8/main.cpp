#include "iostream"

// 6.	��� ������ ����� �����: 17, -5, 3, -12, 24, 78, 61, 73, -9, 13. 
//		�� ������� ������� ����� ����� ����� �� �������� � ��������� ������, 
//		�������� �������� ����� �������� ����������� ��������� � �������� ���������.

int main()
{
	// ��������: �������� ���������!
	// ���������� ��������� ������� ����� ���� ����������, ��� � �������� �����
	// ������� ������ ��� ��� � �� �������

	int mass[10] = { 17, -5, 3, -12, 24, 78, 61, 73, -9, 13 };
	int result[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int max = 0, mass_offset = 0;

	_asm
	{
		lea ebx, mass

		// ����� ����������� �������� � �������
		mov ecx, 10
		loop_one:
		cmp eax, dword ptr[ebx]
			jg if_greater
			mov eax, dword ptr[ebx]
			if_greater :
			add ebx, 4
			loop loop_one

			// ���������� �����������
			mov max, eax

			// �������� ������ ������� �� ������ �����������
			mov ecx, 10
			loop_two:
		// ��������� �������� �� i �������� ��������� �������
		lea ebx, mass
			mov eax, mass_offset
			add ebx, eax
			mov eax, dword ptr[ebx]

			// �������� ����������� ��������� � ��������� ��������
			mov edx, max
			sub edx, eax

			// ������ � ����� ������
			lea ebx, result
			mov eax, mass_offset
			add ebx, eax
			mov dword ptr[ebx], edx

			// ���������� �������� ������� ��� ����� ��������
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
