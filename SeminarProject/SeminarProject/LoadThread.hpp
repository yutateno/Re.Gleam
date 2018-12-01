#pragma once
#include "LoadScreen.hpp"


class LoadThread
{
private:
	// �񓯊����s��
	std::thread ths;

	// ���[�h������
	int num;

	// ���[�h��������
	std::vector<int> fileName;

	// ���[�h��ʂ̃|�C���^
	LoadScreen* p_loadScreen;


	// �񓯊����s�����\�b�h
	void MyNextLoad(const std::string path, int& file, const ELOADFILE type);

	   
public:
	// �R���X�g���N�^
	LoadThread();

	// �f�X�g���N�^
	~LoadThread();


	// �s��
	void Process(const int max, const std::string* path, const ELOADFILE* type);


	/// �Q�b�^�[�Z�b�^�[
	
	// ���[�h�������̂�n��
	const std::vector<int> GetFile() const;

	// ���[�h���I������
	const int GetNum() const;
};