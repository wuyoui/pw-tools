#pragma once

#include "TranslatorService.h"
#include "LoadingScreen.h"
#include "..\COMMON\model.h"

using namespace System;
using namespace System::IO;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Text;

public ref class MainWindow : public System::Windows::Forms::Form
{
	public:
	MainWindow(void)
	{
		InitializeComponent();
		this->Icon = (Drawing::Icon^)((gcnew Resources::ResourceManager("sTools.icons", Reflection::Assembly::GetExecutingAssembly()))->GetObject("app"));
	}

	protected:
	/// <summary>
	/// Clean up any resources being used.
	/// </summary>
	~MainWindow()
	{
		if (components)
		{
			delete components;
		}
	}

	TranslatorService::SoapService^ soap;
	String^ appID;
	String^ from;
	String^ to;

	MODEL^ Model;

	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TextBox^  textBox_FileBON;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox_FileSMD;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button_Browse;
	private: System::Windows::Forms::TextBox^  textBox_FileECM;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::ListBox^  listBox_CombineActs;
	private: System::Windows::Forms::TextBox^  textBox_CombineAct;
	private: System::Windows::Forms::TextBox^  textBox_MoxtVersion;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::ListBox^  listBox_Acts;
	private: System::Windows::Forms::TextBox^  textBox_ActName;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::DataGridView^  dataGridView_AnimatedJoints;
	private: System::Windows::Forms::TextBox^  textBox_EndSample;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  textBox_StartSample;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  textBox_currentSample;
	private: System::Windows::Forms::TrackBar^  trackBar_Samples;
	private: System::Windows::Forms::TextBox^  textBox_ActFile;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column_JointID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column_JointName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column_Position;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column_Orientation;
	private: System::Windows::Forms::CheckBox^  checkBox_Translator;
	private: System::Windows::Forms::ComboBox^  comboBox_language;
	private: System::Windows::Forms::TextBox^  textBox_translationAct;
	private: System::Windows::Forms::TextBox^  textBox_translationCombineAct;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  exportActToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  importActToolStripMenuItem;
	private: System::Windows::Forms::Button^  button_save;
	private: System::ComponentModel::IContainer^  components;

#pragma region Windows Form Designer generated code
	/// <summary>
	/// Required method for Designer support - do not modify
	/// the contents of this method with the code editor.
	/// </summary>
	void InitializeComponent(void)
	{
		this->components = (gcnew System::ComponentModel::Container());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
		this->textBox_FileBON = (gcnew System::Windows::Forms::TextBox());
		this->label3 = (gcnew System::Windows::Forms::Label());
		this->textBox_FileSMD = (gcnew System::Windows::Forms::TextBox());
		this->label2 = (gcnew System::Windows::Forms::Label());
		this->button_Browse = (gcnew System::Windows::Forms::Button());
		this->textBox_FileECM = (gcnew System::Windows::Forms::TextBox());
		this->button_save = (gcnew System::Windows::Forms::Button());
		this->label1 = (gcnew System::Windows::Forms::Label());
		this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
		this->textBox_translationCombineAct = (gcnew System::Windows::Forms::TextBox());
		this->textBox_CombineAct = (gcnew System::Windows::Forms::TextBox());
		this->textBox_MoxtVersion = (gcnew System::Windows::Forms::TextBox());
		this->listBox_CombineActs = (gcnew System::Windows::Forms::ListBox());
		this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
		this->textBox_ActFile = (gcnew System::Windows::Forms::TextBox());
		this->label8 = (gcnew System::Windows::Forms::Label());
		this->textBox_translationAct = (gcnew System::Windows::Forms::TextBox());
		this->textBox_currentSample = (gcnew System::Windows::Forms::TextBox());
		this->trackBar_Samples = (gcnew System::Windows::Forms::TrackBar());
		this->dataGridView_AnimatedJoints = (gcnew System::Windows::Forms::DataGridView());
		this->Column_JointID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column_JointName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column_Position = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column_Orientation = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->textBox_EndSample = (gcnew System::Windows::Forms::TextBox());
		this->label7 = (gcnew System::Windows::Forms::Label());
		this->textBox_StartSample = (gcnew System::Windows::Forms::TextBox());
		this->label6 = (gcnew System::Windows::Forms::Label());
		this->textBox_ActName = (gcnew System::Windows::Forms::TextBox());
		this->label5 = (gcnew System::Windows::Forms::Label());
		this->listBox_Acts = (gcnew System::Windows::Forms::ListBox());
		this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
		this->exportActToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->importActToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->checkBox_Translator = (gcnew System::Windows::Forms::CheckBox());
		this->comboBox_language = (gcnew System::Windows::Forms::ComboBox());
		this->groupBox1->SuspendLayout();
		this->groupBox2->SuspendLayout();
		this->groupBox3->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar_Samples))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_AnimatedJoints))->BeginInit();
		this->contextMenuStrip1->SuspendLayout();
		this->SuspendLayout();
		// 
		// groupBox1
		// 
		this->groupBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->groupBox1->Controls->Add(this->textBox_FileBON);
		this->groupBox1->Controls->Add(this->label3);
		this->groupBox1->Controls->Add(this->textBox_FileSMD);
		this->groupBox1->Controls->Add(this->label2);
		this->groupBox1->Controls->Add(this->button_Browse);
		this->groupBox1->Controls->Add(this->textBox_FileECM);
		this->groupBox1->Controls->Add(this->button_save);
		this->groupBox1->Controls->Add(this->label1);
		this->groupBox1->Location = System::Drawing::Point(1, 3);
		this->groupBox1->Name = L"groupBox1";
		this->groupBox1->Size = System::Drawing::Size(950, 100);
		this->groupBox1->TabIndex = 1;
		this->groupBox1->TabStop = false;
		this->groupBox1->Text = L"INPUT FILES";
		// 
		// textBox_FileBON
		// 
		this->textBox_FileBON->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->textBox_FileBON->Enabled = false;
		this->textBox_FileBON->Location = System::Drawing::Point(64, 73);
		this->textBox_FileBON->Name = L"textBox_FileBON";
		this->textBox_FileBON->Size = System::Drawing::Size(880, 20);
		this->textBox_FileBON->TabIndex = 6;
		// 
		// label3
		// 
		this->label3->AutoSize = true;
		this->label3->Location = System::Drawing::Point(6, 76);
		this->label3->Name = L"label3";
		this->label3->Size = System::Drawing::Size(52, 13);
		this->label3->TabIndex = 5;
		this->label3->Text = L"BON File:";
		// 
		// textBox_FileSMD
		// 
		this->textBox_FileSMD->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->textBox_FileSMD->Enabled = false;
		this->textBox_FileSMD->Location = System::Drawing::Point(64, 47);
		this->textBox_FileSMD->Name = L"textBox_FileSMD";
		this->textBox_FileSMD->Size = System::Drawing::Size(880, 20);
		this->textBox_FileSMD->TabIndex = 4;
		// 
		// label2
		// 
		this->label2->AutoSize = true;
		this->label2->Location = System::Drawing::Point(6, 50);
		this->label2->Name = L"label2";
		this->label2->Size = System::Drawing::Size(53, 13);
		this->label2->TabIndex = 3;
		this->label2->Text = L"SMD File:";
		// 
		// button_Browse
		// 
		this->button_Browse->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
		this->button_Browse->Location = System::Drawing::Point(788, 19);
		this->button_Browse->Name = L"button_Browse";
		this->button_Browse->Size = System::Drawing::Size(75, 23);
		this->button_Browse->TabIndex = 2;
		this->button_Browse->Text = L"Browse...";
		this->button_Browse->UseVisualStyleBackColor = true;
		this->button_Browse->Click += gcnew System::EventHandler(this, &MainWindow::click_Browse);
		// 
		// textBox_FileECM
		// 
		this->textBox_FileECM->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->textBox_FileECM->Enabled = false;
		this->textBox_FileECM->Location = System::Drawing::Point(64, 21);
		this->textBox_FileECM->Name = L"textBox_FileECM";
		this->textBox_FileECM->Size = System::Drawing::Size(718, 20);
		this->textBox_FileECM->TabIndex = 1;
		this->textBox_FileECM->Text = L"D:\\- GAMES -\\element.143\\models.pck.files\\models\\players\\形象\\刺客女\\躯干\\刺客女.ecm";
		// 
		// button_save
		// 
		this->button_save->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
		this->button_save->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(0)));
		this->button_save->Location = System::Drawing::Point(869, 19);
		this->button_save->Name = L"button_save";
		this->button_save->Size = System::Drawing::Size(75, 23);
		this->button_save->TabIndex = 7;
		this->button_save->Text = L"Save";
		this->button_save->UseVisualStyleBackColor = true;
		this->button_save->Click += gcnew System::EventHandler(this, &MainWindow::click_Save);
		// 
		// label1
		// 
		this->label1->AutoSize = true;
		this->label1->Location = System::Drawing::Point(6, 24);
		this->label1->Name = L"label1";
		this->label1->Size = System::Drawing::Size(52, 13);
		this->label1->TabIndex = 0;
		this->label1->Text = L"ECM File:";
		// 
		// groupBox2
		// 
		this->groupBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left));
		this->groupBox2->Controls->Add(this->textBox_translationCombineAct);
		this->groupBox2->Controls->Add(this->textBox_CombineAct);
		this->groupBox2->Controls->Add(this->textBox_MoxtVersion);
		this->groupBox2->Controls->Add(this->listBox_CombineActs);
		this->groupBox2->Location = System::Drawing::Point(1, 136);
		this->groupBox2->Name = L"groupBox2";
		this->groupBox2->Size = System::Drawing::Size(382, 484);
		this->groupBox2->TabIndex = 2;
		this->groupBox2->TabStop = false;
		this->groupBox2->Text = L"COMBINE ACTS";
		// 
		// textBox_translationCombineAct
		// 
		this->textBox_translationCombineAct->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->textBox_translationCombineAct->Enabled = false;
		this->textBox_translationCombineAct->Location = System::Drawing::Point(172, 19);
		this->textBox_translationCombineAct->Name = L"textBox_translationCombineAct";
		this->textBox_translationCombineAct->Size = System::Drawing::Size(204, 20);
		this->textBox_translationCombineAct->TabIndex = 7;
		// 
		// textBox_CombineAct
		// 
		this->textBox_CombineAct->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->textBox_CombineAct->Location = System::Drawing::Point(172, 45);
		this->textBox_CombineAct->Multiline = true;
		this->textBox_CombineAct->Name = L"textBox_CombineAct";
		this->textBox_CombineAct->ScrollBars = System::Windows::Forms::ScrollBars::Both;
		this->textBox_CombineAct->Size = System::Drawing::Size(204, 433);
		this->textBox_CombineAct->TabIndex = 3;
		this->textBox_CombineAct->WordWrap = false;
		this->textBox_CombineAct->Click += gcnew System::EventHandler(this, &MainWindow::click_CombineAct);
		// 
		// textBox_MoxtVersion
		// 
		this->textBox_MoxtVersion->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->textBox_MoxtVersion->Enabled = false;
		this->textBox_MoxtVersion->Location = System::Drawing::Point(6, 19);
		this->textBox_MoxtVersion->Name = L"textBox_MoxtVersion";
		this->textBox_MoxtVersion->Size = System::Drawing::Size(160, 20);
		this->textBox_MoxtVersion->TabIndex = 2;
		this->textBox_MoxtVersion->Text = L"MOXTVersion: ";
		// 
		// listBox_CombineActs
		// 
		this->listBox_CombineActs->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left));
		this->listBox_CombineActs->FormattingEnabled = true;
		this->listBox_CombineActs->Location = System::Drawing::Point(6, 45);
		this->listBox_CombineActs->Name = L"listBox_CombineActs";
		this->listBox_CombineActs->Size = System::Drawing::Size(160, 433);
		this->listBox_CombineActs->TabIndex = 0;
		this->listBox_CombineActs->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::select_CombineAct);
		// 
		// groupBox3
		// 
		this->groupBox3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->groupBox3->Controls->Add(this->textBox_ActFile);
		this->groupBox3->Controls->Add(this->label8);
		this->groupBox3->Controls->Add(this->textBox_translationAct);
		this->groupBox3->Controls->Add(this->textBox_currentSample);
		this->groupBox3->Controls->Add(this->trackBar_Samples);
		this->groupBox3->Controls->Add(this->dataGridView_AnimatedJoints);
		this->groupBox3->Controls->Add(this->textBox_EndSample);
		this->groupBox3->Controls->Add(this->label7);
		this->groupBox3->Controls->Add(this->textBox_StartSample);
		this->groupBox3->Controls->Add(this->label6);
		this->groupBox3->Controls->Add(this->textBox_ActName);
		this->groupBox3->Controls->Add(this->label5);
		this->groupBox3->Controls->Add(this->listBox_Acts);
		this->groupBox3->Location = System::Drawing::Point(389, 136);
		this->groupBox3->Name = L"groupBox3";
		this->groupBox3->Size = System::Drawing::Size(562, 484);
		this->groupBox3->TabIndex = 3;
		this->groupBox3->TabStop = false;
		this->groupBox3->Text = L"BASE ACTS";
		// 
		// textBox_ActFile
		// 
		this->textBox_ActFile->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->textBox_ActFile->Location = System::Drawing::Point(248, 71);
		this->textBox_ActFile->Name = L"textBox_ActFile";
		this->textBox_ActFile->Size = System::Drawing::Size(308, 20);
		this->textBox_ActFile->TabIndex = 20;
		// 
		// label8
		// 
		this->label8->AutoSize = true;
		this->label8->Location = System::Drawing::Point(169, 74);
		this->label8->Name = L"label8";
		this->label8->Size = System::Drawing::Size(45, 13);
		this->label8->TabIndex = 19;
		this->label8->Text = L"Act File:";
		// 
		// textBox_translationAct
		// 
		this->textBox_translationAct->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->textBox_translationAct->Enabled = false;
		this->textBox_translationAct->Location = System::Drawing::Point(248, 45);
		this->textBox_translationAct->Name = L"textBox_translationAct";
		this->textBox_translationAct->Size = System::Drawing::Size(308, 20);
		this->textBox_translationAct->TabIndex = 5;
		// 
		// textBox_currentSample
		// 
		this->textBox_currentSample->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
		this->textBox_currentSample->Enabled = false;
		this->textBox_currentSample->Location = System::Drawing::Point(515, 458);
		this->textBox_currentSample->Name = L"textBox_currentSample";
		this->textBox_currentSample->Size = System::Drawing::Size(41, 20);
		this->textBox_currentSample->TabIndex = 18;
		this->textBox_currentSample->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		// 
		// trackBar_Samples
		// 
		this->trackBar_Samples->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->trackBar_Samples->AutoSize = false;
		this->trackBar_Samples->Location = System::Drawing::Point(172, 458);
		this->trackBar_Samples->Maximum = 0;
		this->trackBar_Samples->Name = L"trackBar_Samples";
		this->trackBar_Samples->Size = System::Drawing::Size(337, 19);
		this->trackBar_Samples->TabIndex = 17;
		this->trackBar_Samples->TickStyle = System::Windows::Forms::TickStyle::None;
		this->trackBar_Samples->ValueChanged += gcnew System::EventHandler(this, &MainWindow::change_sample);
		// 
		// dataGridView_AnimatedJoints
		// 
		this->dataGridView_AnimatedJoints->AllowUserToAddRows = false;
		this->dataGridView_AnimatedJoints->AllowUserToDeleteRows = false;
		this->dataGridView_AnimatedJoints->AllowUserToResizeRows = false;
		this->dataGridView_AnimatedJoints->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->dataGridView_AnimatedJoints->BackgroundColor = System::Drawing::SystemColors::Window;
		this->dataGridView_AnimatedJoints->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {this->Column_JointID, 
			this->Column_JointName, this->Column_Position, this->Column_Orientation});
		this->dataGridView_AnimatedJoints->EnableHeadersVisualStyles = false;
		this->dataGridView_AnimatedJoints->Location = System::Drawing::Point(172, 123);
		this->dataGridView_AnimatedJoints->MultiSelect = false;
		this->dataGridView_AnimatedJoints->Name = L"dataGridView_AnimatedJoints";
		this->dataGridView_AnimatedJoints->ReadOnly = true;
		this->dataGridView_AnimatedJoints->RowHeadersVisible = false;
		this->dataGridView_AnimatedJoints->RowTemplate->Height = 20;
		this->dataGridView_AnimatedJoints->Size = System::Drawing::Size(384, 331);
		this->dataGridView_AnimatedJoints->TabIndex = 16;
		// 
		// Column_JointID
		// 
		this->Column_JointID->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->Column_JointID->DefaultCellStyle = dataGridViewCellStyle1;
		this->Column_JointID->HeaderText = L"Joint ID";
		this->Column_JointID->Name = L"Column_JointID";
		this->Column_JointID->ReadOnly = true;
		this->Column_JointID->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->Column_JointID->Width = 49;
		// 
		// Column_JointName
		// 
		this->Column_JointName->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
		this->Column_JointName->DefaultCellStyle = dataGridViewCellStyle2;
		this->Column_JointName->HeaderText = L"Joint Name";
		this->Column_JointName->Name = L"Column_JointName";
		this->Column_JointName->ReadOnly = true;
		this->Column_JointName->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// Column_Position
		// 
		this->Column_Position->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->Column_Position->DefaultCellStyle = dataGridViewCellStyle3;
		this->Column_Position->HeaderText = L"Position (x,y,z)";
		this->Column_Position->Name = L"Column_Position";
		this->Column_Position->ReadOnly = true;
		this->Column_Position->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->Column_Position->Width = 80;
		// 
		// Column_Orientation
		// 
		this->Column_Orientation->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->Column_Orientation->DefaultCellStyle = dataGridViewCellStyle4;
		this->Column_Orientation->HeaderText = L"Orientation (x,y,z,w)";
		this->Column_Orientation->Name = L"Column_Orientation";
		this->Column_Orientation->ReadOnly = true;
		this->Column_Orientation->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->Column_Orientation->Width = 105;
		// 
		// textBox_EndSample
		// 
		this->textBox_EndSample->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
		this->textBox_EndSample->Location = System::Drawing::Point(515, 97);
		this->textBox_EndSample->Name = L"textBox_EndSample";
		this->textBox_EndSample->Size = System::Drawing::Size(41, 20);
		this->textBox_EndSample->TabIndex = 7;
		this->textBox_EndSample->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		// 
		// label7
		// 
		this->label7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
		this->label7->AutoSize = true;
		this->label7->Location = System::Drawing::Point(442, 100);
		this->label7->Name = L"label7";
		this->label7->Size = System::Drawing::Size(67, 13);
		this->label7->TabIndex = 6;
		this->label7->Text = L"End Sample:";
		// 
		// textBox_StartSample
		// 
		this->textBox_StartSample->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
		this->textBox_StartSample->Location = System::Drawing::Point(395, 97);
		this->textBox_StartSample->Name = L"textBox_StartSample";
		this->textBox_StartSample->Size = System::Drawing::Size(41, 20);
		this->textBox_StartSample->TabIndex = 5;
		this->textBox_StartSample->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		// 
		// label6
		// 
		this->label6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
		this->label6->AutoSize = true;
		this->label6->Location = System::Drawing::Point(319, 100);
		this->label6->Name = L"label6";
		this->label6->Size = System::Drawing::Size(70, 13);
		this->label6->TabIndex = 4;
		this->label6->Text = L"Start Sample:";
		// 
		// textBox_ActName
		// 
		this->textBox_ActName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->textBox_ActName->Location = System::Drawing::Point(248, 19);
		this->textBox_ActName->Name = L"textBox_ActName";
		this->textBox_ActName->Size = System::Drawing::Size(308, 20);
		this->textBox_ActName->TabIndex = 3;
		// 
		// label5
		// 
		this->label5->AutoSize = true;
		this->label5->Location = System::Drawing::Point(169, 22);
		this->label5->Name = L"label5";
		this->label5->Size = System::Drawing::Size(57, 13);
		this->label5->TabIndex = 2;
		this->label5->Text = L"Act Name:";
		// 
		// listBox_Acts
		// 
		this->listBox_Acts->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left));
		this->listBox_Acts->ContextMenuStrip = this->contextMenuStrip1;
		this->listBox_Acts->FormattingEnabled = true;
		this->listBox_Acts->Location = System::Drawing::Point(6, 19);
		this->listBox_Acts->Name = L"listBox_Acts";
		this->listBox_Acts->Size = System::Drawing::Size(160, 459);
		this->listBox_Acts->TabIndex = 1;
		this->listBox_Acts->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::select_Act);
		// 
		// contextMenuStrip1
		// 
		this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->exportActToolStripMenuItem, 
			this->importActToolStripMenuItem});
		this->contextMenuStrip1->Name = L"contextMenuStrip1";
		this->contextMenuStrip1->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
		this->contextMenuStrip1->ShowImageMargin = false;
		this->contextMenuStrip1->Size = System::Drawing::Size(113, 48);
		// 
		// exportActToolStripMenuItem
		// 
		this->exportActToolStripMenuItem->Name = L"exportActToolStripMenuItem";
		this->exportActToolStripMenuItem->Size = System::Drawing::Size(112, 22);
		this->exportActToolStripMenuItem->Text = L"Export Act...";
		this->exportActToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::click_ExportAct);
		// 
		// importActToolStripMenuItem
		// 
		this->importActToolStripMenuItem->Name = L"importActToolStripMenuItem";
		this->importActToolStripMenuItem->Size = System::Drawing::Size(112, 22);
		this->importActToolStripMenuItem->Text = L"Import Act...";
		this->importActToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::click_ImportAct);
		// 
		// checkBox_Translator
		// 
		this->checkBox_Translator->AutoSize = true;
		this->checkBox_Translator->Location = System::Drawing::Point(1, 111);
		this->checkBox_Translator->Name = L"checkBox_Translator";
		this->checkBox_Translator->Size = System::Drawing::Size(109, 17);
		this->checkBox_Translator->TabIndex = 6;
		this->checkBox_Translator->Text = L"Enable Translator";
		this->checkBox_Translator->UseVisualStyleBackColor = true;
		this->checkBox_Translator->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::check_TranslationService);
		// 
		// comboBox_language
		// 
		this->comboBox_language->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
		this->comboBox_language->Enabled = false;
		this->comboBox_language->FormattingEnabled = true;
		this->comboBox_language->Location = System::Drawing::Point(116, 109);
		this->comboBox_language->Name = L"comboBox_language";
		this->comboBox_language->Size = System::Drawing::Size(75, 21);
		this->comboBox_language->TabIndex = 4;
		this->comboBox_language->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::change_language);
		// 
		// MainWindow
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(952, 621);
		this->Controls->Add(this->comboBox_language);
		this->Controls->Add(this->groupBox3);
		this->Controls->Add(this->checkBox_Translator);
		this->Controls->Add(this->groupBox2);
		this->Controls->Add(this->groupBox1);
		this->MinimumSize = System::Drawing::Size(960, 648);
		this->Name = L"MainWindow";
		this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
		this->Text = L" sACTedit";
		this->groupBox1->ResumeLayout(false);
		this->groupBox1->PerformLayout();
		this->groupBox2->ResumeLayout(false);
		this->groupBox2->PerformLayout();
		this->groupBox3->ResumeLayout(false);
		this->groupBox3->PerformLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar_Samples))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_AnimatedJoints))->EndInit();
		this->contextMenuStrip1->ResumeLayout(false);
		this->ResumeLayout(false);
		this->PerformLayout();

	}
