namespace ����ź�� {

Main main;

class Main
{
	Main()
	{
		regtrg(�̺�Ʈ_�÷��̾�������, Ʈ����_�ʼ��̺�Ʈ, TriggerCallbackType2(callback), true);
	}

	bool callback(trgevent2 e)
	{
		Person kunshu = e.getPerson();
		City city = Building(kunshu.�Ҽ�).toCity();

		if (city && city.���� > 25000 && randbool(2 + (city.�޶ѱ� ? rand(3) : 0)))
		{
			trgscene().move(Building(kunshu.�Ҽ�));
			trgscene().fade(0);
			trgsleep();
			trgscene().background(2);
			trgscene().fade(255);

			switch (rand(3))
			{
			case 0: MessageBox().talk(format("\x1b[1x{}\x1b[0x���� �ں� ���̴� ��ư� �� �����ϴ�. ���� ���� ���� �ֽʽÿ�.", kunshu.�̸�), ����_���); break;
			case 1: MessageBox().talk(format("���� ���� �͵� ���� �����̶�... \x1b[1x{}\x1b[0x��, �����ֽʽÿ�.", kunshu.�̸�), ����_���); break;
			case 2: MessageBox().talk("��Ź�Դϴ�...����...���� ���� ����...", ����_���); break;
			}

			array<int> food = { 0, std::rounddown(city.���� / 5, -3), std::rounddown(city.���� / 4, -3), std::rounddown(city.���� / 3, -3) };
			int tp = 0;
			array<string> items = { "���� �ʴ´�", format("���� {}�� �ش�", food[1]), format("���� {}�� �ش�", food[2]), format("���� {}�� �ش�", food[3]) };
			int i = MessageBox().choose(items, "������ �ְڽ��ϱ�?");

			switch (i)
			{
			case 0:
				switch (rand(2))
				{
				case 0: MessageBox().talk("�츮���Ե� ������ ����. �뼭�� �ֽÿ�.", kunshu); break;
				case 1: MessageBox().talk("���������� ���ÿ�. �Ȼ��� ���� �� ������.", kunshu); break;
				}

				switch (rand(3))
				{
				case 0: MessageBox().talk("...����� �ƴϴ�...", ����_���); break;
				case 1: MessageBox().talk("�ƾ�... ������ ������� �����̱���...", ����_���); break;
				case 2: MessageBox().talk(format("�̷�... \x1b[1x{}\x1b[0x�Ը��� �����߰Ǹ�...", kunshu.�̸�), ����_���); break;
				}
				
				tp = (rand(6) + 1) * 500;
				MessageBox().talk(format("�ⱳ ����Ʈ�� \x1b[1x{}\x1b[0x��ŭ �����߽��ϴ�.", tp));
				Force(kunshu.getForceId()).addTP(-tp, city.getPos());
				break;

			case 1:
			case 2:
			case 3:
				switch (rand(2))
				{
				case 0: MessageBox().talk(format("�˾Ҽ�. ���ѷ� ���� {}�� �غ��Ű�ڼ�.", food[i]), kunshu); break;
				case 1: MessageBox().talk(format("�װ� �� �ȵƱ�. ���� {}�� �ְڼ�.", food[i]), kunshu); break;
				}

				switch (rand(3))
				{
				case 0: MessageBox().talk("�����մϴ�. �� ������ ���� �ʰڽ��ϴ�.", ����_���); break;
				case 1: MessageBox().talk(format("�ƾ�, \x1b[1x{}\x1b[0x���� ������ �����Դϴ�. �� ������ �� ���ڽ��ϴ�.", kunshu.�̸�), ����_���); break;
				case 2: MessageBox().talk("�����մϴ�... �̰����� ��Ե� ������ �� ���� �� �����ϴ�.", ����_���); break;
				}

				tp = (rand(6) + 1) * 100;
				MessageBox().talk(format("�ⱳ ����Ʈ�� \x1b[1x{}\x1b[0x��ŭ �����߽��ϴ�.", tp));
				Force(kunshu.getForceId()).addTP(tp, city.getPos());
				city.addFood(-food[i], true);
				break;
			}

			trgscene().fade(0);
			trgsleep();
			trgscene().background(-1);
			trgscene().fade(255);
		}

		return false;
	}
};

} // namespace