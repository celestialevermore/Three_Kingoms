namespace ����_���� {

// Main main;

class Main
{
	Main()
	{
		regtrg(�̺�Ʈ2_Ű����, Ʈ����_�ʼ��̺�Ʈ, TriggerCallbackType2(keyup), true);
	}

	bool keyup(trgevent2 e)
	{
		if (e.getNum() == win32api::VK_F5)
		{
			// ������ �����Դϴ�.
			int prev_time = game().���ӵ�;
			game().���ӵ� = 100;

			trgcouncil().run(����_����, ����_����, ����_����, ����_����, -1, -1, -1, CouncilCallbackType(sample1));
			
			game().���ӵ� = prev_time;
		}
		else if (e.getNum() == win32api::VK_F6)
		{
			// �����̳� �ϱ��並 ����ؾ��� ����� �����Դϴ�.
			// ȭ�� ��ȯ�� ���õ� ������ ���� ������ ������ �ʿ�� �մϴ�.
			int prev_time = game().���ӵ�;
			game().���ӵ� = 100;

			step2_ = 0;
			trgcouncil().run(-1, -1, -1, -1, -1, -1, -1, CouncilCallbackType(sample2));

			game().���ӵ� = prev_time;
		}
		else if (e.getNum() == win32api::VK_F7)
		{
			// ���ͳݿ� ������ ���� ��ȯ�� ���� �������� ����� �̾߱��� ��ȭ Ÿ¥ ������ ���� �����Դϴ�. 
			int prev_time = game().���ӵ�;
			game().���ӵ� = 100;

			trgscene().move(City(����_�Ǿ�), 2000);
			trgdiplomacy().run(����_�ձ�, -1, ����_���, CouncilCallbackType(scene1));
			trgscene().move(City(����_����), 2000);
			trgcouncil().run(����_����, ����_���, ����_������, -1, -1, -1, -1, CouncilCallbackType(scene2));
			trgscene().effect(18); // �� ���� scene �Լ��� ���� ������ ���⸦ �߰��� �߰��� �� ���� ������ �� ���� �δ°� �ڿ������� �������ϴ�.
			trgcouncil().run(����_����, ����_���, ����_������, -1, ����_����, -1, -1, CouncilCallbackType(scene3));

			game().���ӵ� = prev_time;
		}
		return false;
	}

	void sample1()
	{
		trgcouncil().animation(700, ����_����, 0x37);
		MessageBox().talk("ȸ�Ǹ� �����ϵ��� ����.", ����_����);

		trgcouncil().animation(0, ����_����, 0x48);
		MessageBox().talk("���־�!", ����_����);

		trgcouncil().animation(0, ����_����, 0x4f);
		MessageBox().talk("(��������)", ����_����);
	}

	private int step2_ = 0;
	void sample2()
	{
		step2_++;
		MessageBox().talk(format("step: {}", step2_));
		if (step2_ == 1)
		{
			trgdebate().init();
			trgdebate().setSlot(0, 850, true); // �Ź���
			trgdebate().setSlot(1, 0xcf, false); // �õ���(����1)
			// ������ ���� ��� ����.(������ ������ sample2 �Լ��� �ٽ� ȣ��˴ϴ�.)
			if (trgdebate().run())
				return;
			// ������ ���� �ʴ´ٸ� ��������.
			step2_++;
			// �� ������ �ٸ� �ڵ带 �߰����� ������.
		}
		if (step2_ == 2)
		{
			trgduel().init();
			trgduel().setSlot(0, 0, 850); // �Ź���
			trgduel().setSlot(1, 0, 0x15d); // ����(����3)
			trgduel().setControl(0, 0);
			if (trgduel().run(1))
				return;
			step2_++;
		}
	}

	void scene1()
	{
		trgdiplomacy d;
		MessageBox m;
		d.animation(100, ����_���, 0x5b);
		m.talk("�ðܸ� �ּ���. ���� ���� �аŸ� �� �ù��ҵ��� Ȯ ����Ұ� �ö���", ����_���);
	}

	void scene2()
	{
		trgcouncil c;
		MessageBox m;
		m.talk("(�δ��ϴ�)", ����_������);
		m.talk("(������ ����� �ü��� ���ƿ� ������)", ����_������);
		m.talk("(������ �������� ����)", ����_������);
		m.talk("(�� ����� �������� �����ϱ�)", ����_������);
		c.animation(0, ����_������, 0x3a);
		m.talk("���� ���ָ� ���캸�� �Ұ���\n����ϱ�\n�ڰ沲�� ���ñ⿡ �Ҹ����������� ��...", ����_������);
		c.animation(0, ����_���, 0x82);
		m.talk("���۱׸�, �� �� ����?", ����_���);
		c.animation(0, ����_������, 0x4f);
		m.talk("����", ����_������);
		m.talk("�ƿ� ���ֿ� ���� ���� ��������?", ����_���);
		c.animation(0, ����_���, 0x5c);
		m.talk("������ ���ٸ� �ֹ����� ���̳� �� ������?", ����_���);
		c.animation(0, ����_����, 0x37);
		m.talk("���ְ� �� ���� �� �� ���ٴ� ���� �־�?", ����_����);
		c.animation(0, ����_���, 0x81);
		m.talk("����? ���� ����", ����_���);
		c.animation(0, ����_���, 0x37);
		m.talk("�ʴ� �츮 ������ \'���͸ξ� �������� ����\'�� �ٶ��� �־��� ���̿�", ����_���);
		m.talk("�׷��� ���� �����̶� �ϵ��� �ڿ��� �ܸ� ���� ������ �������� �ο��� ������ ����������", ����_���); // ��, ��
		c.animation(0, ����_���, 0x41);
		m.talk("�翬�� ���ִ� ������ �Ǵ� �� �ƴϰھ�?", ����_���); // ��
		c.animation(0, ����_������, 0x3f);
		m.talk("�ó����� ���� �ֳ� �츮 �ƴϾ��� �׺����� ��ģ ������", ����_������);
		c.animation(0, ����_���, 0x81);
		m.talk("����������������������������������", ����_���);
		c.animation(0, ����_������, 0x37);
		m.talk("��Ȳ���� ��ī ������ ���� ��ã�� �� �Ŷ�� �ϸ� ��¿�ǵ�?", ����_������);
		c.animation(0, ����_���, 0x3d);
		m.talk("����� ���� ���Ͽ� ���� ���ֿ��� ����. ���⿡ ������ ���� ��ī �ΰ�� ���ָ� �԰ڴٴ°� �Ƴ�?", ����_���);
		c.animation(0, ����_������, 0x41);
		m.talk("���� õ���� ����� ���ٴ��� ���̷��� ���...\n�Ĵ޸���?", ����_������); // ��
		c.animation(0, ����_���, 0x81);
		m.talk("�Ĵ޷�?\n��������������������", ����_���);
		c.animation(0, ����_���, 0x3f);
		m.talk("���� �� �� ����ϰ� �� �ո��� �Ǵ�", ����_���);
		m.talk("�غ�ƾ�? ���?", ����_���);
		c.animation(0, ����_���, 0x3a);
		m.talk("�� ���ݺ��� Ȯ�ε��ڽ��ϴ���", ����_���);
		m.talk("�����~ ����� �� ������ ������\n�ٶ󸮴ٶ�", ����_���);
	}

	void scene3()
	{
		trgcouncil c;
		MessageBox m;
		m.talk("...", ����_����);
		c.animation(0, ����_����, 0x81);
		m.talk("�����.", ����_����);
		m.talk("�����?", ����_���);
		c.animation(0, ����_���, 0x5c);
		m.talk("...���� �þ�\n�� ���߳� ���Ͽ� �ִ� �� �ȶ��� �ôٴϲ�?", ����_���);
		c.animation(0, ����_������, 0x44);
		m.talk("\'Ȯ������ ������ �ºθ� ��������.\'\n�̷� �� �ȹ����?", ����_������);
		c.animation(0, ����_����, 0x37);
		m.talk("���� ���� ������� �� ���ư���", ����_����);
	}
};

} // namespace