#pragma endregion

	private: System::Void select_CombineAct(System::Object^  sender, System::EventArgs^  e)
	{
		if(listBox_CombineActs->SelectedIndex > -1)
		{
			textBox_CombineAct->Lines = Model->ECModel->combineActs[listBox_CombineActs->SelectedIndex]->GetAllParameters();
			textBox_translationCombineAct->Text = translate(Model->GetCombineActName(listBox_CombineActs->SelectedIndex));
		}
	}
	private: System::Void select_Act(System::Object^  sender, System::EventArgs^  e)
	{
		if(listBox_Acts->SelectedIndex > -1)
		{
			textBox_ActName->Text = Model->GetActName(listBox_Acts->SelectedIndex);
			textBox_translationAct->Text = translate(textBox_ActName->Text);
			textBox_ActFile->Text = Model->GetActStckFile(listBox_Acts->SelectedIndex);
			if(textBox_ActFile->Text != "")
			{
				textBox_ActFile->Enabled = true;
			}
			else
			{
				textBox_ActFile->Enabled = false;
			}
			textBox_StartSample->Text = Model->ModelDescription->GetStartSample(listBox_Acts->SelectedIndex).ToString("F0");
			textBox_EndSample->Text = Model->ModelDescription->GetEndSample(listBox_Acts->SelectedIndex).ToString("F0");
			textBox_currentSample->Text = "0";
			trackBar_Samples->Minimum = Convert::ToInt32(textBox_StartSample->Text);
			trackBar_Samples->Maximum = Convert::ToInt32(textBox_EndSample->Text);
			trackBar_Samples->Value = trackBar_Samples->Minimum;
		}
	}
	private: System::Void change_sample(System::Object^  sender, System::EventArgs^  e)
	{
		textBox_currentSample->Text = trackBar_Samples->Value.ToString();

		for(int i=0; i<Model->Skeleton->AnimatedJoints->Length; i++)
		{
			Point3f^ position = Model->GetJointPosition(listBox_Acts->SelectedIndex, i, trackBar_Samples->Value);
			Point4f^ orientation = Model->GetJointOrientation(listBox_Acts->SelectedIndex, i, trackBar_Samples->Value);

			dataGridView_AnimatedJoints->Rows[i]->Cells[2]->Value = position->X.ToString("F3") + ", " + position->Y.ToString("F3") + ", " + position->Z.ToString("F3");
			dataGridView_AnimatedJoints->Rows[i]->Cells[3]->Value = orientation->X.ToString("F3") + ", " + orientation->Y.ToString("F3") + ", " + orientation->Z.ToString("F3") + ", " + orientation->W.ToString("F3");
		}
	}
	private: System::Void click_Browse(System::Object^  sender, System::EventArgs^  e)
	{
		OpenFileDialog^ load = gcnew OpenFileDialog();
		load->Filter = "Elements Client Model (*.ecm)|*.ecm|All Files (*.*)|*.*";
		if(load->ShowDialog() == Windows::Forms::DialogResult::OK && System::IO::File::Exists(load->FileName))
		{
			textBox_FileECM->Text = load->FileName;

			Model = gcnew MODEL();
			Model->Load(load->FileName);

			textBox_MoxtVersion->Text = "MOXTVersion: " + Model->ECModel->header->Version;
			listBox_CombineActs->Items->Clear();
			for(int i=0; i<Model->GetCombineActCount(); i++)
			{
				listBox_CombineActs->Items->Add("[" + i + "] " + Model->GetCombineActName(i));
			}

			listBox_Acts->Items->Clear();
			for(int i=0; i<Model->GetActCount(); i++)
			{
				listBox_Acts->Items->Add("[" + i + "] " + Model->GetActName(i));
			}

			dataGridView_AnimatedJoints->Rows->Clear();
			for(int i=0; i<Model->Skeleton->AnimatedJoints->Length; i++)
			{
				dataGridView_AnimatedJoints->Rows->Add(gcnew array<String^>{
					Model->Skeleton->AnimatedJoints[i]->ID.ToString(),
					Model->GetAnimatedJointName(i)
				});
			}
		}
	}
 	private: System::Void click_Save(System::Object^  sender, System::EventArgs^  e)
	{
		if(File::Exists(textBox_FileECM->Text))
		{
			Model->Save(textBox_FileECM->Text);
		}
	}
	private: System::Void check_TranslationService(System::Object^  sender, System::EventArgs^  e)
	{
		if(checkBox_Translator->Checked)
		{
			Cursor = Windows::Forms::Cursors::WaitCursor;
			LoadingScreen^ initialize = gcnew LoadingScreen();
			initialize->Show();
			Application::DoEvents();
			try
			{
				soap = gcnew TranslatorService::SoapService();
				appID = "763743C8043FA427227700179E653860B731D443";
				from = "zh-CHS";
				to = "en";
				comboBox_language->Items->AddRange(soap->GetLanguagesForTranslate(appID));
				comboBox_language->SelectedItem = "en";

				textBox_translationAct->Enabled = true;
				textBox_translationCombineAct->Enabled = true;
				comboBox_language->Enabled = true;
			}
			catch(Exception^ e)
			{
				textBox_translationAct->Text = "TRANSLATION SERVICE UNAVAILABLE";
				textBox_translationCombineAct->Text = "TRANSLATION SERVICE UNAVAILABLE";
				MessageBox::Show(e->Message);
				checkBox_Translator->Checked = false;
			}
			initialize->Close();
			Cursor = Windows::Forms::Cursors::Default;
		}
		else
		{
			soap = nullptr;
			textBox_translationAct->Enabled = false;
			textBox_translationCombineAct->Enabled = false;
			comboBox_language->Enabled = false;
		}
	}

	String^ translate(String^ textIn)
	{
		String^ result = "";

		if(soap)
		{
			Cursor = Windows::Forms::Cursors::AppStarting;

			/*
			array<String^>^ words = textIn->Split(gcnew array<String^>{"_"}, StringSplitOptions::RemoveEmptyEntries);
			array<TranslatorService::TranslateArrayResponse^>^ words_translated = soap->TranslateArray(appID, words, from, to, gcnew TranslatorService::TranslateOptions());
			for(int i=0; i<words_translated->Length; i++)
			{
				if(i>0)
				{
					result += " ";
				}
				result += words_translated[i]->TranslatedText;
			}
			*/

			result = soap->Translate(appID, textIn->Replace("_", " "), from, to, "text/plain", "general");

			Cursor = Windows::Forms::Cursors::Default;
		}

		return result;
	}
	private: System::Void change_language(System::Object^  sender, System::EventArgs^  e)
	{
		to = comboBox_language->SelectedItem->ToString();
		select_CombineAct(nullptr, nullptr);
		select_Act(nullptr, nullptr);
	}
	private: System::Void click_CombineAct(System::Object^  sender, System::EventArgs^  e)
	{
		// get the text of the line where the caret is
		int posStart = textBox_CombineAct->SelectionStart;
		if(posStart > textBox_CombineAct->Text->Length-1)
		{
			posStart--;
		}
		while(posStart > -1 && textBox_CombineAct->Text[posStart] != '\n')
		{
			posStart--;
		}
		posStart++;
		int posEnd = textBox_CombineAct->Text->IndexOf("\r", textBox_CombineAct->SelectionStart);
		if(posEnd == -1)
		{
			posEnd = textBox_CombineAct->Text->Length-1;
		}

		if(posEnd > posStart)
		{
			String^ line = textBox_CombineAct->Text->Substring(posStart, posEnd-posStart);
			if(line->StartsWith("BaseActName:"))
			{
				String^ actName = line->Substring(line->IndexOf(" ")+1);

				for(int i=0; i<listBox_Acts->Items->Count; i++)
				{
					if(Model->GetActName(i) == actName)
					{
						listBox_Acts->SelectedIndex = i;
						break;
					}
				}
			}
		}
	}
	private: System::Void click_ExportAct(System::Object^  sender, System::EventArgs^  e)
	{
		if(listBox_Acts->SelectedIndex > -1)
		{
			SaveFileDialog^ save = gcnew SaveFileDialog();
			save->Filter = "Joint Act File (*.act)|*.act|All Files (*.*)|*.*";
			if(save->ShowDialog() == Windows::Forms::DialogResult::OK)
			{
				Model->ExportAct(listBox_Acts->SelectedIndex, save->FileName);
			}
		}
	}
	private: System::Void click_ImportAct(System::Object^  sender, System::EventArgs^  e)
	{
		if(listBox_Acts->SelectedIndex > -1)
		{
			OpenFileDialog^ load = gcnew OpenFileDialog();
			load->Filter = "Joint Act File (*.act)|*.act|All Files (*.*)|*.*";
			if(load->ShowDialog() == Windows::Forms::DialogResult::OK && System::IO::File::Exists(load->FileName))
			{
				Model->ImportAct(listBox_Acts->SelectedIndex, load->FileName);
				select_Act(nullptr, nullptr);
			}
		}
	}
};