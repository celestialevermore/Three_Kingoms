namespace ����_����ö�� {

Main main;

class Main {
	Main() {
		regai(AICallbackType(callback));
	}

	bool callback(Force force) {
		locktrg(�̺�Ʈ2_�δ����);

		// �÷��̾�, �̹��� ������ ����.
		if (force.isPlayer() || !force.isNormalForce()) {
			unlocktrg(�̺�Ʈ2_�δ����);
			return false;
		}

		int force_id = force.getId();
		for (int i = 0; i < ����_��; i++) {
			Building building(i);
			if (building.getForceId() == force_id && needRetreat(building))
				retreat(building);
		}

		unlocktrg(�̺�Ʈ2_�δ����);
		return false;
	}

	/** ö���� �ʿ��� �������� �Ǵ� */
	bool needRetreat(Building building) {
		NeedRetreatHelper helper(building);
		return helper.result;
	}

	/** ö�� ��� */
	bool retreat(Building building) {
		List<Person> officers = building.��ɰ��ɹ���;
		if (officers.empty())
			return false;
		int target = getNearestBase(building);
		if (target == -1)
			return false;
		officers.sort(����Ӽ�_�ɷ� + ����ɷ�_���, ����_��������);
		array<int> member = { officers[0].getId() };
		int unit_id = Controller().transport(building, member, building.��, building.����, building.����, getWeaponsArray(building), �δ��ӹ�_�̵�, Building(target).getPos());
		if (unit_id != -1)
			Unit(unit_id).�ൿ�Ϸ� = true;
		return true;
	}

	array<int> getWeaponsArray(Building building) {
		array<int> buf;
		for (int i = 0; i < ����_��; i++)
			buf.push_back(building.����[i]);
		return buf;
	}

	/** ���� ����� �Ʊ� ������ ����. �ϴ��� ���ø� Ȯ��. */
	int getNearestBase(Building src) {
		int best_dst = -1;
		int best_distance = 0;
		for (int i = 0; i < ����_��; i++) {
			Building dst(i);
			if (src.getId() == i || src.getForceId() != dst.getForceId() || dst.�ü� != �ü�_����)
				continue;
			int distance = Path().getDistance(src.getId(), i, src.getForceId());
			if (distance < best_distance || best_dst == -1) {
				best_dst = i;
				best_distance = distance;
			}
		}
		return best_dst;
	}
};

class NeedRetreatHelper {
	Building building;
	bool result;
	int own_transport;
	int enemy_unit1;		// ���� �� �����δ�
	int enemy_unit3;		// 3ĭ���� �� �����δ�
	int enemy_troops3;		// 3ĭ���� �� �����δ뺴��

	NeedRetreatHelper(Building building) {
		this.building = building;
		result = false;
		own_transport = 0;
		enemy_unit1 = 0;
		enemy_unit3 = 0;
		enemy_troops3 = 0;

		Map().range(building.getPos(), 1, 4 + (building.�ü� == �ü�_���� ? 1 : 0), RingCallbackType(callback));

		result = test();
	}

	bool callback(Hex hex, Point pos) {
		Unit unit(hex.getUnit());
		if (isalive(unit)) {
			int distance = Map().getDistance(building.getPos(), pos);
			if (building.isEnemy(unit)) {
				if (distance <= 1) {
					enemy_unit1++;
				}
				if (distance <= 3) {
					enemy_unit3++;
					enemy_troops3 += unit.����;
				}
			}
			else {
			}
		}
		return false;
	}

	bool test() {
		if (enemy_unit1 == 6)
			return false;
		// �ܿ� ������ �ƽ��ƽ��� ���
		if (building.���� < enemy_troops3 * 0.8 && building.���� < building.�ִ볻�� * 0.5 && building.���� < enemy_troops3 * 0.04)
			return true;
		// �ܿ� ������ �ƽ��ƽ��� ���
		if (building.���� < enemy_troops3 * 0.8 && building.���� < enemy_troops3 * 0.06)
			return true;
		return false;
	}
};

} // namespace