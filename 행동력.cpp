/**
	�ϸ��� ������ �ൿ���� ����մϴ�.
*/
int PK_�ൿ��(District district)
{
	Person totoku(district.����);
	int result = 0;

	result += std::max(totoku.���, totoku.�ŷ�) / 5;
	if (result < 6)
		result = 6;

	int city_count = std::min(district.���ü�, 6) * 10;
	result += city_count + 10;
	result += std::min(city_count, district.�Ϲݹ����);

	Person gunshi(Force(district.getForceId()).����);
	if (isalive(gunshi))
	{
		int i = gunshi.����;
		i -= 60;
		i /= 2;
		i += 100;
		i *= result;
		i /= 100;
		result = i;
	}

	result += district.queryValue(���ܼӼ�_�Ǽ��Ϸ�ü��� + �ü�_������) * 5;

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	if (!district.isPlayer())
		result *= 2;
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	return result;
}