/**
	���� ���� ġ�� �������� ����մϴ�.
	@param city ����
	@param month ��
*/
int PK_��������ġ������(City city, int month)
{
	if (month == 1 || month == 4 || month == 7 || month == 10)
	{
		int force_id = city.getForceId();
		if (!����Id_isValid(force_id))
			return 0;

		Force force(force_id);

		// �������� ���� �� 50% Ȯ���� �������� ����
		if (force.hasTech(�ⱳ_��������) && randbool(50))
			return 0;

		int n = 90;

		Person taishu(city.�¼�);
		if (isalive(taishu))
			n -= taishu.�ŷ�;

		n = std::max(n, 1);

		n /= 10;
		n += rand(3);

		return -std::min(n, 5);
	}
	return 0;
}