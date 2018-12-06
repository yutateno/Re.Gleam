#pragma once
#include "BaseMove.hpp"

class MainMove3 : public BaseMove
{
private:
	// �񓯊��e�N�X�`���؂�ւ�
	void ThsTextureReload() override;


public:
	MainMove3(const std::vector<int> v_file);
	~MainMove3();

	// �`��
	void Draw() override;

	// �v���Z�X
	void Process() override;

	// �J�����̃v���Z�X
	void CameraProcess() override;

	// �e�N�X�`���̐؂�ւ�
	void TextureReload() override;
};

