namespace ����δ��۾��� {

Main main;

class Main {
	Main() {
		regtrg(�̺�Ʈ_��, Ʈ����_�ʼ��̺�Ʈ, TriggerCallbackType2(callback));
	}

	bool callback(trgevent2 e) {
		for (auto i = Scenario().�δ�.begin(); i; i++) {
			if (!i().isInWater() || i().���� >= ����_S)
				continue;
			int n = rand(����_S - i().����);
			if (n == 0)
				continue;
			array<Point> step;
			Point pos = i().getPos();
			for (int j = 0; j < n; j++) {
				pos = Map().getNeighbor(pos, Hex(pos).����);
				if (!Map().isValidPos(pos) || Hex(pos).�ǹ����� || Hex(pos).�δ����� || !(Hex(pos).���� == ����_�� || Hex(pos).���� == ����_�ٴ�) || !i().isLocationable(pos))
					break;
				step.insertLast(pos);
			}
			if (step.length() == 0)
				continue;
			switch (rand(2)) {
			case 0: MessageBox().balloon("��Ȳ��������!", i().����, i()); break;
			case 1: MessageBox().balloon("Ű�� ������� �������� �ʴ´�!", i().����, i()); break;
			}
			i().move(step);
		}
		return false;
	}
};

} // namespace