/**
	�������� �߻��� Ȯ���� ����մϴ�.
	@param city ����
*/
int PK_�������߻�Ȯ��(City city) {
	// 1������ 6������ �߻� ����
	if (Scenario().getElapsedMonths() <= 6)
		return 0;

	// �ߺ� �߻� ����
	int city_id = city.getId();
	for (auto i = Scenario().�ǹ�.begin(); i; i++) {
		Building building = i();
		if (isalive(building) && (building.�ü� == �ü�_������1 || building.�ü� == �ü�_������2) && building.getAreaCityId() == city_id)
			return 0;
	}

	// ġ���� ����ġ�� ���� ��� �߻����� ����.
	if (city.ġ�� >= 80 + (city.toBuilding().hasSkill(Ư��_����) ? -20 : 0))
		return 0;

	// ����ġ�� ���� ���� ��� �߻� Ȯ��.
	return (100 - city.ġ��) / 3;
}