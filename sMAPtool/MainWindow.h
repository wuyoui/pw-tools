#pragma once

#include "..\COMMON\map.h"
#include "ColorExpansionBar.h"

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
		this->button_magnifier->BackgroundImage = (Drawing::Image^)((gcnew Resources::ResourceManager("sTools.icons", Reflection::Assembly::GetExecutingAssembly()))->GetObject("magnifier"));
		webBrowser_explorer->Url = gcnew Uri(Application::StartupPath + "\\html\\index.htm");

		Initialize();

		HMAP = gcnew hmap();
		HMAP->SelectedHeights = gcnew ArrayList(0);
		HMAP->Selection = gcnew ArrayList(0);
		pictureBox_hmap->BackgroundImage = gcnew Bitmap(513, 513);
		pictureBox_hmap->Image = gcnew Bitmap(513, 513);
		InitializeHmap();

		RMAP = gcnew rmap();
		RMAP->SelectedBits = gcnew ArrayList(0);
		RMAP->Selection = gcnew ArrayList(0);
		pictureBox_rmap->BackgroundImage = gcnew Bitmap(1024, 1024);
		pictureBox_rmap->Image = gcnew Bitmap(1024, 1024);
		InitializeRmap();

		WMAP = gcnew wmap();
		pictureBox_wmap->BackgroundImage = gcnew Bitmap(1024, 1024);
		pictureBox_wmap->Image = gcnew Bitmap(1024, 1024);
		InitializeWmap();

		PATHs = gcnew pathCollection();
		pictureBox_path->BackgroundImage = gcnew Bitmap(1024, 1024);
		pictureBox_path->Image = gcnew Bitmap(1024, 1024);
		InitializePath();
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

	::Controls::ColorExpansionBar^ colorValueExpansion;
	Image^ Background;
	pathCollection^ PATHs;
	hmap^ HMAP;
	rmap^ RMAP;
	wmap^ WMAP;

	bool ShiftDown;
	Windows::Forms::Cursor^ Pick;

	private: System::Windows::Forms::PictureBox^  pictureBox_hmap;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown_hmapSetNW;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::ToolTip^  toolTip;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  button_hmapLoad;
	private: System::Windows::Forms::TextBox^  textBox_hmapFile;
	private: System::Windows::Forms::Button^  button_hmapSave;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::Button^  button_rmapSave;
	private: System::Windows::Forms::Button^  button_rmapLoad;
	private: System::Windows::Forms::TextBox^  textBox_rmapFile;
	private: System::Windows::Forms::PictureBox^  pictureBox_rmap;
	private: System::Windows::Forms::Panel^  panel_rmap;
	private: System::Windows::Forms::Panel^  panel_hmap;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::Button^  button_rmapSet;
	private: System::Windows::Forms::ComboBox^  comboBox_rmapValue;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::GroupBox^  groupBox5;
	private: System::Windows::Forms::RadioButton^  radioButton_rmapPLine;
	private: System::Windows::Forms::RadioButton^  radioButton_rmapPFill;
	private: System::Windows::Forms::RadioButton^  radioButton_rmapLines;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::GroupBox^  groupBox6;
	private: System::Windows::Forms::TextBox^  textBox_convertInput;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button_convertLoad;
	private: System::Windows::Forms::GroupBox^  groupBox9;
	private: System::Windows::Forms::Button^  button_convertSave;
	private: System::Windows::Forms::TextBox^  textBox_convertOutput;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::GroupBox^  groupBox7;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::GroupBox^  groupBox8;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::GroupBox^  groupBox10;
	private: System::Windows::Forms::Button^  button_convertExport;
	private: System::Windows::Forms::CheckBox^  checkBox_convertTerrain;
	private: System::Windows::Forms::CheckBox^  checkBox_convertPrecinct;
	private: System::Windows::Forms::CheckBox^  checkBox_convertRegion;
	private: System::Windows::Forms::TabPage^  tabPage4;
	private: System::Windows::Forms::WebBrowser^  webBrowser_explorer;
	private: System::Windows::Forms::GroupBox^  groupBox11;
	private: System::Windows::Forms::ComboBox^  comboBox_hmapBackground;
	private: System::Windows::Forms::CheckBox^  checkBox_hmapBackground;
	private: System::Windows::Forms::GroupBox^  groupBox12;
	private: System::Windows::Forms::ComboBox^  comboBox_rmapBackground;
	private: System::Windows::Forms::CheckBox^  checkBox_rmapBackground;
	private: System::Windows::Forms::CheckBox^  checkBox_convertT2mk;
	private: System::Windows::Forms::TabPage^  tabPage5;
	private: System::Windows::Forms::GroupBox^  groupBox13;
	private: System::Windows::Forms::Button^  button_pathSave;
	private: System::Windows::Forms::Button^  button_pathLoad;
	private: System::Windows::Forms::TextBox^  textBox_pathFile;
	private: System::Windows::Forms::GroupBox^  groupBox14;
	private: System::Windows::Forms::ListBox^  listBox_pathSegments;
	private: System::Windows::Forms::ListBox^  listBox_pathPoints;
	private: System::Windows::Forms::TextBox^  textBox_pathSeperator2;
	private: System::Windows::Forms::TextBox^  textBox_pathSeperator1;
	private: System::Windows::Forms::TextBox^  textBox_pathUnknown1;
	private: System::Windows::Forms::TextBox^  textBox_pathID;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  textBox_pathPointZ;
	private: System::Windows::Forms::TextBox^  textBox_pathPointAlt;
	private: System::Windows::Forms::TextBox^  textBox_pathPointX;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::TextBox^  textBox_pathDirectionZ;
	private: System::Windows::Forms::TextBox^  textBox_pathDirectionAlt;
	private: System::Windows::Forms::TextBox^  textBox_pathDirectionX;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::GroupBox^  groupBox16;
	private: System::Windows::Forms::GroupBox^  groupBox15;
	private: System::Windows::Forms::TextBox^  textBox_pathSegmentTailZ;
	private: System::Windows::Forms::TextBox^  textBox_pathSegmentTailAlt;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  textBox_pathSegmentTailX;
	private: System::Windows::Forms::TextBox^  textBox_pathSegmentHeadX;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  textBox_pathSegmentHeadAlt;
	private: System::Windows::Forms::TextBox^  textBox_pathSegmentHeadZ;
	private: System::Windows::Forms::ListBox^  listBox_pathCollection;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::TextBox^  textBox_pathSegmentLength;
	private: System::Windows::Forms::TextBox^  textBox_pathSegmentEnd;
	private: System::Windows::Forms::TextBox^  textBox_pathSegmentStart;
	private: System::Windows::Forms::GroupBox^  groupBox17;
	private: System::Windows::Forms::ComboBox^  comboBox_pathBackground;
	private: System::Windows::Forms::CheckBox^  checkBox_pathBackground;
	private: System::Windows::Forms::Panel^  panel_path;
	private: System::Windows::Forms::PictureBox^  pictureBox_path;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip_path;
	private: System::Windows::Forms::ToolStripMenuItem^  addToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  deleteSelectedToolStripMenuItem;
	private: System::Windows::Forms::MenuStrip^  menuStrip_mainMenu;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem4;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;

	private: System::Windows::Forms::NumericUpDown^  numericUpDown_hmapSetSE;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown_hmapSetSW;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown_hmapSetNE;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::RadioButton^  radioButton4;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::CheckBox^  checkBox_FixT2bk;
	private: System::Windows::Forms::CheckBox^  checkBox_FixDat;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::PictureBox^  button_magnifier;
	private: System::Windows::Forms::TabPage^  tabPage6;
	private: System::Windows::Forms::GroupBox^  groupBox18;
	private: System::Windows::Forms::ComboBox^  comboBox_wmapBackground;
	private: System::Windows::Forms::CheckBox^  checkBox_wmapBackground;
	private: System::Windows::Forms::GroupBox^  groupBox21;
	private: System::Windows::Forms::ListBox^  listBox_wmapCollection;
	private: System::Windows::Forms::TextBox^  textBox_wmapSpanY;
	private: System::Windows::Forms::TextBox^  textBox_wmapSpanX;
	private: System::Windows::Forms::TextBox^  textBox_wmapCenterY;
	private: System::Windows::Forms::TextBox^  textBox_wmapCenterX;
	private: System::Windows::Forms::Label^  label38;
	private: System::Windows::Forms::Label^  label39;
	private: System::Windows::Forms::Label^  label40;
	private: System::Windows::Forms::Label^  label41;
	private: System::Windows::Forms::GroupBox^  groupBox22;
	private: System::Windows::Forms::Button^  button_waterSave;
	private: System::Windows::Forms::Button^  button_wmapLoad;
	private: System::Windows::Forms::TextBox^  textBox_wmapFile;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Label^  label23;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::Label^  label24;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::TextBox^  textBox9;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::TextBox^  textBox10;
	private: System::Windows::Forms::ListBox^  listBox2;
	private: System::Windows::Forms::TextBox^  textBox11;
	private: System::Windows::Forms::Label^  label25;
	private: System::Windows::Forms::TextBox^  textBox12;
	private: System::Windows::Forms::TextBox^  textBox13;
	private: System::Windows::Forms::Label^  label26;
	private: System::Windows::Forms::TextBox^  textBox14;
	private: System::Windows::Forms::TextBox^  textBox15;
	private: System::Windows::Forms::ListBox^  listBox3;
	private: System::Windows::Forms::TextBox^  textBox16;
	private: System::Windows::Forms::TextBox^  textBox17;
	private: System::Windows::Forms::TextBox^  textBox18;
	private: System::Windows::Forms::TextBox^  textBox19;
	private: System::Windows::Forms::Label^  label27;
	private: System::Windows::Forms::Label^  label28;
	private: System::Windows::Forms::Label^  label29;
	private: System::Windows::Forms::Label^  label30;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::TextBox^  textBox20;
	private: System::Windows::Forms::TextBox^  textBox_wmapAltitude;
	private: System::Windows::Forms::Label^  label31;
	private: System::Windows::Forms::PictureBox^  pictureBox_wmap;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip_water;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem2;
	private: System::ComponentModel::IContainer^  components;
	private:
	/// <summary>
	/// Required designer variable.
	/// </summary>

#pragma region Windows Form Designer generated code
	/// <summary>
	/// Required method for Designer support - do not modify
	/// the contents of this method with the code editor.
	/// </summary>
	void InitializeComponent(void)
	{
		this->components = (gcnew System::ComponentModel::Container());
		this->pictureBox_hmap = (gcnew System::Windows::Forms::PictureBox());
		this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
		this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
		this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
		this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
		this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
		this->panel1 = (gcnew System::Windows::Forms::Panel());
		this->label4 = (gcnew System::Windows::Forms::Label());
		this->numericUpDown_hmapSetSE = (gcnew System::Windows::Forms::NumericUpDown());
		this->numericUpDown_hmapSetSW = (gcnew System::Windows::Forms::NumericUpDown());
		this->numericUpDown_hmapSetNE = (gcnew System::Windows::Forms::NumericUpDown());
		this->numericUpDown_hmapSetNW = (gcnew System::Windows::Forms::NumericUpDown());
		this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
		this->toolTip = (gcnew System::Windows::Forms::ToolTip(this->components));
		this->checkBox_FixDat = (gcnew System::Windows::Forms::CheckBox());
		this->checkBox_FixT2bk = (gcnew System::Windows::Forms::CheckBox());
		this->checkBox_convertT2mk = (gcnew System::Windows::Forms::CheckBox());
		this->checkBox_convertTerrain = (gcnew System::Windows::Forms::CheckBox());
		this->checkBox_convertPrecinct = (gcnew System::Windows::Forms::CheckBox());
		this->checkBox_convertRegion = (gcnew System::Windows::Forms::CheckBox());
		this->button_magnifier = (gcnew System::Windows::Forms::PictureBox());
		this->button_convertExport = (gcnew System::Windows::Forms::Button());
		this->button_convertSave = (gcnew System::Windows::Forms::Button());
		this->button_convertLoad = (gcnew System::Windows::Forms::Button());
		this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
		this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
		this->groupBox10 = (gcnew System::Windows::Forms::GroupBox());
		this->label19 = (gcnew System::Windows::Forms::Label());
		this->label18 = (gcnew System::Windows::Forms::Label());
		this->groupBox9 = (gcnew System::Windows::Forms::GroupBox());
		this->textBox_convertOutput = (gcnew System::Windows::Forms::TextBox());
		this->label6 = (gcnew System::Windows::Forms::Label());
		this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
		this->textBox_convertInput = (gcnew System::Windows::Forms::TextBox());
		this->label2 = (gcnew System::Windows::Forms::Label());
		this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
		this->panel_path = (gcnew System::Windows::Forms::Panel());
		this->pictureBox_path = (gcnew System::Windows::Forms::PictureBox());
		this->groupBox17 = (gcnew System::Windows::Forms::GroupBox());
		this->comboBox_pathBackground = (gcnew System::Windows::Forms::ComboBox());
		this->checkBox_pathBackground = (gcnew System::Windows::Forms::CheckBox());
		this->groupBox16 = (gcnew System::Windows::Forms::GroupBox());
		this->textBox_pathSegmentLength = (gcnew System::Windows::Forms::TextBox());
		this->textBox_pathSegmentEnd = (gcnew System::Windows::Forms::TextBox());
		this->textBox_pathSegmentStart = (gcnew System::Windows::Forms::TextBox());
		this->label17 = (gcnew System::Windows::Forms::Label());
		this->label16 = (gcnew System::Windows::Forms::Label());
		this->label14 = (gcnew System::Windows::Forms::Label());
		this->textBox_pathSegmentTailZ = (gcnew System::Windows::Forms::TextBox());
		this->textBox_pathSegmentTailAlt = (gcnew System::Windows::Forms::TextBox());
		this->label7 = (gcnew System::Windows::Forms::Label());
		this->textBox_pathSegmentTailX = (gcnew System::Windows::Forms::TextBox());
		this->textBox_pathSegmentHeadX = (gcnew System::Windows::Forms::TextBox());
		this->label8 = (gcnew System::Windows::Forms::Label());
		this->textBox_pathSegmentHeadAlt = (gcnew System::Windows::Forms::TextBox());
		this->textBox_pathSegmentHeadZ = (gcnew System::Windows::Forms::TextBox());
		this->listBox_pathSegments = (gcnew System::Windows::Forms::ListBox());
		this->contextMenuStrip_path = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
		this->addToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->deleteSelectedToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->groupBox15 = (gcnew System::Windows::Forms::GroupBox());
		this->textBox_pathDirectionZ = (gcnew System::Windows::Forms::TextBox());
		this->listBox_pathPoints = (gcnew System::Windows::Forms::ListBox());
		this->textBox_pathDirectionAlt = (gcnew System::Windows::Forms::TextBox());
		this->label13 = (gcnew System::Windows::Forms::Label());
		this->textBox_pathDirectionX = (gcnew System::Windows::Forms::TextBox());
		this->textBox_pathPointX = (gcnew System::Windows::Forms::TextBox());
		this->label15 = (gcnew System::Windows::Forms::Label());
		this->textBox_pathPointAlt = (gcnew System::Windows::Forms::TextBox());
		this->textBox_pathPointZ = (gcnew System::Windows::Forms::TextBox());
		this->groupBox14 = (gcnew System::Windows::Forms::GroupBox());
		this->listBox_pathCollection = (gcnew System::Windows::Forms::ListBox());
		this->textBox_pathSeperator2 = (gcnew System::Windows::Forms::TextBox());
		this->textBox_pathSeperator1 = (gcnew System::Windows::Forms::TextBox());
		this->textBox_pathUnknown1 = (gcnew System::Windows::Forms::TextBox());
		this->textBox_pathID = (gcnew System::Windows::Forms::TextBox());
		this->label12 = (gcnew System::Windows::Forms::Label());
		this->label11 = (gcnew System::Windows::Forms::Label());
		this->label10 = (gcnew System::Windows::Forms::Label());
		this->label9 = (gcnew System::Windows::Forms::Label());
		this->groupBox13 = (gcnew System::Windows::Forms::GroupBox());
		this->button_pathSave = (gcnew System::Windows::Forms::Button());
		this->button_pathLoad = (gcnew System::Windows::Forms::Button());
		this->textBox_pathFile = (gcnew System::Windows::Forms::TextBox());
		this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
		this->groupBox11 = (gcnew System::Windows::Forms::GroupBox());
		this->comboBox_hmapBackground = (gcnew System::Windows::Forms::ComboBox());
		this->checkBox_hmapBackground = (gcnew System::Windows::Forms::CheckBox());
		this->panel_hmap = (gcnew System::Windows::Forms::Panel());
		this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
		this->button4 = (gcnew System::Windows::Forms::Button());
		this->button1 = (gcnew System::Windows::Forms::Button());
		this->button_hmapSave = (gcnew System::Windows::Forms::Button());
		this->button_hmapLoad = (gcnew System::Windows::Forms::Button());
		this->textBox_hmapFile = (gcnew System::Windows::Forms::TextBox());
		this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
		this->groupBox12 = (gcnew System::Windows::Forms::GroupBox());
		this->comboBox_rmapBackground = (gcnew System::Windows::Forms::ComboBox());
		this->checkBox_rmapBackground = (gcnew System::Windows::Forms::CheckBox());
		this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
		this->radioButton_rmapLines = (gcnew System::Windows::Forms::RadioButton());
		this->radioButton_rmapPLine = (gcnew System::Windows::Forms::RadioButton());
		this->radioButton_rmapPFill = (gcnew System::Windows::Forms::RadioButton());
		this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
		this->button_rmapSet = (gcnew System::Windows::Forms::Button());
		this->comboBox_rmapValue = (gcnew System::Windows::Forms::ComboBox());
		this->label1 = (gcnew System::Windows::Forms::Label());
		this->panel_rmap = (gcnew System::Windows::Forms::Panel());
		this->pictureBox_rmap = (gcnew System::Windows::Forms::PictureBox());
		this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
		this->button5 = (gcnew System::Windows::Forms::Button());
		this->button6 = (gcnew System::Windows::Forms::Button());
		this->button_rmapSave = (gcnew System::Windows::Forms::Button());
		this->button_rmapLoad = (gcnew System::Windows::Forms::Button());
		this->textBox_rmapFile = (gcnew System::Windows::Forms::TextBox());
		this->tabPage6 = (gcnew System::Windows::Forms::TabPage());
		this->pictureBox_wmap = (gcnew System::Windows::Forms::PictureBox());
		this->groupBox18 = (gcnew System::Windows::Forms::GroupBox());
		this->comboBox_wmapBackground = (gcnew System::Windows::Forms::ComboBox());
		this->checkBox_wmapBackground = (gcnew System::Windows::Forms::CheckBox());
		this->groupBox21 = (gcnew System::Windows::Forms::GroupBox());
		this->textBox_wmapAltitude = (gcnew System::Windows::Forms::TextBox());
		this->label31 = (gcnew System::Windows::Forms::Label());
		this->listBox_wmapCollection = (gcnew System::Windows::Forms::ListBox());
		this->contextMenuStrip_water = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
		this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->textBox_wmapSpanY = (gcnew System::Windows::Forms::TextBox());
		this->textBox_wmapSpanX = (gcnew System::Windows::Forms::TextBox());
		this->textBox_wmapCenterY = (gcnew System::Windows::Forms::TextBox());
		this->textBox_wmapCenterX = (gcnew System::Windows::Forms::TextBox());
		this->label38 = (gcnew System::Windows::Forms::Label());
		this->label39 = (gcnew System::Windows::Forms::Label());
		this->label40 = (gcnew System::Windows::Forms::Label());
		this->label41 = (gcnew System::Windows::Forms::Label());
		this->groupBox22 = (gcnew System::Windows::Forms::GroupBox());
		this->button_waterSave = (gcnew System::Windows::Forms::Button());
		this->button_wmapLoad = (gcnew System::Windows::Forms::Button());
		this->textBox_wmapFile = (gcnew System::Windows::Forms::TextBox());
		this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
		this->webBrowser_explorer = (gcnew System::Windows::Forms::WebBrowser());
		this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
		this->button2 = (gcnew System::Windows::Forms::Button());
		this->label3 = (gcnew System::Windows::Forms::Label());
		this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
		this->button3 = (gcnew System::Windows::Forms::Button());
		this->label5 = (gcnew System::Windows::Forms::Label());
		this->menuStrip_mainMenu = (gcnew System::Windows::Forms::MenuStrip());
		this->toolStripMenuItem4 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
		this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
		this->textBox1 = (gcnew System::Windows::Forms::TextBox());
		this->textBox2 = (gcnew System::Windows::Forms::TextBox());
		this->textBox3 = (gcnew System::Windows::Forms::TextBox());
		this->label20 = (gcnew System::Windows::Forms::Label());
		this->label21 = (gcnew System::Windows::Forms::Label());
		this->label22 = (gcnew System::Windows::Forms::Label());
		this->textBox4 = (gcnew System::Windows::Forms::TextBox());
		this->textBox5 = (gcnew System::Windows::Forms::TextBox());
		this->label23 = (gcnew System::Windows::Forms::Label());
		this->textBox6 = (gcnew System::Windows::Forms::TextBox());
		this->textBox7 = (gcnew System::Windows::Forms::TextBox());
		this->label24 = (gcnew System::Windows::Forms::Label());
		this->textBox8 = (gcnew System::Windows::Forms::TextBox());
		this->textBox9 = (gcnew System::Windows::Forms::TextBox());
		this->listBox1 = (gcnew System::Windows::Forms::ListBox());
		this->textBox10 = (gcnew System::Windows::Forms::TextBox());
		this->listBox2 = (gcnew System::Windows::Forms::ListBox());
		this->textBox11 = (gcnew System::Windows::Forms::TextBox());
		this->label25 = (gcnew System::Windows::Forms::Label());
		this->textBox12 = (gcnew System::Windows::Forms::TextBox());
		this->textBox13 = (gcnew System::Windows::Forms::TextBox());
		this->label26 = (gcnew System::Windows::Forms::Label());
		this->textBox14 = (gcnew System::Windows::Forms::TextBox());
		this->textBox15 = (gcnew System::Windows::Forms::TextBox());
		this->listBox3 = (gcnew System::Windows::Forms::ListBox());
		this->textBox16 = (gcnew System::Windows::Forms::TextBox());
		this->textBox17 = (gcnew System::Windows::Forms::TextBox());
		this->textBox18 = (gcnew System::Windows::Forms::TextBox());
		this->textBox19 = (gcnew System::Windows::Forms::TextBox());
		this->label27 = (gcnew System::Windows::Forms::Label());
		this->label28 = (gcnew System::Windows::Forms::Label());
		this->label29 = (gcnew System::Windows::Forms::Label());
		this->label30 = (gcnew System::Windows::Forms::Label());
		this->button7 = (gcnew System::Windows::Forms::Button());
		this->button8 = (gcnew System::Windows::Forms::Button());
		this->textBox20 = (gcnew System::Windows::Forms::TextBox());
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox_hmap))->BeginInit();
		this->groupBox2->SuspendLayout();
		this->panel1->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown_hmapSetSE))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown_hmapSetSW))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown_hmapSetNE))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown_hmapSetNW))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->button_magnifier))->BeginInit();
		this->tabControl1->SuspendLayout();
		this->tabPage3->SuspendLayout();
		this->groupBox10->SuspendLayout();
		this->groupBox9->SuspendLayout();
		this->groupBox6->SuspendLayout();
		this->tabPage5->SuspendLayout();
		this->panel_path->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox_path))->BeginInit();
		this->groupBox17->SuspendLayout();
		this->groupBox16->SuspendLayout();
		this->contextMenuStrip_path->SuspendLayout();
		this->groupBox15->SuspendLayout();
		this->groupBox14->SuspendLayout();
		this->groupBox13->SuspendLayout();
		this->tabPage1->SuspendLayout();
		this->groupBox11->SuspendLayout();
		this->panel_hmap->SuspendLayout();
		this->groupBox1->SuspendLayout();
		this->tabPage2->SuspendLayout();
		this->groupBox12->SuspendLayout();
		this->groupBox5->SuspendLayout();
		this->groupBox4->SuspendLayout();
		this->panel_rmap->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox_rmap))->BeginInit();
		this->groupBox3->SuspendLayout();
		this->tabPage6->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox_wmap))->BeginInit();
		this->groupBox18->SuspendLayout();
		this->groupBox21->SuspendLayout();
		this->contextMenuStrip_water->SuspendLayout();
		this->groupBox22->SuspendLayout();
		this->tabPage4->SuspendLayout();
		this->groupBox7->SuspendLayout();
		this->groupBox8->SuspendLayout();
		this->menuStrip_mainMenu->SuspendLayout();
		this->SuspendLayout();
		// 
		// pictureBox_hmap
		// 
		this->pictureBox_hmap->BackColor = System::Drawing::Color::White;
		this->pictureBox_hmap->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		this->pictureBox_hmap->Location = System::Drawing::Point(0, 0);
		this->pictureBox_hmap->MaximumSize = System::Drawing::Size(513, 513);
		this->pictureBox_hmap->MinimumSize = System::Drawing::Size(513, 513);
		this->pictureBox_hmap->Name = L"pictureBox_hmap";
		this->pictureBox_hmap->Size = System::Drawing::Size(513, 513);
		this->pictureBox_hmap->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
		this->pictureBox_hmap->TabIndex = 1;
		this->pictureBox_hmap->TabStop = false;
		this->pictureBox_hmap->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::hmap_tooltip);
		this->pictureBox_hmap->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::hmap_markPoint);
		// 
		// groupBox2
		// 
		this->groupBox2->Controls->Add(this->radioButton4);
		this->groupBox2->Controls->Add(this->radioButton3);
		this->groupBox2->Controls->Add(this->radioButton2);
		this->groupBox2->Controls->Add(this->radioButton1);
		this->groupBox2->Controls->Add(this->panel1);
		this->groupBox2->Controls->Add(this->numericUpDown_hmapSetSE);
		this->groupBox2->Controls->Add(this->numericUpDown_hmapSetSW);
		this->groupBox2->Controls->Add(this->numericUpDown_hmapSetNE);
		this->groupBox2->Controls->Add(this->numericUpDown_hmapSetNW);
		this->groupBox2->Location = System::Drawing::Point(0, 186);
		this->groupBox2->Name = L"groupBox2";
		this->groupBox2->Size = System::Drawing::Size(167, 152);
		this->groupBox2->TabIndex = 3;
		this->groupBox2->TabStop = false;
		this->groupBox2->Text = L"EDIT SELECTION";
		// 
		// radioButton4
		// 
		this->radioButton4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
		this->radioButton4->AutoSize = true;
		this->radioButton4->Enabled = false;
		this->radioButton4->Location = System::Drawing::Point(118, 111);
		this->radioButton4->Name = L"radioButton4";
		this->radioButton4->Size = System::Drawing::Size(14, 13);
		this->radioButton4->TabIndex = 6;
		this->radioButton4->UseVisualStyleBackColor = true;
		// 
		// radioButton3
		// 
		this->radioButton3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
		this->radioButton3->AutoSize = true;
		this->radioButton3->Enabled = false;
		this->radioButton3->Location = System::Drawing::Point(36, 111);
		this->radioButton3->Name = L"radioButton3";
		this->radioButton3->Size = System::Drawing::Size(14, 13);
		this->radioButton3->TabIndex = 5;
		this->radioButton3->UseVisualStyleBackColor = true;
		// 
		// radioButton2
		// 
		this->radioButton2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
		this->radioButton2->AutoSize = true;
		this->radioButton2->Enabled = false;
		this->radioButton2->Location = System::Drawing::Point(118, 42);
		this->radioButton2->Name = L"radioButton2";
		this->radioButton2->Size = System::Drawing::Size(14, 13);
		this->radioButton2->TabIndex = 3;
		this->radioButton2->UseVisualStyleBackColor = true;
		// 
		// radioButton1
		// 
		this->radioButton1->AutoSize = true;
		this->radioButton1->Enabled = false;
		this->radioButton1->Location = System::Drawing::Point(35, 42);
		this->radioButton1->Name = L"radioButton1";
		this->radioButton1->Size = System::Drawing::Size(14, 13);
		this->radioButton1->TabIndex = 2;
		this->radioButton1->UseVisualStyleBackColor = true;
		// 
		// panel1
		// 
		this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
		this->panel1->Controls->Add(this->label4);
		this->panel1->Location = System::Drawing::Point(42, 45);
		this->panel1->Name = L"panel1";
		this->panel1->Size = System::Drawing::Size(82, 75);
		this->panel1->TabIndex = 4;
		// 
		// label4
		// 
		this->label4->Anchor = System::Windows::Forms::AnchorStyles::None;
		this->label4->AutoSize = true;
		this->label4->Location = System::Drawing::Point(15, 30);
		this->label4->Name = L"label4";
		this->label4->Size = System::Drawing::Size(51, 13);
		this->label4->TabIndex = 0;
		this->label4->Text = L"Selection";
		// 
		// numericUpDown_hmapSetSE
		// 
		this->numericUpDown_hmapSetSE->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
		this->numericUpDown_hmapSetSE->DecimalPlaces = 3;
		this->numericUpDown_hmapSetSE->Location = System::Drawing::Point(86, 126);
		this->numericUpDown_hmapSetSE->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {800, 0, 0, 0});
		this->numericUpDown_hmapSetSE->Name = L"numericUpDown_hmapSetSE";
		this->numericUpDown_hmapSetSE->Size = System::Drawing::Size(75, 20);
		this->numericUpDown_hmapSetSE->TabIndex = 8;
		this->numericUpDown_hmapSetSE->ValueChanged += gcnew System::EventHandler(this, &MainWindow::hmap_setHeight);
		// 
		// numericUpDown_hmapSetSW
		// 
		this->numericUpDown_hmapSetSW->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
		this->numericUpDown_hmapSetSW->DecimalPlaces = 3;
		this->numericUpDown_hmapSetSW->Location = System::Drawing::Point(6, 126);
		this->numericUpDown_hmapSetSW->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {800, 0, 0, 0});
		this->numericUpDown_hmapSetSW->Name = L"numericUpDown_hmapSetSW";
		this->numericUpDown_hmapSetSW->Size = System::Drawing::Size(75, 20);
		this->numericUpDown_hmapSetSW->TabIndex = 7;
		this->numericUpDown_hmapSetSW->ValueChanged += gcnew System::EventHandler(this, &MainWindow::hmap_setHeight);
		// 
		// numericUpDown_hmapSetNE
		// 
		this->numericUpDown_hmapSetNE->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
		this->numericUpDown_hmapSetNE->DecimalPlaces = 3;
		this->numericUpDown_hmapSetNE->Location = System::Drawing::Point(84, 19);
		this->numericUpDown_hmapSetNE->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {800, 0, 0, 0});
		this->numericUpDown_hmapSetNE->Name = L"numericUpDown_hmapSetNE";
		this->numericUpDown_hmapSetNE->Size = System::Drawing::Size(75, 20);
		this->numericUpDown_hmapSetNE->TabIndex = 1;
		this->numericUpDown_hmapSetNE->ValueChanged += gcnew System::EventHandler(this, &MainWindow::hmap_setHeight);
		// 
		// numericUpDown_hmapSetNW
		// 
		this->numericUpDown_hmapSetNW->DecimalPlaces = 3;
		this->numericUpDown_hmapSetNW->Location = System::Drawing::Point(6, 19);
		this->numericUpDown_hmapSetNW->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {800, 0, 0, 0});
		this->numericUpDown_hmapSetNW->Name = L"numericUpDown_hmapSetNW";
		this->numericUpDown_hmapSetNW->Size = System::Drawing::Size(75, 20);
		this->numericUpDown_hmapSetNW->TabIndex = 0;
		this->numericUpDown_hmapSetNW->ValueChanged += gcnew System::EventHandler(this, &MainWindow::hmap_setHeight);
		// 
		// progressBar1
		// 
		this->progressBar1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->progressBar1->Location = System::Drawing::Point(4, 569);
		this->progressBar1->Name = L"progressBar1";
		this->progressBar1->Size = System::Drawing::Size(750, 15);
		this->progressBar1->TabIndex = 4;
		// 
		// toolTip
		// 
		this->toolTip->AutomaticDelay = 0;
		this->toolTip->AutoPopDelay = 10000;
		this->toolTip->InitialDelay = 0;
		this->toolTip->ReshowDelay = 0;
		this->toolTip->UseAnimation = false;
		this->toolTip->UseFading = false;
		// 
		// checkBox_FixDat
		// 
		this->checkBox_FixDat->AutoSize = true;
		this->checkBox_FixDat->Location = System::Drawing::Point(89, 29);
		this->checkBox_FixDat->Name = L"checkBox_FixDat";
		this->checkBox_FixDat->Size = System::Drawing::Size(101, 17);
		this->checkBox_FixDat->TabIndex = 6;
		this->checkBox_FixDat->Text = L"Fix bsdata/*.dat";
		this->toolTip->SetToolTip(this->checkBox_FixDat, L"Check this to convert new water dat files to old water dat files.\r\nThe files will" 
			L" be created in the input folder, the original files will get the .BAK extension." 
			L"\r\n");
		this->checkBox_FixDat->UseVisualStyleBackColor = true;
		// 
		// checkBox_FixT2bk
		// 
		this->checkBox_FixT2bk->AutoSize = true;
		this->checkBox_FixT2bk->Location = System::Drawing::Point(202, 29);
		this->checkBox_FixT2bk->Name = L"checkBox_FixT2bk";
		this->checkBox_FixT2bk->Size = System::Drawing::Size(70, 17);
		this->checkBox_FixT2bk->TabIndex = 2;
		this->checkBox_FixT2bk->Text = L"Fix *.t2bk";
		this->toolTip->SetToolTip(this->checkBox_FixT2bk, L"Check this to convert version 6 t2bk maps to version 5 t2bk maps.\r\nThe files will" 
			L" be created in the input folder, the original files will get the .BAK extension." 
			L"");
		this->checkBox_FixT2bk->UseVisualStyleBackColor = true;
		// 
		// checkBox_convertT2mk
		// 
		this->checkBox_convertT2mk->AutoSize = true;
		this->checkBox_convertT2mk->Location = System::Drawing::Point(424, 52);
		this->checkBox_convertT2mk->Name = L"checkBox_convertT2mk";
		this->checkBox_convertT2mk->Size = System::Drawing::Size(118, 17);
		this->checkBox_convertT2mk->TabIndex = 4;
		this->checkBox_convertT2mk->Text = L"Decompress *.t2mk";
		this->toolTip->SetToolTip(this->checkBox_convertT2mk, L"Check this to deflate the *.t2mk files into the selected output directory.\r\nThis " 
			L"option is only for developers, it\'s currently unknown,\r\nif these files are usefu" 
			L"l for any server conversion...");
		this->checkBox_convertT2mk->UseVisualStyleBackColor = true;
		// 
		// checkBox_convertTerrain
		// 
		this->checkBox_convertTerrain->AutoSize = true;
		this->checkBox_convertTerrain->Location = System::Drawing::Point(324, 52);
		this->checkBox_convertTerrain->Name = L"checkBox_convertTerrain";
		this->checkBox_convertTerrain->Size = System::Drawing::Size(94, 17);
		this->checkBox_convertTerrain->TabIndex = 3;
		this->checkBox_convertTerrain->Text = L"Convert *.t2bk";
		this->toolTip->SetToolTip(this->checkBox_convertTerrain, L"Check this to create server hmap files into the selected output directory.");
		this->checkBox_convertTerrain->UseVisualStyleBackColor = true;
		// 
		// checkBox_convertPrecinct
		// 
		this->checkBox_convertPrecinct->AutoSize = true;
		this->checkBox_convertPrecinct->Location = System::Drawing::Point(202, 52);
		this->checkBox_convertPrecinct->Name = L"checkBox_convertPrecinct";
		this->checkBox_convertPrecinct->Size = System::Drawing::Size(118, 17);
		this->checkBox_convertPrecinct->TabIndex = 1;
		this->checkBox_convertPrecinct->Text = L"Convert precinct.clt";
		this->toolTip->SetToolTip(this->checkBox_convertPrecinct, L"Check this to create server precinct files into the selected output directory.");
		this->checkBox_convertPrecinct->UseVisualStyleBackColor = true;
		// 
		// checkBox_convertRegion
		// 
		this->checkBox_convertRegion->AutoSize = true;
		this->checkBox_convertRegion->Location = System::Drawing::Point(89, 52);
		this->checkBox_convertRegion->Name = L"checkBox_convertRegion";
		this->checkBox_convertRegion->Size = System::Drawing::Size(109, 17);
		this->checkBox_convertRegion->TabIndex = 0;
		this->checkBox_convertRegion->Text = L"Convert region.clt";
		this->toolTip->SetToolTip(this->checkBox_convertRegion, L"Check this to create server region files into the selected output directory.");
		this->checkBox_convertRegion->UseVisualStyleBackColor = true;
		// 
		// button_magnifier
		// 
		this->button_magnifier->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
		this->button_magnifier->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
		this->button_magnifier->Cursor = System::Windows::Forms::Cursors::Hand;
		this->button_magnifier->Location = System::Drawing::Point(734, 2);
		this->button_magnifier->Name = L"button_magnifier";
		this->button_magnifier->Size = System::Drawing::Size(18, 18);
		this->button_magnifier->TabIndex = 10;
		this->button_magnifier->TabStop = false;
		this->toolTip->SetToolTip(this->button_magnifier, L"Launch Magnifier");
		this->button_magnifier->Click += gcnew System::EventHandler(this, &MainWindow::magnifier_click);
		// 
		// button_convertExport
		// 
		this->button_convertExport->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
		this->button_convertExport->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		this->button_convertExport->Location = System::Drawing::Point(663, 48);
		this->button_convertExport->Name = L"button_convertExport";
		this->button_convertExport->Size = System::Drawing::Size(75, 23);
		this->button_convertExport->TabIndex = 5;
		this->button_convertExport->Text = L"Export";
		this->toolTip->SetToolTip(this->button_convertExport, L"Start the conversion");
		this->button_convertExport->UseVisualStyleBackColor = true;
		this->button_convertExport->Click += gcnew System::EventHandler(this, &MainWindow::convert_export);
		// 
		// button_convertSave
		// 
		this->button_convertSave->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
		this->button_convertSave->Location = System::Drawing::Point(663, 19);
		this->button_convertSave->Name = L"button_convertSave";
		this->button_convertSave->Size = System::Drawing::Size(75, 23);
		this->button_convertSave->TabIndex = 2;
		this->button_convertSave->Text = L"Browse...";
		this->toolTip->SetToolTip(this->button_convertSave, L"Select the directory where the server side maps folder should be stored");
		this->button_convertSave->UseVisualStyleBackColor = true;
		this->button_convertSave->Click += gcnew System::EventHandler(this, &MainWindow::convert_browse);
		// 
		// button_convertLoad
		// 
		this->button_convertLoad->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
		this->button_convertLoad->Location = System::Drawing::Point(663, 19);
		this->button_convertLoad->Name = L"button_convertLoad";
		this->button_convertLoad->Size = System::Drawing::Size(75, 23);
		this->button_convertLoad->TabIndex = 2;
		this->button_convertLoad->Text = L"Browse...";
		this->toolTip->SetToolTip(this->button_convertLoad, L"Select the root directory for the maps in your client (*\\element\\maps)");
		this->button_convertLoad->UseVisualStyleBackColor = true;
		this->button_convertLoad->Click += gcnew System::EventHandler(this, &MainWindow::convert_browse);
		// 
		// tabControl1
		// 
		this->tabControl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->tabControl1->Appearance = System::Windows::Forms::TabAppearance::FlatButtons;
		this->tabControl1->Controls->Add(this->tabPage3);
		this->tabControl1->Controls->Add(this->tabPage5);
		this->tabControl1->Controls->Add(this->tabPage1);
		this->tabControl1->Controls->Add(this->tabPage2);
		this->tabControl1->Controls->Add(this->tabPage6);
		this->tabControl1->Controls->Add(this->tabPage4);
		this->tabControl1->Location = System::Drawing::Point(0, 24);
		this->tabControl1->Margin = System::Windows::Forms::Padding(0);
		this->tabControl1->Name = L"tabControl1";
		this->tabControl1->Padding = System::Drawing::Point(3, 3);
		this->tabControl1->SelectedIndex = 0;
		this->tabControl1->Size = System::Drawing::Size(758, 545);
		this->tabControl1->TabIndex = 0;
		this->tabControl1->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MainWindow::misc_keyUp);
		this->tabControl1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainWindow::misc_keyDown);
		// 
		// tabPage3
		// 
		this->tabPage3->Controls->Add(this->groupBox10);
		this->tabPage3->Controls->Add(this->groupBox9);
		this->tabPage3->Controls->Add(this->groupBox6);
		this->tabPage3->Location = System::Drawing::Point(4, 25);
		this->tabPage3->Margin = System::Windows::Forms::Padding(0);
		this->tabPage3->Name = L"tabPage3";
		this->tabPage3->Size = System::Drawing::Size(750, 516);
		this->tabPage3->TabIndex = 2;
		this->tabPage3->Text = L"Convert";
		this->tabPage3->UseVisualStyleBackColor = true;
		// 
		// groupBox10
		// 
		this->groupBox10->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->groupBox10->Controls->Add(this->label19);
		this->groupBox10->Controls->Add(this->label18);
		this->groupBox10->Controls->Add(this->checkBox_FixDat);
		this->groupBox10->Controls->Add(this->checkBox_FixT2bk);
		this->groupBox10->Controls->Add(this->checkBox_convertT2mk);
		this->groupBox10->Controls->Add(this->button_convertExport);
		this->groupBox10->Controls->Add(this->checkBox_convertTerrain);
		this->groupBox10->Controls->Add(this->checkBox_convertPrecinct);
		this->groupBox10->Controls->Add(this->checkBox_convertRegion);
		this->groupBox10->Location = System::Drawing::Point(3, 117);
		this->groupBox10->Name = L"groupBox10";
		this->groupBox10->Size = System::Drawing::Size(744, 77);
		this->groupBox10->TabIndex = 2;
		this->groupBox10->TabStop = false;
		this->groupBox10->Text = L"OPTIONS";
		// 
		// label19
		// 
		this->label19->AutoSize = true;
		this->label19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)), 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		this->label19->Location = System::Drawing::Point(6, 30);
		this->label19->Name = L"label19";
		this->label19->Size = System::Drawing::Size(72, 13);
		this->label19->TabIndex = 8;
		this->label19->Text = L"Client Side:";
		// 
		// label18
		// 
		this->label18->AutoSize = true;
		this->label18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)), 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		this->label18->Location = System::Drawing::Point(6, 53);
		this->label18->Name = L"label18";
		this->label18->Size = System::Drawing::Size(77, 13);
		this->label18->TabIndex = 7;
		this->label18->Text = L"Server Side:";
		// 
		// groupBox9
		// 
		this->groupBox9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->groupBox9->Controls->Add(this->button_convertSave);
		this->groupBox9->Controls->Add(this->textBox_convertOutput);
		this->groupBox9->Controls->Add(this->label6);
		this->groupBox9->Location = System::Drawing::Point(3, 60);
		this->groupBox9->Name = L"groupBox9";
		this->groupBox9->Size = System::Drawing::Size(744, 51);
		this->groupBox9->TabIndex = 1;
		this->groupBox9->TabStop = false;
		this->groupBox9->Text = L"OUTPUT FOLDER (*Server Side Fixes)";
		// 
		// textBox_convertOutput
		// 
		this->textBox_convertOutput->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->textBox_convertOutput->Enabled = false;
		this->textBox_convertOutput->Location = System::Drawing::Point(120, 21);
		this->textBox_convertOutput->Name = L"textBox_convertOutput";
		this->textBox_convertOutput->Size = System::Drawing::Size(537, 20);
		this->textBox_convertOutput->TabIndex = 1;
		this->textBox_convertOutput->Text = L"C:\\Users\\Ronny\\Desktop";
		// 
		// label6
		// 
		this->label6->AutoSize = true;
		this->label6->Location = System::Drawing::Point(6, 24);
		this->label6->Name = L"label6";
		this->label6->Size = System::Drawing::Size(108, 13);
		this->label6->TabIndex = 0;
		this->label6->Text = L"Destination Directory:";
		// 
		// groupBox6
		// 
		this->groupBox6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->groupBox6->Controls->Add(this->button_convertLoad);
		this->groupBox6->Controls->Add(this->textBox_convertInput);
		this->groupBox6->Controls->Add(this->label2);
		this->groupBox6->Location = System::Drawing::Point(3, 3);
		this->groupBox6->Name = L"groupBox6";
		this->groupBox6->Size = System::Drawing::Size(744, 51);
		this->groupBox6->TabIndex = 0;
		this->groupBox6->TabStop = false;
		this->groupBox6->Text = L"INPUT FOLDER (*Client Side Fixes)";
		// 
		// textBox_convertInput
		// 
		this->textBox_convertInput->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->textBox_convertInput->Enabled = false;
		this->textBox_convertInput->Location = System::Drawing::Point(119, 21);
		this->textBox_convertInput->Name = L"textBox_convertInput";
		this->textBox_convertInput->Size = System::Drawing::Size(538, 20);
		this->textBox_convertInput->TabIndex = 1;
		this->textBox_convertInput->Text = L"E:\\- GAMES -\\Perfect World International\\element\\maps";
		// 
		// label2
		// 
		this->label2->AutoSize = true;
		this->label2->Location = System::Drawing::Point(6, 24);
		this->label2->Name = L"label2";
		this->label2->Size = System::Drawing::Size(110, 13);
		this->label2->TabIndex = 0;
		this->label2->Text = L"Client Maps Directory:";
		// 
		// tabPage5
		// 
		this->tabPage5->Controls->Add(this->panel_path);
		this->tabPage5->Controls->Add(this->groupBox17);
		this->tabPage5->Controls->Add(this->groupBox16);
		this->tabPage5->Controls->Add(this->groupBox15);
		this->tabPage5->Controls->Add(this->groupBox14);
		this->tabPage5->Controls->Add(this->groupBox13);
		this->tabPage5->Location = System::Drawing::Point(4, 25);
		this->tabPage5->Margin = System::Windows::Forms::Padding(0);
		this->tabPage5->Name = L"tabPage5";
		this->tabPage5->Size = System::Drawing::Size(750, 516);
		this->tabPage5->TabIndex = 4;
		this->tabPage5->Text = L"path.sev";
		this->tabPage5->UseVisualStyleBackColor = true;
		// 
		// panel_path
		// 
		this->panel_path->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->panel_path->AutoScroll = true;
		this->panel_path->BackColor = System::Drawing::SystemColors::AppWorkspace;
		this->panel_path->Controls->Add(this->pictureBox_path);
		this->panel_path->Location = System::Drawing::Point(281, 81);
		this->panel_path->Name = L"panel_path";
		this->panel_path->Size = System::Drawing::Size(469, 435);
		this->panel_path->TabIndex = 9;
		// 
		// pictureBox_path
		// 
		this->pictureBox_path->BackColor = System::Drawing::Color::White;
		this->pictureBox_path->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
		this->pictureBox_path->Location = System::Drawing::Point(0, 0);
		this->pictureBox_path->MinimumSize = System::Drawing::Size(512, 512);
		this->pictureBox_path->Name = L"pictureBox_path";
		this->pictureBox_path->Size = System::Drawing::Size(1024, 1024);
		this->pictureBox_path->TabIndex = 2;
		this->pictureBox_path->TabStop = false;
		this->pictureBox_path->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::path_tooltip);
		// 
		// groupBox17
		// 
		this->groupBox17->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->groupBox17->Controls->Add(this->comboBox_pathBackground);
		this->groupBox17->Controls->Add(this->checkBox_pathBackground);
		this->groupBox17->Location = System::Drawing::Point(281, 0);
		this->groupBox17->Name = L"groupBox17";
		this->groupBox17->Size = System::Drawing::Size(469, 75);
		this->groupBox17->TabIndex = 8;
		this->groupBox17->TabStop = false;
		this->groupBox17->Text = L"BACKGROUND";
		// 
		// comboBox_pathBackground
		// 
		this->comboBox_pathBackground->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->comboBox_pathBackground->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
		this->comboBox_pathBackground->FormattingEnabled = true;
		this->comboBox_pathBackground->Location = System::Drawing::Point(6, 42);
		this->comboBox_pathBackground->Name = L"comboBox_pathBackground";
		this->comboBox_pathBackground->Size = System::Drawing::Size(455, 21);
		this->comboBox_pathBackground->TabIndex = 3;
		this->comboBox_pathBackground->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::path_switchBackground);
		// 
		// checkBox_pathBackground
		// 
		this->checkBox_pathBackground->AutoSize = true;
		this->checkBox_pathBackground->Checked = true;
		this->checkBox_pathBackground->CheckState = System::Windows::Forms::CheckState::Checked;
		this->checkBox_pathBackground->Location = System::Drawing::Point(6, 19);
		this->checkBox_pathBackground->Name = L"checkBox_pathBackground";
		this->checkBox_pathBackground->Size = System::Drawing::Size(120, 17);
		this->checkBox_pathBackground->TabIndex = 2;
		this->checkBox_pathBackground->Text = L"Toggle Background";
		this->checkBox_pathBackground->UseVisualStyleBackColor = true;
		this->checkBox_pathBackground->Click += gcnew System::EventHandler(this, &MainWindow::path_switchBackground);
		// 
		// groupBox16
		// 
		this->groupBox16->Controls->Add(this->textBox_pathSegmentLength);
		this->groupBox16->Controls->Add(this->textBox_pathSegmentEnd);
		this->groupBox16->Controls->Add(this->textBox_pathSegmentStart);
		this->groupBox16->Controls->Add(this->label17);
		this->groupBox16->Controls->Add(this->label16);
		this->groupBox16->Controls->Add(this->label14);
		this->groupBox16->Controls->Add(this->textBox_pathSegmentTailZ);
		this->groupBox16->Controls->Add(this->textBox_pathSegmentTailAlt);
		this->groupBox16->Controls->Add(this->label7);
		this->groupBox16->Controls->Add(this->textBox_pathSegmentTailX);
		this->groupBox16->Controls->Add(this->textBox_pathSegmentHeadX);
		this->groupBox16->Controls->Add(this->label8);
		this->groupBox16->Controls->Add(this->textBox_pathSegmentHeadAlt);
		this->groupBox16->Controls->Add(this->textBox_pathSegmentHeadZ);
		this->groupBox16->Controls->Add(this->listBox_pathSegments);
		this->groupBox16->Location = System::Drawing::Point(0, 324);
		this->groupBox16->Name = L"groupBox16";
		this->groupBox16->Size = System::Drawing::Size(275, 186);
		this->groupBox16->TabIndex = 3;
		this->groupBox16->TabStop = false;
		this->groupBox16->Text = L"SEGMENTS";
		// 
		// textBox_pathSegmentLength
		// 
		this->textBox_pathSegmentLength->Enabled = false;
		this->textBox_pathSegmentLength->Location = System::Drawing::Point(206, 160);
		this->textBox_pathSegmentLength->Name = L"textBox_pathSegmentLength";
		this->textBox_pathSegmentLength->Size = System::Drawing::Size(63, 20);
		this->textBox_pathSegmentLength->TabIndex = 38;
		this->textBox_pathSegmentLength->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_pathSegmentLength->Leave += gcnew System::EventHandler(this, &MainWindow::path_editValue);
		// 
		// textBox_pathSegmentEnd
		// 
		this->textBox_pathSegmentEnd->Location = System::Drawing::Point(206, 134);
		this->textBox_pathSegmentEnd->Name = L"textBox_pathSegmentEnd";
		this->textBox_pathSegmentEnd->Size = System::Drawing::Size(63, 20);
		this->textBox_pathSegmentEnd->TabIndex = 37;
		this->textBox_pathSegmentEnd->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_pathSegmentEnd->Leave += gcnew System::EventHandler(this, &MainWindow::path_editValue);
		// 
		// textBox_pathSegmentStart
		// 
		this->textBox_pathSegmentStart->Location = System::Drawing::Point(206, 108);
		this->textBox_pathSegmentStart->Name = L"textBox_pathSegmentStart";
		this->textBox_pathSegmentStart->Size = System::Drawing::Size(63, 20);
		this->textBox_pathSegmentStart->TabIndex = 36;
		this->textBox_pathSegmentStart->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_pathSegmentStart->Leave += gcnew System::EventHandler(this, &MainWindow::path_editValue);
		// 
		// label17
		// 
		this->label17->AutoSize = true;
		this->label17->Location = System::Drawing::Point(65, 163);
		this->label17->Name = L"label17";
		this->label17->Size = System::Drawing::Size(88, 13);
		this->label17->TabIndex = 35;
		this->label17->Text = L"Segment Length:";
		// 
		// label16
		// 
		this->label16->AutoSize = true;
		this->label16->Location = System::Drawing::Point(65, 137);
		this->label16->Name = L"label16";
		this->label16->Size = System::Drawing::Size(70, 13);
		this->label16->TabIndex = 34;
		this->label16->Text = L"End Point ID:";
		// 
		// label14
		// 
		this->label14->AutoSize = true;
		this->label14->Location = System::Drawing::Point(65, 111);
		this->label14->Name = L"label14";
		this->label14->Size = System::Drawing::Size(73, 13);
		this->label14->TabIndex = 33;
		this->label14->Text = L"Start Point ID:";
		// 
		// textBox_pathSegmentTailZ
		// 
		this->textBox_pathSegmentTailZ->Location = System::Drawing::Point(204, 74);
		this->textBox_pathSegmentTailZ->Name = L"textBox_pathSegmentTailZ";
		this->textBox_pathSegmentTailZ->Size = System::Drawing::Size(63, 20);
		this->textBox_pathSegmentTailZ->TabIndex = 32;
		this->textBox_pathSegmentTailZ->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_pathSegmentTailZ->Leave += gcnew System::EventHandler(this, &MainWindow::path_editValue);
		// 
		// textBox_pathSegmentTailAlt
		// 
		this->textBox_pathSegmentTailAlt->Location = System::Drawing::Point(135, 74);
		this->textBox_pathSegmentTailAlt->Name = L"textBox_pathSegmentTailAlt";
		this->textBox_pathSegmentTailAlt->Size = System::Drawing::Size(63, 20);
		this->textBox_pathSegmentTailAlt->TabIndex = 31;
		this->textBox_pathSegmentTailAlt->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_pathSegmentTailAlt->Leave += gcnew System::EventHandler(this, &MainWindow::path_editValue);
		// 
		// label7
		// 
		this->label7->AutoSize = true;
		this->label7->Location = System::Drawing::Point(63, 19);
		this->label7->Name = L"label7";
		this->label7->Size = System::Drawing::Size(149, 13);
		this->label7->TabIndex = 25;
		this->label7->Text = L"Control Point 1 (X, Altitude, Z):";
		// 
		// textBox_pathSegmentTailX
		// 
		this->textBox_pathSegmentTailX->Location = System::Drawing::Point(66, 74);
		this->textBox_pathSegmentTailX->Name = L"textBox_pathSegmentTailX";
		this->textBox_pathSegmentTailX->Size = System::Drawing::Size(63, 20);
		this->textBox_pathSegmentTailX->TabIndex = 30;
		this->textBox_pathSegmentTailX->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_pathSegmentTailX->Leave += gcnew System::EventHandler(this, &MainWindow::path_editValue);
		// 
		// textBox_pathSegmentHeadX
		// 
		this->textBox_pathSegmentHeadX->Location = System::Drawing::Point(66, 35);
		this->textBox_pathSegmentHeadX->Name = L"textBox_pathSegmentHeadX";
		this->textBox_pathSegmentHeadX->Size = System::Drawing::Size(63, 20);
		this->textBox_pathSegmentHeadX->TabIndex = 26;
		this->textBox_pathSegmentHeadX->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_pathSegmentHeadX->Leave += gcnew System::EventHandler(this, &MainWindow::path_editValue);
		// 
		// label8
		// 
		this->label8->AutoSize = true;
		this->label8->Location = System::Drawing::Point(63, 58);
		this->label8->Name = L"label8";
		this->label8->Size = System::Drawing::Size(149, 13);
		this->label8->TabIndex = 29;
		this->label8->Text = L"Control Point 2 (X, Altitude, Z):";
		// 
		// textBox_pathSegmentHeadAlt
		// 
		this->textBox_pathSegmentHeadAlt->Location = System::Drawing::Point(135, 35);
		this->textBox_pathSegmentHeadAlt->Name = L"textBox_pathSegmentHeadAlt";
		this->textBox_pathSegmentHeadAlt->Size = System::Drawing::Size(63, 20);
		this->textBox_pathSegmentHeadAlt->TabIndex = 27;
		this->textBox_pathSegmentHeadAlt->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_pathSegmentHeadAlt->Leave += gcnew System::EventHandler(this, &MainWindow::path_editValue);
		// 
		// textBox_pathSegmentHeadZ
		// 
		this->textBox_pathSegmentHeadZ->Location = System::Drawing::Point(204, 35);
		this->textBox_pathSegmentHeadZ->Name = L"textBox_pathSegmentHeadZ";
		this->textBox_pathSegmentHeadZ->Size = System::Drawing::Size(63, 20);
		this->textBox_pathSegmentHeadZ->TabIndex = 28;
		this->textBox_pathSegmentHeadZ->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_pathSegmentHeadZ->Leave += gcnew System::EventHandler(this, &MainWindow::path_editValue);
		// 
		// listBox_pathSegments
		// 
		this->listBox_pathSegments->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left));
		this->listBox_pathSegments->ContextMenuStrip = this->contextMenuStrip_path;
		this->listBox_pathSegments->FormattingEnabled = true;
		this->listBox_pathSegments->Location = System::Drawing::Point(6, 19);
		this->listBox_pathSegments->Name = L"listBox_pathSegments";
		this->listBox_pathSegments->Size = System::Drawing::Size(56, 160);
		this->listBox_pathSegments->TabIndex = 14;
		this->listBox_pathSegments->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::path_changeSegment);
		// 
		// contextMenuStrip_path
		// 
		this->contextMenuStrip_path->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->addToolStripMenuItem, 
			this->deleteSelectedToolStripMenuItem});
		this->contextMenuStrip_path->Name = L"contextMenuStrip_path";
		this->contextMenuStrip_path->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
		this->contextMenuStrip_path->ShowImageMargin = false;
		this->contextMenuStrip_path->Size = System::Drawing::Size(81, 48);
		// 
		// addToolStripMenuItem
		// 
		this->addToolStripMenuItem->Name = L"addToolStripMenuItem";
		this->addToolStripMenuItem->Size = System::Drawing::Size(80, 22);
		this->addToolStripMenuItem->Text = L"Add";
		this->addToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::path_add);
		// 
		// deleteSelectedToolStripMenuItem
		// 
		this->deleteSelectedToolStripMenuItem->Name = L"deleteSelectedToolStripMenuItem";
		this->deleteSelectedToolStripMenuItem->Size = System::Drawing::Size(80, 22);
		this->deleteSelectedToolStripMenuItem->Text = L"Delete";
		this->deleteSelectedToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::path_delete);
		// 
		// groupBox15
		// 
		this->groupBox15->Controls->Add(this->textBox_pathDirectionZ);
		this->groupBox15->Controls->Add(this->listBox_pathPoints);
		this->groupBox15->Controls->Add(this->textBox_pathDirectionAlt);
		this->groupBox15->Controls->Add(this->label13);
		this->groupBox15->Controls->Add(this->textBox_pathDirectionX);
		this->groupBox15->Controls->Add(this->textBox_pathPointX);
		this->groupBox15->Controls->Add(this->label15);
		this->groupBox15->Controls->Add(this->textBox_pathPointAlt);
		this->groupBox15->Controls->Add(this->textBox_pathPointZ);
		this->groupBox15->Location = System::Drawing::Point(0, 210);
		this->groupBox15->Name = L"groupBox15";
		this->groupBox15->Size = System::Drawing::Size(275, 108);
		this->groupBox15->TabIndex = 2;
		this->groupBox15->TabStop = false;
		this->groupBox15->Text = L"POINTS";
		// 
		// textBox_pathDirectionZ
		// 
		this->textBox_pathDirectionZ->Location = System::Drawing::Point(204, 81);
		this->textBox_pathDirectionZ->Name = L"textBox_pathDirectionZ";
		this->textBox_pathDirectionZ->Size = System::Drawing::Size(63, 20);
		this->textBox_pathDirectionZ->TabIndex = 24;
		this->textBox_pathDirectionZ->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_pathDirectionZ->Leave += gcnew System::EventHandler(this, &MainWindow::path_editValue);
		// 
		// listBox_pathPoints
		// 
		this->listBox_pathPoints->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left));
		this->listBox_pathPoints->ContextMenuStrip = this->contextMenuStrip_path;
		this->listBox_pathPoints->FormattingEnabled = true;
		this->listBox_pathPoints->Location = System::Drawing::Point(6, 19);
		this->listBox_pathPoints->Name = L"listBox_pathPoints";
		this->listBox_pathPoints->Size = System::Drawing::Size(56, 82);
		this->listBox_pathPoints->TabIndex = 13;
		this->listBox_pathPoints->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::path_changePoint);
		// 
		// textBox_pathDirectionAlt
		// 
		this->textBox_pathDirectionAlt->Location = System::Drawing::Point(135, 81);
		this->textBox_pathDirectionAlt->Name = L"textBox_pathDirectionAlt";
		this->textBox_pathDirectionAlt->Size = System::Drawing::Size(63, 20);
		this->textBox_pathDirectionAlt->TabIndex = 23;
		this->textBox_pathDirectionAlt->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_pathDirectionAlt->Leave += gcnew System::EventHandler(this, &MainWindow::path_editValue);
		// 
		// label13
		// 
		this->label13->AutoSize = true;
		this->label13->Location = System::Drawing::Point(63, 19);
		this->label13->Name = L"label13";
		this->label13->Size = System::Drawing::Size(104, 13);
		this->label13->TabIndex = 15;
		this->label13->Text = L"Point (X, Altitude, Z):";
		// 
		// textBox_pathDirectionX
		// 
		this->textBox_pathDirectionX->Location = System::Drawing::Point(66, 81);
		this->textBox_pathDirectionX->Name = L"textBox_pathDirectionX";
		this->textBox_pathDirectionX->Size = System::Drawing::Size(63, 20);
		this->textBox_pathDirectionX->TabIndex = 22;
		this->textBox_pathDirectionX->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_pathDirectionX->Leave += gcnew System::EventHandler(this, &MainWindow::path_editValue);
		// 
		// textBox_pathPointX
		// 
		this->textBox_pathPointX->Location = System::Drawing::Point(66, 35);
		this->textBox_pathPointX->Name = L"textBox_pathPointX";
		this->textBox_pathPointX->Size = System::Drawing::Size(63, 20);
		this->textBox_pathPointX->TabIndex = 17;
		this->textBox_pathPointX->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_pathPointX->Leave += gcnew System::EventHandler(this, &MainWindow::path_editValue);
		// 
		// label15
		// 
		this->label15->AutoSize = true;
		this->label15->Location = System::Drawing::Point(63, 65);
		this->label15->Name = L"label15";
		this->label15->Size = System::Drawing::Size(122, 13);
		this->label15->TabIndex = 21;
		this->label15->Text = L"Direction (X, Altitude, Z):";
		// 
		// textBox_pathPointAlt
		// 
		this->textBox_pathPointAlt->Location = System::Drawing::Point(135, 35);
		this->textBox_pathPointAlt->Name = L"textBox_pathPointAlt";
		this->textBox_pathPointAlt->Size = System::Drawing::Size(63, 20);
		this->textBox_pathPointAlt->TabIndex = 19;
		this->textBox_pathPointAlt->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_pathPointAlt->Leave += gcnew System::EventHandler(this, &MainWindow::path_editValue);
		// 
		// textBox_pathPointZ
		// 
		this->textBox_pathPointZ->Location = System::Drawing::Point(204, 35);
		this->textBox_pathPointZ->Name = L"textBox_pathPointZ";
		this->textBox_pathPointZ->Size = System::Drawing::Size(63, 20);
		this->textBox_pathPointZ->TabIndex = 20;
		this->textBox_pathPointZ->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_pathPointZ->Leave += gcnew System::EventHandler(this, &MainWindow::path_editValue);
		// 
		// groupBox14
		// 
		this->groupBox14->Controls->Add(this->listBox_pathCollection);
		this->groupBox14->Controls->Add(this->textBox_pathSeperator2);
		this->groupBox14->Controls->Add(this->textBox_pathSeperator1);
		this->groupBox14->Controls->Add(this->textBox_pathUnknown1);
		this->groupBox14->Controls->Add(this->textBox_pathID);
		this->groupBox14->Controls->Add(this->label12);
		this->groupBox14->Controls->Add(this->label11);
		this->groupBox14->Controls->Add(this->label10);
		this->groupBox14->Controls->Add(this->label9);
		this->groupBox14->Location = System::Drawing::Point(0, 81);
		this->groupBox14->Name = L"groupBox14";
		this->groupBox14->Size = System::Drawing::Size(275, 123);
		this->groupBox14->TabIndex = 1;
		this->groupBox14->TabStop = false;
		this->groupBox14->Text = L"PATH";
		// 
		// listBox_pathCollection
		// 
		this->listBox_pathCollection->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left));
		this->listBox_pathCollection->ContextMenuStrip = this->contextMenuStrip_path;
		this->listBox_pathCollection->FormattingEnabled = true;
		this->listBox_pathCollection->Location = System::Drawing::Point(6, 19);
		this->listBox_pathCollection->Name = L"listBox_pathCollection";
		this->listBox_pathCollection->Size = System::Drawing::Size(56, 95);
		this->listBox_pathCollection->TabIndex = 14;
		this->listBox_pathCollection->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::path_change);
		// 
		// textBox_pathSeperator2
		// 
		this->textBox_pathSeperator2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
		this->textBox_pathSeperator2->Location = System::Drawing::Point(206, 97);
		this->textBox_pathSeperator2->Name = L"textBox_pathSeperator2";
		this->textBox_pathSeperator2->Size = System::Drawing::Size(63, 20);
		this->textBox_pathSeperator2->TabIndex = 10;
		this->textBox_pathSeperator2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_pathSeperator2->Leave += gcnew System::EventHandler(this, &MainWindow::path_editValue);
		// 
		// textBox_pathSeperator1
		// 
		this->textBox_pathSeperator1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
		this->textBox_pathSeperator1->Location = System::Drawing::Point(206, 71);
		this->textBox_pathSeperator1->Name = L"textBox_pathSeperator1";
		this->textBox_pathSeperator1->Size = System::Drawing::Size(63, 20);
		this->textBox_pathSeperator1->TabIndex = 8;
		this->textBox_pathSeperator1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_pathSeperator1->Leave += gcnew System::EventHandler(this, &MainWindow::path_editValue);
		// 
		// textBox_pathUnknown1
		// 
		this->textBox_pathUnknown1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
		this->textBox_pathUnknown1->Location = System::Drawing::Point(206, 45);
		this->textBox_pathUnknown1->Name = L"textBox_pathUnknown1";
		this->textBox_pathUnknown1->Size = System::Drawing::Size(63, 20);
		this->textBox_pathUnknown1->TabIndex = 6;
		this->textBox_pathUnknown1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_pathUnknown1->Leave += gcnew System::EventHandler(this, &MainWindow::path_editValue);
		// 
		// textBox_pathID
		// 
		this->textBox_pathID->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
		this->textBox_pathID->Location = System::Drawing::Point(206, 19);
		this->textBox_pathID->Name = L"textBox_pathID";
		this->textBox_pathID->Size = System::Drawing::Size(63, 20);
		this->textBox_pathID->TabIndex = 4;
		this->textBox_pathID->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_pathID->Leave += gcnew System::EventHandler(this, &MainWindow::path_editValue);
		// 
		// label12
		// 
		this->label12->AutoSize = true;
		this->label12->Location = System::Drawing::Point(68, 100);
		this->label12->Name = L"label12";
		this->label12->Size = System::Drawing::Size(65, 13);
		this->label12->TabIndex = 9;
		this->label12->Text = L"Unknown 3:";
		// 
		// label11
		// 
		this->label11->AutoSize = true;
		this->label11->Location = System::Drawing::Point(68, 74);
		this->label11->Name = L"label11";
		this->label11->Size = System::Drawing::Size(65, 13);
		this->label11->TabIndex = 7;
		this->label11->Text = L"Unknown 2:";
		// 
		// label10
		// 
		this->label10->AutoSize = true;
		this->label10->Location = System::Drawing::Point(68, 22);
		this->label10->Name = L"label10";
		this->label10->Size = System::Drawing::Size(21, 13);
		this->label10->TabIndex = 3;
		this->label10->Text = L"ID:";
		// 
		// label9
		// 
		this->label9->AutoSize = true;
		this->label9->Location = System::Drawing::Point(68, 48);
		this->label9->Name = L"label9";
		this->label9->Size = System::Drawing::Size(65, 13);
		this->label9->TabIndex = 5;
		this->label9->Text = L"Unknown 1:";
		// 
		// groupBox13
		// 
		this->groupBox13->Controls->Add(this->button_pathSave);
		this->groupBox13->Controls->Add(this->button_pathLoad);
		this->groupBox13->Controls->Add(this->textBox_pathFile);
		this->groupBox13->Location = System::Drawing::Point(0, 0);
		this->groupBox13->Name = L"groupBox13";
		this->groupBox13->Size = System::Drawing::Size(275, 75);
		this->groupBox13->TabIndex = 0;
		this->groupBox13->TabStop = false;
		this->groupBox13->Text = L"FILE";
		// 
		// button_pathSave
		// 
		this->button_pathSave->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
		this->button_pathSave->Location = System::Drawing::Point(141, 45);
		this->button_pathSave->Name = L"button_pathSave";
		this->button_pathSave->Size = System::Drawing::Size(128, 23);
		this->button_pathSave->TabIndex = 2;
		this->button_pathSave->Text = L"Save";
		this->button_pathSave->UseVisualStyleBackColor = true;
		this->button_pathSave->Click += gcnew System::EventHandler(this, &MainWindow::path_save);
		// 
		// button_pathLoad
		// 
		this->button_pathLoad->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(0)));
		this->button_pathLoad->Location = System::Drawing::Point(6, 45);
		this->button_pathLoad->Name = L"button_pathLoad";
		this->button_pathLoad->Size = System::Drawing::Size(128, 23);
		this->button_pathLoad->TabIndex = 1;
		this->button_pathLoad->Text = L"Load...";
		this->button_pathLoad->UseVisualStyleBackColor = true;
		this->button_pathLoad->Click += gcnew System::EventHandler(this, &MainWindow::path_load);
		// 
		// textBox_pathFile
		// 
		this->textBox_pathFile->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->textBox_pathFile->Enabled = false;
		this->textBox_pathFile->Location = System::Drawing::Point(6, 19);
		this->textBox_pathFile->Name = L"textBox_pathFile";
		this->textBox_pathFile->Size = System::Drawing::Size(263, 20);
		this->textBox_pathFile->TabIndex = 0;
		// 
		// tabPage1
		// 
		this->tabPage1->Controls->Add(this->groupBox11);
		this->tabPage1->Controls->Add(this->panel_hmap);
		this->tabPage1->Controls->Add(this->groupBox1);
		this->tabPage1->Controls->Add(this->groupBox2);
		this->tabPage1->Location = System::Drawing::Point(4, 25);
		this->tabPage1->Margin = System::Windows::Forms::Padding(0);
		this->tabPage1->Name = L"tabPage1";
		this->tabPage1->Size = System::Drawing::Size(750, 516);
		this->tabPage1->TabIndex = 0;
		this->tabPage1->Text = L"*.hmap";
		this->tabPage1->UseVisualStyleBackColor = true;
		// 
		// groupBox11
		// 
		this->groupBox11->Controls->Add(this->comboBox_hmapBackground);
		this->groupBox11->Controls->Add(this->checkBox_hmapBackground);
		this->groupBox11->Location = System::Drawing::Point(0, 110);
		this->groupBox11->Name = L"groupBox11";
		this->groupBox11->Size = System::Drawing::Size(167, 70);
		this->groupBox11->TabIndex = 7;
		this->groupBox11->TabStop = false;
		this->groupBox11->Text = L"BACKGROUND";
		// 
		// comboBox_hmapBackground
		// 
		this->comboBox_hmapBackground->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
		this->comboBox_hmapBackground->FormattingEnabled = true;
		this->comboBox_hmapBackground->Location = System::Drawing::Point(6, 42);
		this->comboBox_hmapBackground->Name = L"comboBox_hmapBackground";
		this->comboBox_hmapBackground->Size = System::Drawing::Size(155, 21);
		this->comboBox_hmapBackground->TabIndex = 3;
		this->comboBox_hmapBackground->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::hmap_changeBackground);
		// 
		// checkBox_hmapBackground
		// 
		this->checkBox_hmapBackground->AutoSize = true;
		this->checkBox_hmapBackground->Location = System::Drawing::Point(6, 19);
		this->checkBox_hmapBackground->Name = L"checkBox_hmapBackground";
		this->checkBox_hmapBackground->Size = System::Drawing::Size(120, 17);
		this->checkBox_hmapBackground->TabIndex = 2;
		this->checkBox_hmapBackground->Text = L"Toggle Background";
		this->checkBox_hmapBackground->UseVisualStyleBackColor = true;
		this->checkBox_hmapBackground->Click += gcnew System::EventHandler(this, &MainWindow::hmap_switchBackground);
		// 
		// panel_hmap
		// 
		this->panel_hmap->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->panel_hmap->AutoScroll = true;
		this->panel_hmap->BackColor = System::Drawing::SystemColors::AppWorkspace;
		this->panel_hmap->Controls->Add(this->pictureBox_hmap);
		this->panel_hmap->Location = System::Drawing::Point(173, 0);
		this->panel_hmap->Name = L"panel_hmap";
		this->panel_hmap->Size = System::Drawing::Size(513, 513);
		this->panel_hmap->TabIndex = 7;
		// 
		// groupBox1
		// 
		this->groupBox1->Controls->Add(this->button4);
		this->groupBox1->Controls->Add(this->button1);
		this->groupBox1->Controls->Add(this->button_hmapSave);
		this->groupBox1->Controls->Add(this->button_hmapLoad);
		this->groupBox1->Controls->Add(this->textBox_hmapFile);
		this->groupBox1->Location = System::Drawing::Point(0, 0);
		this->groupBox1->Name = L"groupBox1";
		this->groupBox1->Size = System::Drawing::Size(167, 104);
		this->groupBox1->TabIndex = 6;
		this->groupBox1->TabStop = false;
		this->groupBox1->Text = L"FILE";
		// 
		// button4
		// 
		this->button4->Location = System::Drawing::Point(87, 74);
		this->button4->Name = L"button4";
		this->button4->Size = System::Drawing::Size(74, 23);
		this->button4->TabIndex = 4;
		this->button4->Text = L"Export VG";
		this->button4->UseVisualStyleBackColor = true;
		this->button4->Click += gcnew System::EventHandler(this, &MainWindow::hmap_export);
		// 
		// button1
		// 
		this->button1->Location = System::Drawing::Point(6, 74);
		this->button1->Name = L"button1";
		this->button1->Size = System::Drawing::Size(74, 23);
		this->button1->TabIndex = 3;
		this->button1->Text = L"Import VG";
		this->button1->UseVisualStyleBackColor = true;
		this->button1->Click += gcnew System::EventHandler(this, &MainWindow::hmap_import);
		// 
		// button_hmapSave
		// 
		this->button_hmapSave->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
		this->button_hmapSave->Location = System::Drawing::Point(87, 45);
		this->button_hmapSave->Name = L"button_hmapSave";
		this->button_hmapSave->Size = System::Drawing::Size(74, 23);
		this->button_hmapSave->TabIndex = 2;
		this->button_hmapSave->Text = L"Save";
		this->button_hmapSave->UseVisualStyleBackColor = true;
		this->button_hmapSave->Click += gcnew System::EventHandler(this, &MainWindow::hmap_save);
		// 
		// button_hmapLoad
		// 
		this->button_hmapLoad->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(0)));
		this->button_hmapLoad->Location = System::Drawing::Point(6, 45);
		this->button_hmapLoad->Name = L"button_hmapLoad";
		this->button_hmapLoad->Size = System::Drawing::Size(74, 23);
		this->button_hmapLoad->TabIndex = 1;
		this->button_hmapLoad->Text = L"Load...";
		this->button_hmapLoad->UseVisualStyleBackColor = true;
		this->button_hmapLoad->Click += gcnew System::EventHandler(this, &MainWindow::hmap_load);
		// 
		// textBox_hmapFile
		// 
		this->textBox_hmapFile->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->textBox_hmapFile->Enabled = false;
		this->textBox_hmapFile->Location = System::Drawing::Point(6, 19);
		this->textBox_hmapFile->Name = L"textBox_hmapFile";
		this->textBox_hmapFile->Size = System::Drawing::Size(155, 20);
		this->textBox_hmapFile->TabIndex = 0;
		// 
		// tabPage2
		// 
		this->tabPage2->Controls->Add(this->groupBox12);
		this->tabPage2->Controls->Add(this->groupBox5);
		this->tabPage2->Controls->Add(this->groupBox4);
		this->tabPage2->Controls->Add(this->panel_rmap);
		this->tabPage2->Controls->Add(this->groupBox3);
		this->tabPage2->Location = System::Drawing::Point(4, 25);
		this->tabPage2->Margin = System::Windows::Forms::Padding(0);
		this->tabPage2->Name = L"tabPage2";
		this->tabPage2->Size = System::Drawing::Size(750, 516);
		this->tabPage2->TabIndex = 1;
		this->tabPage2->Text = L"*.rmap";
		this->tabPage2->UseVisualStyleBackColor = true;
		// 
		// groupBox12
		// 
		this->groupBox12->Controls->Add(this->comboBox_rmapBackground);
		this->groupBox12->Controls->Add(this->checkBox_rmapBackground);
		this->groupBox12->Location = System::Drawing::Point(0, 110);
		this->groupBox12->Name = L"groupBox12";
		this->groupBox12->Size = System::Drawing::Size(167, 70);
		this->groupBox12->TabIndex = 11;
		this->groupBox12->TabStop = false;
		this->groupBox12->Text = L"BACKGROUND";
		// 
		// comboBox_rmapBackground
		// 
		this->comboBox_rmapBackground->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
		this->comboBox_rmapBackground->FormattingEnabled = true;
		this->comboBox_rmapBackground->Location = System::Drawing::Point(6, 42);
		this->comboBox_rmapBackground->Name = L"comboBox_rmapBackground";
		this->comboBox_rmapBackground->Size = System::Drawing::Size(155, 21);
		this->comboBox_rmapBackground->TabIndex = 3;
		this->comboBox_rmapBackground->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::rmap_changeBackground);
		// 
		// checkBox_rmapBackground
		// 
		this->checkBox_rmapBackground->AutoSize = true;
		this->checkBox_rmapBackground->Location = System::Drawing::Point(6, 19);
		this->checkBox_rmapBackground->Name = L"checkBox_rmapBackground";
		this->checkBox_rmapBackground->Size = System::Drawing::Size(120, 17);
		this->checkBox_rmapBackground->TabIndex = 2;
		this->checkBox_rmapBackground->Text = L"Toggle Background";
		this->checkBox_rmapBackground->UseVisualStyleBackColor = true;
		this->checkBox_rmapBackground->Click += gcnew System::EventHandler(this, &MainWindow::rmap_switchBackground);
		// 
		// groupBox5
		// 
		this->groupBox5->Controls->Add(this->radioButton_rmapLines);
		this->groupBox5->Controls->Add(this->radioButton_rmapPLine);
		this->groupBox5->Controls->Add(this->radioButton_rmapPFill);
		this->groupBox5->Location = System::Drawing::Point(0, 186);
		this->groupBox5->Name = L"groupBox5";
		this->groupBox5->Size = System::Drawing::Size(167, 89);
		this->groupBox5->TabIndex = 10;
		this->groupBox5->TabStop = false;
		this->groupBox5->Text = L"EDIT MODE";
		// 
		// radioButton_rmapLines
		// 
		this->radioButton_rmapLines->AutoSize = true;
		this->radioButton_rmapLines->Location = System::Drawing::Point(6, 65);
		this->radioButton_rmapLines->Name = L"radioButton_rmapLines";
		this->radioButton_rmapLines->Size = System::Drawing::Size(75, 17);
		this->radioButton_rmapLines->TabIndex = 2;
		this->radioButton_rmapLines->TabStop = true;
		this->radioButton_rmapLines->Text = L"Line Mode";
		this->radioButton_rmapLines->UseVisualStyleBackColor = true;
		this->radioButton_rmapLines->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::rmap_markPoint);
		// 
		// radioButton_rmapPLine
		// 
		this->radioButton_rmapPLine->AutoSize = true;
		this->radioButton_rmapPLine->Location = System::Drawing::Point(6, 42);
		this->radioButton_rmapPLine->Name = L"radioButton_rmapPLine";
		this->radioButton_rmapPLine->Size = System::Drawing::Size(116, 17);
		this->radioButton_rmapPLine->TabIndex = 1;
		this->radioButton_rmapPLine->Text = L"Polygon Line Mode";
		this->radioButton_rmapPLine->UseVisualStyleBackColor = true;
		this->radioButton_rmapPLine->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::rmap_markPoint);
		// 
		// radioButton_rmapPFill
		// 
		this->radioButton_rmapPFill->AutoSize = true;
		this->radioButton_rmapPFill->Checked = true;
		this->radioButton_rmapPFill->Location = System::Drawing::Point(6, 19);
		this->radioButton_rmapPFill->Name = L"radioButton_rmapPFill";
		this->radioButton_rmapPFill->Size = System::Drawing::Size(108, 17);
		this->radioButton_rmapPFill->TabIndex = 0;
		this->radioButton_rmapPFill->TabStop = true;
		this->radioButton_rmapPFill->Text = L"Polygon Fill Mode";
		this->radioButton_rmapPFill->UseVisualStyleBackColor = true;
		this->radioButton_rmapPFill->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::rmap_markPoint);
		// 
		// groupBox4
		// 
		this->groupBox4->Controls->Add(this->button_rmapSet);
		this->groupBox4->Controls->Add(this->comboBox_rmapValue);
		this->groupBox4->Controls->Add(this->label1);
		this->groupBox4->Location = System::Drawing::Point(0, 281);
		this->groupBox4->Name = L"groupBox4";
		this->groupBox4->Size = System::Drawing::Size(167, 73);
		this->groupBox4->TabIndex = 9;
		this->groupBox4->TabStop = false;
		this->groupBox4->Text = L"EDIT SELECTION";
		// 
		// button_rmapSet
		// 
		this->button_rmapSet->Location = System::Drawing::Point(70, 46);
		this->button_rmapSet->Name = L"button_rmapSet";
		this->button_rmapSet->Size = System::Drawing::Size(91, 21);
		this->button_rmapSet->TabIndex = 4;
		this->button_rmapSet->Text = L"Set";
		this->button_rmapSet->UseVisualStyleBackColor = true;
		this->button_rmapSet->Click += gcnew System::EventHandler(this, &MainWindow::rmap_setBits);
		// 
		// comboBox_rmapValue
		// 
		this->comboBox_rmapValue->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
		this->comboBox_rmapValue->FormattingEnabled = true;
		this->comboBox_rmapValue->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"True", L"False"});
		this->comboBox_rmapValue->Location = System::Drawing::Point(70, 19);
		this->comboBox_rmapValue->Name = L"comboBox_rmapValue";
		this->comboBox_rmapValue->Size = System::Drawing::Size(91, 21);
		this->comboBox_rmapValue->TabIndex = 3;
		// 
		// label1
		// 
		this->label1->AutoSize = true;
		this->label1->Location = System::Drawing::Point(3, 22);
		this->label1->Name = L"label1";
		this->label1->Size = System::Drawing::Size(61, 13);
		this->label1->TabIndex = 2;
		this->label1->Text = L"Set Values:";
		// 
		// panel_rmap
		// 
		this->panel_rmap->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->panel_rmap->AutoScroll = true;
		this->panel_rmap->BackColor = System::Drawing::SystemColors::AppWorkspace;
		this->panel_rmap->Controls->Add(this->pictureBox_rmap);
		this->panel_rmap->Location = System::Drawing::Point(173, 0);
		this->panel_rmap->Name = L"panel_rmap";
		this->panel_rmap->Size = System::Drawing::Size(577, 516);
		this->panel_rmap->TabIndex = 8;
		// 
		// pictureBox_rmap
		// 
		this->pictureBox_rmap->BackColor = System::Drawing::Color::White;
		this->pictureBox_rmap->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		this->pictureBox_rmap->Location = System::Drawing::Point(0, 0);
		this->pictureBox_rmap->MaximumSize = System::Drawing::Size(1024, 1024);
		this->pictureBox_rmap->MinimumSize = System::Drawing::Size(1024, 1024);
		this->pictureBox_rmap->Name = L"pictureBox_rmap";
		this->pictureBox_rmap->Size = System::Drawing::Size(1024, 1024);
		this->pictureBox_rmap->TabIndex = 2;
		this->pictureBox_rmap->TabStop = false;
		this->pictureBox_rmap->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::rmap_tooltip);
		this->pictureBox_rmap->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::rmap_markPoint);
		// 
		// groupBox3
		// 
		this->groupBox3->Controls->Add(this->button5);
		this->groupBox3->Controls->Add(this->button6);
		this->groupBox3->Controls->Add(this->button_rmapSave);
		this->groupBox3->Controls->Add(this->button_rmapLoad);
		this->groupBox3->Controls->Add(this->textBox_rmapFile);
		this->groupBox3->Location = System::Drawing::Point(0, 0);
		this->groupBox3->Name = L"groupBox3";
		this->groupBox3->Size = System::Drawing::Size(167, 104);
		this->groupBox3->TabIndex = 7;
		this->groupBox3->TabStop = false;
		this->groupBox3->Text = L"FILE";
		// 
		// button5
		// 
		this->button5->Location = System::Drawing::Point(87, 74);
		this->button5->Name = L"button5";
		this->button5->Size = System::Drawing::Size(74, 23);
		this->button5->TabIndex = 6;
		this->button5->Text = L"Export VG";
		this->button5->UseVisualStyleBackColor = true;
		this->button5->Click += gcnew System::EventHandler(this, &MainWindow::rmap_export);
		// 
		// button6
		// 
		this->button6->Location = System::Drawing::Point(6, 74);
		this->button6->Name = L"button6";
		this->button6->Size = System::Drawing::Size(74, 23);
		this->button6->TabIndex = 5;
		this->button6->Text = L"Import VG";
		this->button6->UseVisualStyleBackColor = true;
		this->button6->Click += gcnew System::EventHandler(this, &MainWindow::rmap_import);
		// 
		// button_rmapSave
		// 
		this->button_rmapSave->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
		this->button_rmapSave->Location = System::Drawing::Point(87, 45);
		this->button_rmapSave->Name = L"button_rmapSave";
		this->button_rmapSave->Size = System::Drawing::Size(74, 23);
		this->button_rmapSave->TabIndex = 2;
		this->button_rmapSave->Text = L"Save";
		this->button_rmapSave->UseVisualStyleBackColor = true;
		this->button_rmapSave->Click += gcnew System::EventHandler(this, &MainWindow::rmap_save);
		// 
		// button_rmapLoad
		// 
		this->button_rmapLoad->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(0)));
		this->button_rmapLoad->Location = System::Drawing::Point(6, 45);
		this->button_rmapLoad->Name = L"button_rmapLoad";
		this->button_rmapLoad->Size = System::Drawing::Size(74, 23);
		this->button_rmapLoad->TabIndex = 1;
		this->button_rmapLoad->Text = L"Load...";
		this->button_rmapLoad->UseVisualStyleBackColor = true;
		this->button_rmapLoad->Click += gcnew System::EventHandler(this, &MainWindow::rmap_load);
		// 
		// textBox_rmapFile
		// 
		this->textBox_rmapFile->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->textBox_rmapFile->Enabled = false;
		this->textBox_rmapFile->Location = System::Drawing::Point(6, 19);
		this->textBox_rmapFile->Name = L"textBox_rmapFile";
		this->textBox_rmapFile->Size = System::Drawing::Size(155, 20);
		this->textBox_rmapFile->TabIndex = 0;
		// 
		// tabPage6
		// 
		this->tabPage6->Controls->Add(this->pictureBox_wmap);
		this->tabPage6->Controls->Add(this->groupBox18);
		this->tabPage6->Controls->Add(this->groupBox21);
		this->tabPage6->Controls->Add(this->groupBox22);
		this->tabPage6->Location = System::Drawing::Point(4, 25);
		this->tabPage6->Name = L"tabPage6";
		this->tabPage6->Size = System::Drawing::Size(750, 516);
		this->tabPage6->TabIndex = 5;
		this->tabPage6->Text = L"*.wmap";
		this->tabPage6->UseVisualStyleBackColor = true;
		// 
		// pictureBox_wmap
		// 
		this->pictureBox_wmap->BackColor = System::Drawing::Color::White;
		this->pictureBox_wmap->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		this->pictureBox_wmap->Location = System::Drawing::Point(173, 0);
		this->pictureBox_wmap->MaximumSize = System::Drawing::Size(513, 513);
		this->pictureBox_wmap->MinimumSize = System::Drawing::Size(513, 513);
		this->pictureBox_wmap->Name = L"pictureBox_wmap";
		this->pictureBox_wmap->Size = System::Drawing::Size(513, 513);
		this->pictureBox_wmap->TabIndex = 2;
		this->pictureBox_wmap->TabStop = false;
		this->pictureBox_wmap->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::wmap_tooltip);
		// 
		// groupBox18
		// 
		this->groupBox18->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->groupBox18->Controls->Add(this->comboBox_wmapBackground);
		this->groupBox18->Controls->Add(this->checkBox_wmapBackground);
		this->groupBox18->Location = System::Drawing::Point(0, 81);
		this->groupBox18->Name = L"groupBox18";
		this->groupBox18->Size = System::Drawing::Size(170, 75);
		this->groupBox18->TabIndex = 14;
		this->groupBox18->TabStop = false;
		this->groupBox18->Text = L"BACKGROUND";
		// 
		// comboBox_wmapBackground
		// 
		this->comboBox_wmapBackground->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->comboBox_wmapBackground->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
		this->comboBox_wmapBackground->FormattingEnabled = true;
		this->comboBox_wmapBackground->Location = System::Drawing::Point(6, 42);
		this->comboBox_wmapBackground->Name = L"comboBox_wmapBackground";
		this->comboBox_wmapBackground->Size = System::Drawing::Size(156, 21);
		this->comboBox_wmapBackground->TabIndex = 3;
		this->comboBox_wmapBackground->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::wmap_switchBackground);
		// 
		// checkBox_wmapBackground
		// 
		this->checkBox_wmapBackground->AutoSize = true;
		this->checkBox_wmapBackground->Checked = true;
		this->checkBox_wmapBackground->CheckState = System::Windows::Forms::CheckState::Checked;
		this->checkBox_wmapBackground->Location = System::Drawing::Point(6, 19);
		this->checkBox_wmapBackground->Name = L"checkBox_wmapBackground";
		this->checkBox_wmapBackground->Size = System::Drawing::Size(120, 17);
		this->checkBox_wmapBackground->TabIndex = 2;
		this->checkBox_wmapBackground->Text = L"Toggle Background";
		this->checkBox_wmapBackground->UseVisualStyleBackColor = true;
		this->checkBox_wmapBackground->Click += gcnew System::EventHandler(this, &MainWindow::wmap_switchBackground);
		// 
		// groupBox21
		// 
		this->groupBox21->Controls->Add(this->textBox_wmapAltitude);
		this->groupBox21->Controls->Add(this->label31);
		this->groupBox21->Controls->Add(this->listBox_wmapCollection);
		this->groupBox21->Controls->Add(this->textBox_wmapSpanY);
		this->groupBox21->Controls->Add(this->textBox_wmapSpanX);
		this->groupBox21->Controls->Add(this->textBox_wmapCenterY);
		this->groupBox21->Controls->Add(this->textBox_wmapCenterX);
		this->groupBox21->Controls->Add(this->label38);
		this->groupBox21->Controls->Add(this->label39);
		this->groupBox21->Controls->Add(this->label40);
		this->groupBox21->Controls->Add(this->label41);
		this->groupBox21->Location = System::Drawing::Point(0, 162);
		this->groupBox21->Name = L"groupBox21";
		this->groupBox21->Size = System::Drawing::Size(167, 307);
		this->groupBox21->TabIndex = 10;
		this->groupBox21->TabStop = false;
		this->groupBox21->Text = L"WATER";
		// 
		// textBox_wmapAltitude
		// 
		this->textBox_wmapAltitude->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
		this->textBox_wmapAltitude->Location = System::Drawing::Point(87, 281);
		this->textBox_wmapAltitude->Name = L"textBox_wmapAltitude";
		this->textBox_wmapAltitude->Size = System::Drawing::Size(74, 20);
		this->textBox_wmapAltitude->TabIndex = 16;
		this->textBox_wmapAltitude->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_wmapAltitude->Leave += gcnew System::EventHandler(this, &MainWindow::wmap_editValue);
		// 
		// label31
		// 
		this->label31->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
		this->label31->AutoSize = true;
		this->label31->Location = System::Drawing::Point(3, 284);
		this->label31->Name = L"label31";
		this->label31->Size = System::Drawing::Size(45, 13);
		this->label31->TabIndex = 15;
		this->label31->Text = L"Altitude:";
		// 
		// listBox_wmapCollection
		// 
		this->listBox_wmapCollection->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left));
		this->listBox_wmapCollection->ContextMenuStrip = this->contextMenuStrip_water;
		this->listBox_wmapCollection->FormattingEnabled = true;
		this->listBox_wmapCollection->Location = System::Drawing::Point(6, 19);
		this->listBox_wmapCollection->Name = L"listBox_wmapCollection";
		this->listBox_wmapCollection->Size = System::Drawing::Size(155, 147);
		this->listBox_wmapCollection->TabIndex = 14;
		this->listBox_wmapCollection->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::wmap_change);
		// 
		// contextMenuStrip_water
		// 
		this->contextMenuStrip_water->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripMenuItem1, 
			this->toolStripMenuItem2});
		this->contextMenuStrip_water->Name = L"contextMenuStrip_path";
		this->contextMenuStrip_water->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
		this->contextMenuStrip_water->ShowImageMargin = false;
		this->contextMenuStrip_water->Size = System::Drawing::Size(81, 48);
		// 
		// toolStripMenuItem1
		// 
		this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
		this->toolStripMenuItem1->Size = System::Drawing::Size(80, 22);
		this->toolStripMenuItem1->Text = L"Add";
		this->toolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainWindow::wmap_add);
		// 
		// toolStripMenuItem2
		// 
		this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
		this->toolStripMenuItem2->Size = System::Drawing::Size(80, 22);
		this->toolStripMenuItem2->Text = L"Delete";
		this->toolStripMenuItem2->Click += gcnew System::EventHandler(this, &MainWindow::wmap_delete);
		// 
		// textBox_wmapSpanY
		// 
		this->textBox_wmapSpanY->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
		this->textBox_wmapSpanY->Location = System::Drawing::Point(87, 255);
		this->textBox_wmapSpanY->Name = L"textBox_wmapSpanY";
		this->textBox_wmapSpanY->Size = System::Drawing::Size(74, 20);
		this->textBox_wmapSpanY->TabIndex = 10;
		this->textBox_wmapSpanY->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_wmapSpanY->Leave += gcnew System::EventHandler(this, &MainWindow::wmap_editValue);
		// 
		// textBox_wmapSpanX
		// 
		this->textBox_wmapSpanX->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
		this->textBox_wmapSpanX->Location = System::Drawing::Point(87, 229);
		this->textBox_wmapSpanX->Name = L"textBox_wmapSpanX";
		this->textBox_wmapSpanX->Size = System::Drawing::Size(74, 20);
		this->textBox_wmapSpanX->TabIndex = 8;
		this->textBox_wmapSpanX->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_wmapSpanX->Leave += gcnew System::EventHandler(this, &MainWindow::wmap_editValue);
		// 
		// textBox_wmapCenterY
		// 
		this->textBox_wmapCenterY->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
		this->textBox_wmapCenterY->Location = System::Drawing::Point(87, 203);
		this->textBox_wmapCenterY->Name = L"textBox_wmapCenterY";
		this->textBox_wmapCenterY->Size = System::Drawing::Size(74, 20);
		this->textBox_wmapCenterY->TabIndex = 6;
		this->textBox_wmapCenterY->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_wmapCenterY->Leave += gcnew System::EventHandler(this, &MainWindow::wmap_editValue);
		// 
		// textBox_wmapCenterX
		// 
		this->textBox_wmapCenterX->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
		this->textBox_wmapCenterX->Location = System::Drawing::Point(87, 177);
		this->textBox_wmapCenterX->Name = L"textBox_wmapCenterX";
		this->textBox_wmapCenterX->Size = System::Drawing::Size(74, 20);
		this->textBox_wmapCenterX->TabIndex = 4;
		this->textBox_wmapCenterX->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_wmapCenterX->Leave += gcnew System::EventHandler(this, &MainWindow::wmap_editValue);
		// 
		// label38
		// 
		this->label38->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
		this->label38->AutoSize = true;
		this->label38->Location = System::Drawing::Point(3, 258);
		this->label38->Name = L"label38";
		this->label38->Size = System::Drawing::Size(45, 13);
		this->label38->TabIndex = 9;
		this->label38->Text = L"Span Y:";
		// 
		// label39
		// 
		this->label39->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
		this->label39->AutoSize = true;
		this->label39->Location = System::Drawing::Point(3, 232);
		this->label39->Name = L"label39";
		this->label39->Size = System::Drawing::Size(45, 13);
		this->label39->TabIndex = 7;
		this->label39->Text = L"Span X:";
		// 
		// label40
		// 
		this->label40->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
		this->label40->AutoSize = true;
		this->label40->Location = System::Drawing::Point(3, 180);
		this->label40->Name = L"label40";
		this->label40->Size = System::Drawing::Size(51, 13);
		this->label40->TabIndex = 3;
		this->label40->Text = L"Center X:";
		// 
		// label41
		// 
		this->label41->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
		this->label41->AutoSize = true;
		this->label41->Location = System::Drawing::Point(3, 206);
		this->label41->Name = L"label41";
		this->label41->Size = System::Drawing::Size(51, 13);
		this->label41->TabIndex = 5;
		this->label41->Text = L"Center Y:";
		// 
		// groupBox22
		// 
		this->groupBox22->Controls->Add(this->button_waterSave);
		this->groupBox22->Controls->Add(this->button_wmapLoad);
		this->groupBox22->Controls->Add(this->textBox_wmapFile);
		this->groupBox22->Location = System::Drawing::Point(0, 0);
		this->groupBox22->Name = L"groupBox22";
		this->groupBox22->Size = System::Drawing::Size(167, 75);
		this->groupBox22->TabIndex = 9;
		this->groupBox22->TabStop = false;
		this->groupBox22->Text = L"FILE";
		// 
		// button_waterSave
		// 
		this->button_waterSave->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
		this->button_waterSave->Location = System::Drawing::Point(87, 45);
		this->button_waterSave->Name = L"button_waterSave";
		this->button_waterSave->Size = System::Drawing::Size(74, 23);
		this->button_waterSave->TabIndex = 2;
		this->button_waterSave->Text = L"Save";
		this->button_waterSave->UseVisualStyleBackColor = true;
		this->button_waterSave->Click += gcnew System::EventHandler(this, &MainWindow::wmap_save);
		// 
		// button_wmapLoad
		// 
		this->button_wmapLoad->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(0)));
		this->button_wmapLoad->Location = System::Drawing::Point(6, 45);
		this->button_wmapLoad->Name = L"button_wmapLoad";
		this->button_wmapLoad->Size = System::Drawing::Size(74, 23);
		this->button_wmapLoad->TabIndex = 1;
		this->button_wmapLoad->Text = L"Load...";
		this->button_wmapLoad->UseVisualStyleBackColor = true;
		this->button_wmapLoad->Click += gcnew System::EventHandler(this, &MainWindow::wmap_load);
		// 
		// textBox_wmapFile
		// 
		this->textBox_wmapFile->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->textBox_wmapFile->Enabled = false;
		this->textBox_wmapFile->Location = System::Drawing::Point(6, 19);
		this->textBox_wmapFile->Name = L"textBox_wmapFile";
		this->textBox_wmapFile->Size = System::Drawing::Size(155, 20);
		this->textBox_wmapFile->TabIndex = 0;
		// 
		// tabPage4
		// 
		this->tabPage4->Controls->Add(this->webBrowser_explorer);
		this->tabPage4->Location = System::Drawing::Point(4, 25);
		this->tabPage4->Margin = System::Windows::Forms::Padding(0);
		this->tabPage4->Name = L"tabPage4";
		this->tabPage4->Size = System::Drawing::Size(750, 516);
		this->tabPage4->TabIndex = 3;
		this->tabPage4->Text = L"World Explorer";
		this->tabPage4->UseVisualStyleBackColor = true;
		// 
		// webBrowser_explorer
		// 
		this->webBrowser_explorer->AllowWebBrowserDrop = false;
		this->webBrowser_explorer->Dock = System::Windows::Forms::DockStyle::Fill;
		this->webBrowser_explorer->IsWebBrowserContextMenuEnabled = false;
		this->webBrowser_explorer->Location = System::Drawing::Point(0, 0);
		this->webBrowser_explorer->MinimumSize = System::Drawing::Size(20, 20);
		this->webBrowser_explorer->Name = L"webBrowser_explorer";
		this->webBrowser_explorer->ScrollBarsEnabled = false;
		this->webBrowser_explorer->Size = System::Drawing::Size(750, 516);
		this->webBrowser_explorer->TabIndex = 1;
		this->webBrowser_explorer->WebBrowserShortcutsEnabled = false;
		// 
		// groupBox7
		// 
		this->groupBox7->Controls->Add(this->button2);
		this->groupBox7->Controls->Add(this->label3);
		this->groupBox7->Location = System::Drawing::Point(0, 0);
		this->groupBox7->Name = L"groupBox7";
		this->groupBox7->Size = System::Drawing::Size(710, 51);
		this->groupBox7->TabIndex = 1;
		this->groupBox7->TabStop = false;
		this->groupBox7->Text = L"INPUT FOLDER";
		// 
		// button2
		// 
		this->button2->Location = System::Drawing::Point(627, 19);
		this->button2->Name = L"button2";
		this->button2->Size = System::Drawing::Size(75, 23);
		this->button2->TabIndex = 2;
		this->button2->Text = L"button_convertLoad";
		this->button2->UseVisualStyleBackColor = true;
		// 
		// label3
		// 
		this->label3->AutoSize = true;
		this->label3->Location = System::Drawing::Point(6, 24);
		this->label3->Name = L"label3";
		this->label3->Size = System::Drawing::Size(97, 13);
		this->label3->TabIndex = 0;
		this->label3->Text = L"Path to Client Map:";
		// 
		// groupBox8
		// 
		this->groupBox8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->groupBox8->Controls->Add(this->button3);
		this->groupBox8->Controls->Add(this->label5);
		this->groupBox8->Location = System::Drawing::Point(0, 0);
		this->groupBox8->Name = L"groupBox8";
		this->groupBox8->Size = System::Drawing::Size(710, 51);
		this->groupBox8->TabIndex = 1;
		this->groupBox8->TabStop = false;
		this->groupBox8->Text = L"INPUT FOLDER";
		// 
		// button3
		// 
		this->button3->Location = System::Drawing::Point(627, 19);
		this->button3->Name = L"button3";
		this->button3->Size = System::Drawing::Size(75, 23);
		this->button3->TabIndex = 2;
		this->button3->Text = L"button_convertLoad";
		this->button3->UseVisualStyleBackColor = true;
		// 
		// label5
		// 
		this->label5->AutoSize = true;
		this->label5->Location = System::Drawing::Point(6, 24);
		this->label5->Name = L"label5";
		this->label5->Size = System::Drawing::Size(97, 13);
		this->label5->TabIndex = 0;
		this->label5->Text = L"Path to Client Map:";
		// 
		// menuStrip_mainMenu
		// 
		this->menuStrip_mainMenu->BackColor = System::Drawing::SystemColors::Control;
		this->menuStrip_mainMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->toolStripMenuItem4});
		this->menuStrip_mainMenu->Location = System::Drawing::Point(0, 0);
		this->menuStrip_mainMenu->Name = L"menuStrip_mainMenu";
		this->menuStrip_mainMenu->Padding = System::Windows::Forms::Padding(0, 2, 2, 2);
		this->menuStrip_mainMenu->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
		this->menuStrip_mainMenu->Size = System::Drawing::Size(758, 24);
		this->menuStrip_mainMenu->TabIndex = 8;
		this->menuStrip_mainMenu->Text = L"menuStrip1";
		// 
		// toolStripMenuItem4
		// 
		this->toolStripMenuItem4->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
		this->toolStripMenuItem4->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->exitToolStripMenuItem});
		this->toolStripMenuItem4->ImageScaling = System::Windows::Forms::ToolStripItemImageScaling::None;
		this->toolStripMenuItem4->Name = L"toolStripMenuItem4";
		this->toolStripMenuItem4->Padding = System::Windows::Forms::Padding(0);
		this->toolStripMenuItem4->Size = System::Drawing::Size(27, 20);
		this->toolStripMenuItem4->Text = L"File";
		this->toolStripMenuItem4->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
		// 
		// exitToolStripMenuItem
		// 
		this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
		this->exitToolStripMenuItem->Size = System::Drawing::Size(92, 22);
		this->exitToolStripMenuItem->Text = L"Exit";
		this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::click_exit);
		// 
		// comboBox1
		// 
		this->comboBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
		this->comboBox1->FormattingEnabled = true;
		this->comboBox1->Location = System::Drawing::Point(6, 42);
		this->comboBox1->Name = L"comboBox1";
		this->comboBox1->Size = System::Drawing::Size(455, 21);
		this->comboBox1->TabIndex = 3;
		// 
		// checkBox1
		// 
		this->checkBox1->AutoSize = true;
		this->checkBox1->Checked = true;
		this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
		this->checkBox1->Location = System::Drawing::Point(6, 19);
		this->checkBox1->Name = L"checkBox1";
		this->checkBox1->Size = System::Drawing::Size(120, 17);
		this->checkBox1->TabIndex = 2;
		this->checkBox1->Text = L"Toggle Background";
		this->checkBox1->UseVisualStyleBackColor = true;
		// 
		// textBox1
		// 
		this->textBox1->Enabled = false;
		this->textBox1->Location = System::Drawing::Point(206, 160);
		this->textBox1->Name = L"textBox1";
		this->textBox1->Size = System::Drawing::Size(63, 20);
		this->textBox1->TabIndex = 38;
		this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		// 
		// textBox2
		// 
		this->textBox2->Location = System::Drawing::Point(206, 134);
		this->textBox2->Name = L"textBox2";
		this->textBox2->Size = System::Drawing::Size(63, 20);
		this->textBox2->TabIndex = 37;
		this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		// 
		// textBox3
		// 
		this->textBox3->Location = System::Drawing::Point(206, 108);
		this->textBox3->Name = L"textBox3";
		this->textBox3->Size = System::Drawing::Size(63, 20);
		this->textBox3->TabIndex = 36;
		this->textBox3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		// 
		// label20
		// 
		this->label20->AutoSize = true;
		this->label20->Location = System::Drawing::Point(65, 163);
		this->label20->Name = L"label20";
		this->label20->Size = System::Drawing::Size(88, 13);
		this->label20->TabIndex = 35;
		this->label20->Text = L"Segment Length:";
		// 
		// label21
		// 
		this->label21->AutoSize = true;
		this->label21->Location = System::Drawing::Point(65, 137);
		this->label21->Name = L"label21";
		this->label21->Size = System::Drawing::Size(70, 13);
		this->label21->TabIndex = 34;
		this->label21->Text = L"End Point ID:";
		// 
		// label22
		// 
		this->label22->AutoSize = true;
		this->label22->Location = System::Drawing::Point(65, 111);
		this->label22->Name = L"label22";
		this->label22->Size = System::Drawing::Size(73, 13);
		this->label22->TabIndex = 33;
		this->label22->Text = L"Start Point ID:";
		// 
		// textBox4
		// 
		this->textBox4->Location = System::Drawing::Point(204, 74);
		this->textBox4->Name = L"textBox4";
		this->textBox4->Size = System::Drawing::Size(63, 20);
		this->textBox4->TabIndex = 32;
		this->textBox4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		// 
		// textBox5
		// 
		this->textBox5->Location = System::Drawing::Point(135, 74);
		this->textBox5->Name = L"textBox5";
		this->textBox5->Size = System::Drawing::Size(63, 20);
		this->textBox5->TabIndex = 31;
		this->textBox5->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		// 
		// label23
		// 
		this->label23->AutoSize = true;
		this->label23->Location = System::Drawing::Point(63, 19);
		this->label23->Name = L"label23";
		this->label23->Size = System::Drawing::Size(149, 13);
		this->label23->TabIndex = 25;
		this->label23->Text = L"Control Point 1 (X, Altitude, Z):";
		// 
		// textBox6
		// 
		this->textBox6->Location = System::Drawing::Point(66, 74);
		this->textBox6->Name = L"textBox6";
		this->textBox6->Size = System::Drawing::Size(63, 20);
		this->textBox6->TabIndex = 30;
		this->textBox6->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		// 
		// textBox7
		// 
		this->textBox7->Location = System::Drawing::Point(66, 35);
		this->textBox7->Name = L"textBox7";
		this->textBox7->Size = System::Drawing::Size(63, 20);
		this->textBox7->TabIndex = 26;
		this->textBox7->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		// 
		// label24
		// 
		this->label24->AutoSize = true;
		this->label24->Location = System::Drawing::Point(63, 58);
		this->label24->Name = L"label24";
		this->label24->Size = System::Drawing::Size(149, 13);
		this->label24->TabIndex = 29;
		this->label24->Text = L"Control Point 2 (X, Altitude, Z):";
		// 
		// textBox8
		// 
		this->textBox8->Location = System::Drawing::Point(135, 35);
		this->textBox8->Name = L"textBox8";
		this->textBox8->Size = System::Drawing::Size(63, 20);
		this->textBox8->TabIndex = 27;
		this->textBox8->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		// 
		// textBox9
		// 
		this->textBox9->Location = System::Drawing::Point(204, 35);
		this->textBox9->Name = L"textBox9";
		this->textBox9->Size = System::Drawing::Size(63, 20);
		this->textBox9->TabIndex = 28;
		this->textBox9->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		// 
		// listBox1
		// 
		this->listBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left));
		this->listBox1->ContextMenuStrip = this->contextMenuStrip_path;
		this->listBox1->FormattingEnabled = true;
		this->listBox1->Location = System::Drawing::Point(6, 19);
		this->listBox1->Name = L"listBox1";
		this->listBox1->Size = System::Drawing::Size(56, 160);
		this->listBox1->TabIndex = 14;
		// 
		// textBox10
		// 
		this->textBox10->Location = System::Drawing::Point(204, 81);
		this->textBox10->Name = L"textBox10";
		this->textBox10->Size = System::Drawing::Size(63, 20);
		this->textBox10->TabIndex = 24;
		this->textBox10->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		// 
		// listBox2
		// 
		this->listBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left));
		this->listBox2->ContextMenuStrip = this->contextMenuStrip_path;
		this->listBox2->FormattingEnabled = true;
		this->listBox2->Location = System::Drawing::Point(6, 19);
		this->listBox2->Name = L"listBox2";
		this->listBox2->Size = System::Drawing::Size(56, 82);
		this->listBox2->TabIndex = 13;
		// 
		// textBox11
		// 
		this->textBox11->Location = System::Drawing::Point(135, 81);
		this->textBox11->Name = L"textBox11";
		this->textBox11->Size = System::Drawing::Size(63, 20);
		this->textBox11->TabIndex = 23;
		this->textBox11->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		// 
		// label25
		// 
		this->label25->AutoSize = true;
		this->label25->Location = System::Drawing::Point(63, 19);
		this->label25->Name = L"label25";
		this->label25->Size = System::Drawing::Size(104, 13);
		this->label25->TabIndex = 15;
		this->label25->Text = L"Point (X, Altitude, Z):";
		// 
		// textBox12
		// 
		this->textBox12->Location = System::Drawing::Point(66, 81);
		this->textBox12->Name = L"textBox12";
		this->textBox12->Size = System::Drawing::Size(63, 20);
		this->textBox12->TabIndex = 22;
		this->textBox12->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		// 
		// textBox13
		// 
		this->textBox13->Location = System::Drawing::Point(66, 35);
		this->textBox13->Name = L"textBox13";
		this->textBox13->Size = System::Drawing::Size(63, 20);
		this->textBox13->TabIndex = 17;
		this->textBox13->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		// 
		// label26
		// 
		this->label26->AutoSize = true;
		this->label26->Location = System::Drawing::Point(63, 65);
		this->label26->Name = L"label26";
		this->label26->Size = System::Drawing::Size(122, 13);
		this->label26->TabIndex = 21;
		this->label26->Text = L"Direction (X, Altitude, Z):";
		// 
		// textBox14
		// 
		this->textBox14->Location = System::Drawing::Point(135, 35);
		this->textBox14->Name = L"textBox14";
		this->textBox14->Size = System::Drawing::Size(63, 20);
		this->textBox14->TabIndex = 19;
		this->textBox14->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		// 
		// textBox15
		// 
		this->textBox15->Location = System::Drawing::Point(204, 35);
		this->textBox15->Name = L"textBox15";
		this->textBox15->Size = System::Drawing::Size(63, 20);
		this->textBox15->TabIndex = 20;
		this->textBox15->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		// 
		// listBox3
		// 
		this->listBox3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left));
		this->listBox3->ContextMenuStrip = this->contextMenuStrip_path;
		this->listBox3->FormattingEnabled = true;
		this->listBox3->Location = System::Drawing::Point(6, 19);
		this->listBox3->Name = L"listBox3";
		this->listBox3->Size = System::Drawing::Size(56, 95);
		this->listBox3->TabIndex = 14;
		// 
		// textBox16
		// 
		this->textBox16->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
		this->textBox16->Location = System::Drawing::Point(206, 97);
		this->textBox16->Name = L"textBox16";
		this->textBox16->Size = System::Drawing::Size(63, 20);
		this->textBox16->TabIndex = 10;
		this->textBox16->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		// 
		// textBox17
		// 
		this->textBox17->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
		this->textBox17->Location = System::Drawing::Point(206, 71);
		this->textBox17->Name = L"textBox17";
		this->textBox17->Size = System::Drawing::Size(63, 20);
		this->textBox17->TabIndex = 8;
		this->textBox17->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		// 
		// textBox18
		// 
		this->textBox18->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
		this->textBox18->Location = System::Drawing::Point(206, 45);
		this->textBox18->Name = L"textBox18";
		this->textBox18->Size = System::Drawing::Size(63, 20);
		this->textBox18->TabIndex = 6;
		this->textBox18->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		// 
		// textBox19
		// 
		this->textBox19->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
		this->textBox19->Location = System::Drawing::Point(206, 19);
		this->textBox19->Name = L"textBox19";
		this->textBox19->Size = System::Drawing::Size(63, 20);
		this->textBox19->TabIndex = 4;
		this->textBox19->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		// 
		// label27
		// 
		this->label27->AutoSize = true;
		this->label27->Location = System::Drawing::Point(68, 100);
		this->label27->Name = L"label27";
		this->label27->Size = System::Drawing::Size(65, 13);
		this->label27->TabIndex = 9;
		this->label27->Text = L"Unknown 3:";
		// 
		// label28
		// 
		this->label28->AutoSize = true;
		this->label28->Location = System::Drawing::Point(68, 74);
		this->label28->Name = L"label28";
		this->label28->Size = System::Drawing::Size(65, 13);
		this->label28->TabIndex = 7;
		this->label28->Text = L"Unknown 2:";
		// 
		// label29
		// 
		this->label29->AutoSize = true;
		this->label29->Location = System::Drawing::Point(68, 22);
		this->label29->Name = L"label29";
		this->label29->Size = System::Drawing::Size(21, 13);
		this->label29->TabIndex = 3;
		this->label29->Text = L"ID:";
		// 
		// label30
		// 
		this->label30->AutoSize = true;
		this->label30->Location = System::Drawing::Point(68, 48);
		this->label30->Name = L"label30";
		this->label30->Size = System::Drawing::Size(65, 13);
		this->label30->TabIndex = 5;
		this->label30->Text = L"Unknown 1:";
		// 
		// button7
		// 
		this->button7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
		this->button7->Location = System::Drawing::Point(141, 45);
		this->button7->Name = L"button7";
		this->button7->Size = System::Drawing::Size(128, 23);
		this->button7->TabIndex = 2;
		this->button7->Text = L"Save";
		this->button7->UseVisualStyleBackColor = true;
		// 
		// button8
		// 
		this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(0)));
		this->button8->Location = System::Drawing::Point(6, 45);
		this->button8->Name = L"button8";
		this->button8->Size = System::Drawing::Size(128, 23);
		this->button8->TabIndex = 1;
		this->button8->Text = L"Load...";
		this->button8->UseVisualStyleBackColor = true;
		// 
		// textBox20
		// 
		this->textBox20->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->textBox20->Enabled = false;
		this->textBox20->Location = System::Drawing::Point(6, 19);
		this->textBox20->Name = L"textBox20";
		this->textBox20->Size = System::Drawing::Size(263, 20);
		this->textBox20->TabIndex = 0;
		// 
		// MainWindow
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(758, 587);
		this->Controls->Add(this->button_magnifier);
		this->Controls->Add(this->menuStrip_mainMenu);
		this->Controls->Add(this->tabControl1);
		this->Controls->Add(this->progressBar1);
		this->MinimumSize = System::Drawing::Size(766, 614);
		this->Name = L"MainWindow";
		this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
		this->Text = L" sMAPtool";
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox_hmap))->EndInit();
		this->groupBox2->ResumeLayout(false);
		this->groupBox2->PerformLayout();
		this->panel1->ResumeLayout(false);
		this->panel1->PerformLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown_hmapSetSE))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown_hmapSetSW))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown_hmapSetNE))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown_hmapSetNW))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->button_magnifier))->EndInit();
		this->tabControl1->ResumeLayout(false);
		this->tabPage3->ResumeLayout(false);
		this->groupBox10->ResumeLayout(false);
		this->groupBox10->PerformLayout();
		this->groupBox9->ResumeLayout(false);
		this->groupBox9->PerformLayout();
		this->groupBox6->ResumeLayout(false);
		this->groupBox6->PerformLayout();
		this->tabPage5->ResumeLayout(false);
		this->panel_path->ResumeLayout(false);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox_path))->EndInit();
		this->groupBox17->ResumeLayout(false);
		this->groupBox17->PerformLayout();
		this->groupBox16->ResumeLayout(false);
		this->groupBox16->PerformLayout();
		this->contextMenuStrip_path->ResumeLayout(false);
		this->groupBox15->ResumeLayout(false);
		this->groupBox15->PerformLayout();
		this->groupBox14->ResumeLayout(false);
		this->groupBox14->PerformLayout();
		this->groupBox13->ResumeLayout(false);
		this->groupBox13->PerformLayout();
		this->tabPage1->ResumeLayout(false);
		this->groupBox11->ResumeLayout(false);
		this->groupBox11->PerformLayout();
		this->panel_hmap->ResumeLayout(false);
		this->groupBox1->ResumeLayout(false);
		this->groupBox1->PerformLayout();
		this->tabPage2->ResumeLayout(false);
		this->groupBox12->ResumeLayout(false);
		this->groupBox12->PerformLayout();
		this->groupBox5->ResumeLayout(false);
		this->groupBox5->PerformLayout();
		this->groupBox4->ResumeLayout(false);
		this->groupBox4->PerformLayout();
		this->panel_rmap->ResumeLayout(false);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox_rmap))->EndInit();
		this->groupBox3->ResumeLayout(false);
		this->groupBox3->PerformLayout();
		this->tabPage6->ResumeLayout(false);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox_wmap))->EndInit();
		this->groupBox18->ResumeLayout(false);
		this->groupBox18->PerformLayout();
		this->groupBox21->ResumeLayout(false);
		this->groupBox21->PerformLayout();
		this->contextMenuStrip_water->ResumeLayout(false);
		this->groupBox22->ResumeLayout(false);
		this->groupBox22->PerformLayout();
		this->tabPage4->ResumeLayout(false);
		this->groupBox7->ResumeLayout(false);
		this->groupBox7->PerformLayout();
		this->groupBox8->ResumeLayout(false);
		this->groupBox8->PerformLayout();
		this->menuStrip_mainMenu->ResumeLayout(false);
		this->menuStrip_mainMenu->PerformLayout();
		this->ResumeLayout(false);
		this->PerformLayout();

	}

#pragma endregion

#pragma region MISC

	Color Float_to_Color(float value)
	{
		return Color::FromArgb(HMAP->ColorScheme[Convert::ToInt32((HMAP->ColorScheme->Length-1)*value)]);
	}
	private: array<unsigned char>^ decompress(array<unsigned char>^ compressed)
	{
		MemoryStream^ ms = gcnew MemoryStream(compressed);

		// Skip 2 Bytes from zlib
		ms->ReadByte();
		ms->ReadByte();

		Compression::DeflateStream^ ds = gcnew Compression::DeflateStream(ms, Compression::CompressionMode::Decompress, true);
		
		ArrayList^ temp = gcnew ArrayList();

		int value;

		while((value = ds->ReadByte()) != -1)
		{
			temp->Add((unsigned char)value);
		}

		ds->Close();
		ms->Close();

		array<unsigned char>^ result = gcnew array<unsigned char>(temp->Count);
		temp->CopyTo(result);
		return result;
	}
	private: void Initialize()
	{
		try
		{
			Pick = gcnew Windows::Forms::Cursor(Application::StartupPath + "\\cursors\\pick.cur");
		}
		catch(...)
		{
			Pick = Cursors::Hand;
		}
		ShiftDown = false;

		// Load Background Files
		if(Directory::Exists(Application::StartupPath + "\\maps"))
		{
			array<String^>^ files = Directory::GetFiles(Application::StartupPath + "\\maps");
			for(int i=0; i<files->Length; i++)
			{
				comboBox_hmapBackground->Items->Add(files[i]->Substring(files[i]->LastIndexOf("\\")+1));
				comboBox_rmapBackground->Items->Add(files[i]->Substring(files[i]->LastIndexOf("\\")+1));
				comboBox_wmapBackground->Items->Add(files[i]->Substring(files[i]->LastIndexOf("\\")+1));
			}
		}
	}
	private: System::Void misc_keyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		if(e->Shift)
		{
			ShiftDown = true;
			Cursor = Pick;
		}
	}
	private: System::Void misc_keyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		ShiftDown = false;
		Cursor = Cursors::Default;
	}
	private: System::Void magnifier_click(System::Object^  sender, System::EventArgs^  e)
	{
		if(File::Exists(Application::StartupPath + "\\magnifier.exe"))
		{
			Diagnostics::Process::Start(Application::StartupPath + "\\magnifier.exe");
		}
		else
		{
			MessageBox::Show("Not Found: magnifier.exe");
		}
	}
	private: System::Void click_exit(System::Object^  sender, System::EventArgs^  e)
	{
		this->Close();
	}
#pragma endregion
#pragma region CONVERT

	private: System::Void convert_browse(System::Object^  sender, System::EventArgs^  e)
	{
		FolderBrowserDialog^ dir = gcnew FolderBrowserDialog();

		if(dir->ShowDialog() == Windows::Forms::DialogResult::OK && Directory::Exists(dir->SelectedPath))
		{
			if((Button^)sender == button_convertLoad)
			{
				textBox_convertInput->Text = dir->SelectedPath;
			}
			if((Button^)sender == button_convertSave)
			{
				textBox_convertOutput->Text = dir->SelectedPath;
			}
		}
	}
	private: System::Void convert_export(System::Object^  sender, System::EventArgs^  e)
	{
		Cursor = Windows::Forms::Cursors::WaitCursor;
		progressBar1->Style = Windows::Forms::ProgressBarStyle::Marquee;

		String^ path_input = textBox_convertInput->Text;
		String^ path_output = textBox_convertOutput->Text + "\\maps";
		Directory::CreateDirectory(path_output);
		
		array<String^>^ maps = Directory::GetDirectories(path_input);

		for(int i=0; i<maps->Length; i++)
		{
			String^ input = maps[i];
			String^ output = path_output + input->Substring(input->LastIndexOf("\\"));

			Directory::CreateDirectory(output);
			Directory::CreateDirectory(output + "\\map");
			//Directory::CreateDirectory(output + "\\airmap");
			Directory::CreateDirectory(output + "\\movemap");
			//Directory::CreateDirectory(output + "\\watermap");

			Directory::CreateDirectory(output + "\\decompressed");

			if(checkBox_convertRegion->Checked && File::Exists(input + "\\region.clt"))
			{
				convert_save_region(input + "\\region.clt", output + "\\region.sev");
			}
			if(checkBox_convertPrecinct->Checked && File::Exists(input + "\\precinct.clt"))
			{
				convert_save_precinct(input + "\\precinct.clt", output + "\\precinct.sev");
			}
			if(checkBox_FixDat->Checked && Directory::Exists(input + "\\bsdata"))
			{
				array<String^>^ water = Directory::GetFiles(input + "\\bsdata", "*.dat");

				for(int j=0; j<water->Length; j++)
				{
					convert_fix_dat(water[j]);
					Application::DoEvents();
				}
			}
			if(checkBox_FixT2bk->Checked)
			{
				array<String^>^ terrains = Directory::GetFiles(input, "*.t2bk");

				for(int j=0; j<terrains->Length; j++)
				{
					convert_fix_t2bk(terrains[j]);
					Application::DoEvents();
				}
			}
			if(checkBox_convertTerrain->Checked)
			{
				array<String^>^ terrains = Directory::GetFiles(input, "*.t2bk");

				for(int j=0; j<terrains->Length; j++)
				{
					convert_save_terrain(terrains[j], output + "\\map\\" + terrains[j]->Substring(terrains[j]->LastIndexOf("_")+1)->Replace("t2bk", "hmap"));
					Application::DoEvents();
				}
			}
			if(checkBox_convertT2mk->Checked)
			{
				array<String^>^ terrains = Directory::GetFiles(input, "*.t2mk");

				for(int j=0; j<terrains->Length; j++)
				{
					convert_save_t2mk(terrains[j], output + "\\decompressed\\" + terrains[j]->Substring(terrains[j]->LastIndexOf("_")+1)->Replace("t2mk", "t2mk"));
					Application::DoEvents();
				}
			}
			Application::DoEvents();
		}

		progressBar1->Style = Windows::Forms::ProgressBarStyle::Continuous;
		Cursor = Windows::Forms::Cursors::Default;
	}
	void convert_save_region(String^ fileIn, String^ fileOut)
	{
		//export region
		StreamReader^ sr = gcnew StreamReader(fileIn, Encoding::Unicode);
		File::Delete(fileOut);
		FileStream^ fs = gcnew FileStream(fileOut, FileMode::Create, FileAccess::Write);
		BinaryWriter^ bw = gcnew BinaryWriter(fs);

		int rcount = 0;
		int tcount = 0;
		String^ line;

		while(line = sr->ReadLine())
		{
			if(line->StartsWith("version "))
			{
				bw->Write(Convert::ToInt32(line->Replace("version ", "")));
				bw->Write((int)0);
				bw->Write((int)0);
				bw->Write(Convert::ToInt32(sr->ReadLine()));
				
				line = sr->ReadLine();
			}

			if(line->StartsWith("[region]"))
			{
				sr->ReadLine();

				array<String^>^ s = sr->ReadLine()->Split(gcnew array<wchar_t>{' '});

				bw->Write((int)0);
				bw->Write(Convert::ToInt32(s[s->Length-1]));

				rcount++;
				
				line = sr->ReadLine();
			}

			if(line->StartsWith("[trans]"))
			{
				array<String^>^ s = sr->ReadLine()->Split(gcnew array<wchar_t>{' '});

				bw->Write((int)1);
				for(int i=0; i<s->Length; i++)
				{
					if(s[i] != "")
					{
						bw->Write(Convert::ToInt32(s[i]));
					}
				}

				tcount++;
				
				line = sr->ReadLine();
			}

			if(line != "" && !line->StartsWith("\"") && !line->StartsWith("/") && !line->StartsWith("#") && !line->StartsWith("?"))
			{
				array<String^>^ s = line->Replace(",", "")->Split(gcnew array<wchar_t>{' '});

				for(int i=0; i<s->Length; i++)
				{
					if(s[i] != "")
					{
						bw->Write(Convert::ToSingle(s[i]));
					}
				}
			}
		}

		bw->BaseStream->Position = 4;
		bw->Write(rcount);
		bw->Write(tcount);

		sr->Close();
		bw->Close();
		fs->Close();
	}

	void convert_save_precinct(String^ fileIn, String^ fileOut)
	{
		//export region
		StreamReader^ sr = gcnew StreamReader(fileIn, Encoding::Unicode);
		File::Delete(fileOut);
		FileStream^ fs = gcnew FileStream(fileOut, FileMode::Create, FileAccess::Write);
		BinaryWriter^ bw = gcnew BinaryWriter(fs);

		int count = 0;
		String^ line;

		while(line = sr->ReadLine())
		{
			if(line->StartsWith("version "))
			{
				bw->Write(Convert::ToInt32(line->Replace("version ", "")));
				bw->Write((int)0);
				bw->Write(Convert::ToInt32(sr->ReadLine()));
				
				line = sr->ReadLine();
			}

			if(line->StartsWith("\"") && line->EndsWith("\"") && !line->Contains("\"\"") && !line->Contains(".mp3") && !line->Contains(".wav") && !line->Contains(".ogg"))
			{
				array<String^>^ s = sr->ReadLine()->Split(gcnew array<wchar_t>{' '});
				bw->Write(Convert::ToInt32(s[2]));
				bw->Write(Convert::ToInt32(s[6]));
				bw->Write(Convert::ToInt32(s[8]));
				bw->Write(Convert::ToInt32(s[16]));
				bw->Write(Convert::ToInt32(s[18]));
				count++;

				line = sr->ReadLine();
			}

			if(line != "" && !line->StartsWith("\"") && !line->StartsWith("/") && !line->StartsWith("#") && !line->StartsWith("?"))
			{
				array<String^>^ s = line->Replace(",", "")->Split(gcnew array<wchar_t>{' '});

				for(int i=0; i<s->Length; i++)
				{
					if(s[i] != "")
					{
						bw->Write(Convert::ToSingle(s[i]));
					}
				}
			}
		}

		bw->BaseStream->Position = 4;
		bw->Write(count);

		sr->Close();
		bw->Close();
		fs->Close();
	}
	void convert_fix_dat(String^ fileIn)
	{
		bool isFixed = false;

		FileStream^ fr = File::OpenRead(fileIn);
		BinaryReader^ br = gcnew BinaryReader(fr);

		// goto the end of file and read count as integer
		br->BaseStream->Position = br->BaseStream->Length-4;
		int blockCount = br->ReadInt32();
		array<int>^ streamPositionsOrg = gcnew array<int>(blockCount);
		array<int>^ streamPositionsNew = gcnew array<int>(blockCount);

		br->BaseStream->Position = br->BaseStream->Length-(blockCount*4)-4;

		// read old stream offsets
		for(int i=0; i<blockCount; i++)
		{
			streamPositionsOrg[i] = br->ReadInt32();
		}

		String^ fileOut = fileIn + ".tmp";
		if(File::Exists(fileOut))
		{
			File::Delete(fileOut);
		}

		FileStream^ fw = gcnew FileStream(fileOut, FileMode::Create, FileAccess::Write);
		BinaryWriter^ bw = gcnew BinaryWriter(fw);

		br->BaseStream->Position = 0;

		// read the heading and write to output (always 12 byte)
		bw->Write(br->ReadBytes(12));

		for(int i=0; i<blockCount; i++)
		{
			br->BaseStream->Position = streamPositionsOrg[i];
			streamPositionsNew[i] = (int)bw->BaseStream->Position;

			int ident = br->ReadInt32();

			// standard deflated block
			if(ident!=268443648 && ident!=268447744)
			{
				bw->Write(ident);
				bw->Write(br->ReadInt32());
				bw->Write(br->ReadBytes(ident));
			}
			// water block
			else
			{
				// write signature for old waterblock
				bw->Write((int)268443648);
				bw->Write(br->ReadBytes(16));
				int tileCountX = br->ReadInt32();
				bw->Write(tileCountX);
				int tileCountZ = br->ReadInt32();
				bw->Write(tileCountZ);
				bw->Write(br->ReadBytes(16));

				if(ident==268447744)
				{
					isFixed = true;
					// skip byte for new waterblock
					br->ReadByte();
				}

				bw->Write(br->ReadBytes(tileCountX*tileCountZ));

				int coastLineCount = br->ReadInt32();
				bw->Write(coastLineCount);

				for(int c=0; c<coastLineCount; c++)
				{
					bw->Write(br->ReadBytes(12));
					int shorePointCount = br->ReadInt32();
					bw->Write(shorePointCount);
					bw->Write(br->ReadBytes(4*3*shorePointCount));
					bw->Write(br->ReadBytes(4*3*2*shorePointCount));
				}
			}
		}

		// write the new stream positions and the block count
		for(int i=0; i<blockCount; i++)
		{
			bw->Write(streamPositionsNew[i]);
		}

		bw->Write(blockCount);

		bw->Close();
		fw->Close();

		br->Close();
		fr->Close();

		if(isFixed)
		{
			if(File::Exists(fileIn + ".BAK"))
			{
				File::Delete(fileIn + ".BAK");
			}
			File::Move(fileIn, fileIn + ".BAK");
			/*
			if(File::Exists(fileIn))
			{
				File::Delete(fileIn);
			}
			*/
			File::Move(fileOut, fileIn);
		}
		else
		{
			File::Delete(fileOut);
		}
	}

	void convert_fix_t2bk(String^ fileIn)
	{
		FileStream^ fr = File::OpenRead(fileIn);
		BinaryReader^ br = gcnew BinaryReader(fr);

		int sig = br->ReadInt32();
		int version = br->ReadInt32();

		if(version > 5)
		{
			String^ fileOut = fileIn + ".tmp";
			if(File::Exists(fileOut))
			{
				File::Delete(fileOut);
			}
			FileStream^ fw = gcnew FileStream(fileOut, FileMode::Create, FileAccess::Write);
			BinaryWriter^ bw = gcnew BinaryWriter(fw);

			bw->Write(sig);
			bw->Write((int)5);

			int tileCount = br->ReadInt32();
			bw->Write(tileCount);
			bw->Write(br->ReadInt32());

			array<int>^ streamPositionsOrg = gcnew array<int>(tileCount);
			array<int>^ streamPositionsNew = gcnew array<int>(tileCount);

			// read old stream offsets
			for(int i=0; i<tileCount; i++)
			{
				streamPositionsOrg[i] = br->ReadInt32();
				// write placeholders, cause we currently don't know the fixed tile positions
				bw->Write((int)0);
			}

			// read & write tiles
			for(int i=0; i<tileCount; i++)
			{
				br->BaseStream->Position = streamPositionsOrg[i];
				streamPositionsNew[i] = (int)bw->BaseStream->Position;

				bw->Write(br->ReadInt32());
				bw->Write(br->ReadInt32());
				bw->Write(br->ReadSingle());
				bw->Write(br->ReadInt32());

				int count_1 = br->ReadInt32();
				bw->Write(count_1);
				int count_2 = br->ReadInt32();
				bw->Write(count_2);
				int count_3 = br->ReadInt32();
				bw->Write(count_3);
				int count_4 = br->ReadInt32();
				bw->Write(count_4);

				// version > 5 exclusion
				// skip 4 bytes of count_5
				br->ReadInt32();

				bw->Write(br->ReadBytes(count_1));
				bw->Write(br->ReadBytes(count_2));
				bw->Write(br->ReadBytes(count_3));
				bw->Write(br->ReadBytes(count_4));

				// version > 5 exclusion
				// skip the bytes of tile_5 by jumping to next tile offset at the beginning of the for loop

				this->Update();
			}

			// write new stream offsets
			bw->BaseStream->Position = 16;
			for(int i=0; i<tileCount; i++)
			{
				bw->Write(streamPositionsNew[i]);
			}

			fw->Close();
			bw->Close();

			fr->Close();
			br->Close();

			if(File::Exists(fileIn + ".BAK"))
			{
				File::Delete(fileIn + ".BAK");
			}
			File::Move(fileIn, fileIn + ".BAK");
			/*
			if(File::Exists(fileIn))
			{
				File::Delete(fileIn);
			}
			*/
			File::Move(fileOut, fileIn);
		}
		else
		{
			fr->Close();
			br->Close();
		}
	}
	void convert_save_terrain(String^ fileIn, String^ fileOut)
	{
		FileStream^ fr = File::OpenRead(fileIn);
		BinaryReader^ br = gcnew BinaryReader(fr);

		br->ReadInt32();
		int version = br->ReadInt32();

		array<int>^ terrainStreamPositions = gcnew array<int>(br->ReadInt32());

		br->ReadInt32();

		for(int i=0; i<terrainStreamPositions->Length; i++)
		{
			terrainStreamPositions[i] = br->ReadInt32();
		}

		array<mapT2bk^>^ mapTiles = gcnew array<mapT2bk^>(terrainStreamPositions->Length);

		for(int i=0; i<terrainStreamPositions->Length; i++)
		{
			mapTiles[i] = gcnew mapT2bk();

			br->BaseStream->Position = terrainStreamPositions[i];
			mapTiles[i]->zone = br->ReadInt32();
			mapTiles[i]->global_pixel_position = br->ReadInt32();
			mapTiles[i]->unknown_01 = br->ReadSingle();
			mapTiles[i]->pixel_size = br->ReadInt32();

			mapTiles[i]->hmap = gcnew array<unsigned char>(br->ReadInt32());
			mapTiles[i]->tile_2 = gcnew array<unsigned char>(br->ReadInt32());
			mapTiles[i]->tile_3 = gcnew array<unsigned char>(br->ReadInt32());
			mapTiles[i]->tile_4 = gcnew array<unsigned char>(br->ReadInt32());
			if(version > 5)
			{
				br->ReadInt32();
			}

			mapTiles[i]->hmap = br->ReadBytes(mapTiles[i]->hmap->Length);
			mapTiles[i]->tile_2 = br->ReadBytes(mapTiles[i]->tile_2->Length);
			mapTiles[i]->tile_3 = br->ReadBytes(mapTiles[i]->tile_3->Length);
			mapTiles[i]->tile_4 = br->ReadBytes(mapTiles[i]->tile_4->Length);

			mapTiles[i]->hmap = decompress(mapTiles[i]->hmap);
			mapTiles[i]->tile_2 = decompress(mapTiles[i]->tile_2);
			mapTiles[i]->tile_3 = decompress(mapTiles[i]->tile_3);
			mapTiles[i]->tile_4 = decompress(mapTiles[i]->tile_4);

			this->Update();
		}

		fr->Close();
		br->Close();

		// combine all t1 parts

		float height_scale = 800; // Stretch normalized height values

		array<float>^ t1map = gcnew array<float>(513*513);
		int x_offset;
		int y_offset;
		int pos;
		for(int i=0; i<mapTiles->Length; i++)
		{
			y_offset = (i/16*513*(33-1));
			x_offset = i%16*(33-1);

			for(int j=0; j<mapTiles[i]->hmap->Length/4; j++)
			{
				pos = y_offset + x_offset + j/33*513 + j%33;
				t1map[pos] = BitConverter::ToSingle(mapTiles[i]->hmap, 4*j) / height_scale;
			}

			this->Update();
		}

		File::Delete(fileOut);
		FileStream^ fw = gcnew FileStream(fileOut, FileMode::Create, FileAccess::Write);
		BinaryWriter^ bw = gcnew BinaryWriter(fw);

		for(int i=0; i<t1map->Length; i++)
		{
			bw->Write(t1map[i]);
		}

		fw->Close();
		bw->Close();
	}
	void convert_save_t2mk(String^ fileIn, String^ fileOut)
	{
		FileStream^ fr = File::OpenRead(fileIn);
		BinaryReader^ br = gcnew BinaryReader(fr);

		FileStream^ fw = gcnew FileStream(fileOut, FileMode::Create, FileAccess::Write);
		BinaryWriter^ bw = gcnew BinaryWriter(fw);

		mapT2mk^ debug = gcnew mapT2mk();
		debug->version = br->ReadInt32();
		debug->unknown_1 = br->ReadInt32();
		debug->count_1 = br->ReadInt32();
		debug->count_2 = br->ReadInt32();
		debug->unknown_2 = br->ReadInt32();

		debug->byte_positions = gcnew array<int>(debug->count_1);
		debug->blocks_1 = gcnew array<t2mkBlock_1^>(debug->count_2); 
		debug->blocks_2 = gcnew array<t2mkBlock_2^>(debug->count_1);

		// Read Positions
		for(int i=0; i<debug->byte_positions->Length; i++)
		{
			debug->byte_positions[i] = br->ReadInt32();
		}

		// Read Block 1
		for(int i=0; i<debug->blocks_1->Length; i++)
		{
			debug->blocks_1[i] = gcnew t2mkBlock_1();
			debug->blocks_1[i]->unknown_1 = br->ReadInt32();
			debug->blocks_1[i]->seperator = br->ReadInt32();
			debug->blocks_1[i]->unknown_2 = br->ReadInt32();
			debug->blocks_1[i]->unknown_3 = br->ReadInt32();
			debug->blocks_1[i]->unknown_4 = br->ReadSingle();
			debug->blocks_1[i]->unknown_5 = br->ReadSingle();
			debug->blocks_1[i]->unknown_6 = br->ReadInt32();
		}

		// Read Block 2
		for(int i=0; i<debug->blocks_2->Length; i++)
		{
			debug->blocks_2[i] = gcnew t2mkBlock_2();
			debug->blocks_2[i]->subblock_count = br->ReadInt32();
			debug->blocks_2[i]->sub_blocks = gcnew array<t2mkSubBlock^>(debug->blocks_2[i]->subblock_count);
			// Read the SubBlock Information
			for(int n=0; n<debug->blocks_2[i]->sub_blocks->Length; n++)
			{
				debug->blocks_2[i]->sub_blocks[n] = gcnew t2mkSubBlock();
				debug->blocks_2[i]->sub_blocks[n]->id = br->ReadInt32();
				debug->blocks_2[i]->sub_blocks[n]->byte_position = br->ReadInt32();
				debug->blocks_2[i]->sub_blocks[n]->byte_length = br->ReadInt32();
				debug->blocks_2[i]->sub_blocks[n]->byte_data = gcnew array<unsigned char>(debug->blocks_2[i]->sub_blocks[n]->byte_length);
			}
			// Read the SubBlock Data
			for(int n=0; n<debug->blocks_2[i]->sub_blocks->Length; n++)
			{
				debug->blocks_2[i]->sub_blocks[n]->byte_data = br->ReadBytes(debug->blocks_2[i]->sub_blocks[n]->byte_data->Length);

				array<unsigned char>^ deflate = decompress(debug->blocks_2[i]->sub_blocks[n]->byte_data);
				bw->Write(deflate->Length);
				bw->Write(deflate);
			}
		}

		fw->Close();
		bw->Close();

		fr->Close();
		br->Close();
	}
	
#pragma endregion
#pragma region PATH

	private: void InitializePath()
	{
		// Load Background Files
		if(Directory::Exists(Application::StartupPath + "\\maps\\path"))
		{
			array<String^>^ files = Directory::GetFiles(Application::StartupPath + "\\maps\\path");
			for(int i=0; i<files->Length; i++)
			{
				comboBox_pathBackground->Items->Add(files[i]->Substring(files[i]->LastIndexOf("\\")+1));
			}
		}
	}
	private: System::Void path_load(System::Object^  sender, System::EventArgs^  e)
	{
		OpenFileDialog^ load = gcnew OpenFileDialog();
		load->Filter = "Path Collection (*.sev)|*.sev|All Files (*.*)|*.*";
		if(load->ShowDialog() == Windows::Forms::DialogResult::OK && File::Exists(load->FileName))
		{
			try
			{
				Cursor = Windows::Forms::Cursors::AppStarting;

				FileStream^ fr = File::OpenRead(load->FileName);
				BinaryReader^ br = gcnew BinaryReader(fr);

				listBox_pathCollection->Items->Clear();

				PATHs->version = br->ReadInt32();
				PATHs->count = br->ReadInt32();
				PATHs->paths = gcnew array<path^>(PATHs->count);
				for(int i=0; i<PATHs->paths->Length;i++)
				{
					PATHs->paths[i] = gcnew path();
					PATHs->paths[i]->unknown_1 = br->ReadInt32();
					PATHs->paths[i]->id = br->ReadInt32();
					PATHs->paths[i]->seperator_1 = br->ReadInt32();
					PATHs->paths[i]->seperator_2 = br->ReadInt32();
					PATHs->paths[i]->count_points = br->ReadInt32();
					PATHs->paths[i]->points = gcnew array<path_point^>(PATHs->paths[i]->count_points);
					for(int n=0; n<PATHs->paths[i]->points->Length; n++)
					{
						PATHs->paths[i]->points[n] = gcnew path_point();
						PATHs->paths[i]->points[n]->x = br->ReadSingle();
						PATHs->paths[i]->points[n]->altitude = br->ReadSingle();
						PATHs->paths[i]->points[n]->z = br->ReadSingle();
						PATHs->paths[i]->points[n]->direction_x = br->ReadSingle();
						PATHs->paths[i]->points[n]->direction_altitude = br->ReadSingle();
						PATHs->paths[i]->points[n]->direction_z = br->ReadSingle();
					}
					PATHs->paths[i]->count_segments = br->ReadInt32();
					PATHs->paths[i]->segments = gcnew array<path_segment^>(PATHs->paths[i]->count_segments);
					for(int n=0; n<PATHs->paths[i]->segments->Length; n++)
					{
						PATHs->paths[i]->segments[n] = gcnew path_segment();
						PATHs->paths[i]->segments[n]->x_1 = br->ReadSingle();
						PATHs->paths[i]->segments[n]->altitude_1 = br->ReadSingle();
						PATHs->paths[i]->segments[n]->z_1 = br->ReadSingle();
						PATHs->paths[i]->segments[n]->x_2 = br->ReadSingle();
						PATHs->paths[i]->segments[n]->altitude_2 = br->ReadSingle();
						PATHs->paths[i]->segments[n]->z_2 = br->ReadSingle();
						PATHs->paths[i]->segments[n]->startpoint = br->ReadInt32();
						PATHs->paths[i]->segments[n]->endpoint = br->ReadInt32();
						PATHs->paths[i]->segments[n]->length = br->ReadSingle();
					}
					listBox_pathCollection->Items->Add(PATHs->paths[i]->id);
				}

				br->Close();
				fr->Close();

				this->textBox_pathFile->Text = load->FileName;

				if(listBox_pathCollection->Items->Count>0)
				{
					listBox_pathCollection->SelectedIndex = 0;
				}

				path_drawBackground();
				path_drawPath();

				Cursor = Windows::Forms::Cursors::Default;
			}
			catch(Exception^ e)
			{
				MessageBox::Show("LOADING ERROR!\n" + e->Message);
				Cursor = Windows::Forms::Cursors::Default;
			}
		}
	}
	private: System::Void path_save(System::Object^  sender, System::EventArgs^  e)
	{
		if(File::Exists(textBox_pathFile->Text))
		{
			try
			{
				Cursor = Windows::Forms::Cursors::AppStarting;

				FileStream^ fw = gcnew FileStream(textBox_pathFile->Text, FileMode::Create, FileAccess::Write);
				BinaryWriter^ bw = gcnew BinaryWriter(fw);

				bw->Write(PATHs->version);
				bw->Write(PATHs->count);
				for(int i=0; i<PATHs->paths->Length;i++)
				{
					bw->Write(PATHs->paths[i]->unknown_1);
					bw->Write(PATHs->paths[i]->id);
					bw->Write(PATHs->paths[i]->seperator_1);
					bw->Write(PATHs->paths[i]->seperator_2);
					bw->Write(PATHs->paths[i]->count_points);
					for(int n=0; n<PATHs->paths[i]->points->Length; n++)
					{
						bw->Write(PATHs->paths[i]->points[n]->x);
						bw->Write(PATHs->paths[i]->points[n]->altitude);
						bw->Write(PATHs->paths[i]->points[n]->z);
						bw->Write(PATHs->paths[i]->points[n]->direction_x);
						bw->Write(PATHs->paths[i]->points[n]->direction_altitude);
						bw->Write(PATHs->paths[i]->points[n]->direction_z);
					}
					bw->Write(PATHs->paths[i]->count_segments);
					for(int n=0; n<PATHs->paths[i]->segments->Length; n++)
					{
						bw->Write(PATHs->paths[i]->segments[n]->x_1);
						bw->Write(PATHs->paths[i]->segments[n]->altitude_1);
						bw->Write(PATHs->paths[i]->segments[n]->z_1);
						bw->Write(PATHs->paths[i]->segments[n]->x_2);
						bw->Write(PATHs->paths[i]->segments[n]->altitude_2);
						bw->Write(PATHs->paths[i]->segments[n]->z_2);
						bw->Write(PATHs->paths[i]->segments[n]->startpoint);
						bw->Write(PATHs->paths[i]->segments[n]->endpoint);
						bw->Write(PATHs->paths[i]->segments[n]->length);
					}
				}

				bw->Close();
				fw->Close();

				Cursor = Windows::Forms::Cursors::Default;
			}
			catch(Exception^ e)
			{
				MessageBox::Show("SAVING ERROR!\n" + e->Message);
				Cursor = Windows::Forms::Cursors::Default;
			}
		}
	}
	private: void path_drawBackground()
	{
		Cursor = Cursors::AppStarting;

		if(checkBox_pathBackground->Checked && comboBox_pathBackground->SelectedItem && File::Exists(Application::StartupPath + "\\maps\\path\\" + comboBox_pathBackground->SelectedItem->ToString()))
		{
			pictureBox_path->BackgroundImage = Image::FromFile(Application::StartupPath + "\\maps\\path\\" + comboBox_pathBackground->SelectedItem->ToString());
		}
		else
		{
			pictureBox_path->BackgroundImage = gcnew Bitmap(1024, 1024);
		}
		pictureBox_path->Width = pictureBox_path->BackgroundImage->Width;
		pictureBox_path->Height = pictureBox_path->BackgroundImage->Height;
		GC::Collect();

		Cursor = Cursors::Default;
	}
	private: void path_drawPath()
	{
		Cursor = Cursors::AppStarting;

		if(PATHs->paths && listBox_pathCollection->SelectedIndex>-1)
		{
			try
			{
				pictureBox_path->Image = gcnew Bitmap(pictureBox_path->Width, pictureBox_path->Height);
				Graphics^ g = Graphics::FromImage(pictureBox_path->Image);
				Color clearColor = Color::FromArgb(0, 0, 0, 0);
				g->Clear(clearColor);

				Pen^ segment = gcnew Pen(Color::LightGreen);
				Pen^ path = gcnew Pen(Color::Blue);
				Pen^ mark = gcnew Pen(Color::Red);

				// Draw Points Polygon
				array<Rectangle>^ rects = gcnew array<Rectangle>(PATHs->paths[listBox_pathCollection->SelectedIndex]->points->Length);
				array<Point>^ points = gcnew array<Point>(PATHs->paths[listBox_pathCollection->SelectedIndex]->points->Length);
				for(int i=0; i<PATHs->paths[listBox_pathCollection->SelectedIndex]->points->Length; i++)
				{
					int x = Convert::ToInt32(Math::Round(PATHs->paths[listBox_pathCollection->SelectedIndex]->points[i]->x+(pictureBox_path->Image->Width/2)-0.5));
					int y = Convert::ToInt32(Math::Round(-PATHs->paths[listBox_pathCollection->SelectedIndex]->points[i]->z+(pictureBox_path->Image->Height/2)-0.5));
					rects[i] = Rectangle(x-1, y-1, 2, 2);
					points[i] = Point(x, y);
				}
				if(points->Length>1)
				{
					g->DrawPolygon(path, points);
				}
				if(rects->Length>0)
				{
					g->DrawRectangles(path, rects);
					// Draw selected segment
					if(listBox_pathSegments->SelectedIndex>-1)
					{
						int p_0 = PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[listBox_pathSegments->SelectedIndex]->startpoint;
						int x_1 = Convert::ToInt32(Math::Round(PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[listBox_pathSegments->SelectedIndex]->x_1+(pictureBox_path->Image->Width/2)-0.5));
						int y_1 = Convert::ToInt32(Math::Round(-PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[listBox_pathSegments->SelectedIndex]->z_1+(pictureBox_path->Image->Height/2)-0.5));
						int x_2 = Convert::ToInt32(Math::Round(PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[listBox_pathSegments->SelectedIndex]->x_2+(pictureBox_path->Image->Width/2)-0.5));
						int y_2 = Convert::ToInt32(Math::Round(-PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[listBox_pathSegments->SelectedIndex]->z_2+(pictureBox_path->Image->Height/2)-0.5));
						int p_3 = PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[listBox_pathSegments->SelectedIndex]->endpoint;

						g->DrawLines(segment, gcnew array<Point>{points[p_0], Point(x_1, y_1), Point(x_2, y_2), points[p_3]});
						g->DrawRectangles(segment, gcnew array<Rectangle>{rects[p_0], Rectangle(x_1-1, y_1-1,2,2), Rectangle(x_2-1, y_2-1,2,2), rects[p_3]});
					}
					// Draw selected point
					if(listBox_pathPoints->SelectedIndex>-1 && listBox_pathPoints->SelectedIndex<rects->Length)
					{
						g->DrawRectangle(mark, rects[listBox_pathPoints->SelectedIndex]);
					}
				}
				GC::Collect();
				pictureBox_path->Refresh();
			}
			catch(...)
			{
				// Prevent Double Paint on fast Clicking in Pointlist
			}
		}

		Cursor = Cursors::Default;
	}
	private: void path_scroll()
	{
		if(PATHs->paths && listBox_pathCollection->SelectedIndex>-1 && PATHs->paths[listBox_pathCollection->SelectedIndex]->points->Length>0)
		{
			// Calculate Path Mean Center
			float mean_x = 0;
			float mean_z = 0;
			for(int i=0; i<PATHs->paths[listBox_pathCollection->SelectedIndex]->points->Length; i++)
			{
				mean_x += PATHs->paths[listBox_pathCollection->SelectedIndex]->points[i]->x;
				mean_z += PATHs->paths[listBox_pathCollection->SelectedIndex]->points[i]->z;
			}
			mean_x = mean_x/PATHs->paths[listBox_pathCollection->SelectedIndex]->points->Length;
			mean_z = mean_z/PATHs->paths[listBox_pathCollection->SelectedIndex]->points->Length;

			// Calculate Scroll Values
			int x = Convert::ToInt32(Math::Round(mean_x+(pictureBox_path->Image->Width/2)-0.5))-(panel_path->ClientSize.Width/2);
			int y = Convert::ToInt32(Math::Round(-mean_z+(pictureBox_path->Image->Height/2)-0.5))-(panel_path->ClientSize.Height/2);
			if(x>panel_path->HorizontalScroll->Minimum && x<panel_path->HorizontalScroll->Maximum)
			{
				panel_path->HorizontalScroll->Value = x;
			}
			if(y>panel_path->VerticalScroll->Minimum && y<panel_path->VerticalScroll->Maximum)
			{
				panel_path->VerticalScroll->Value = y;
			}
		}
	}
	void path_editSegmentLength(int index)
	{
		if(PATHs->paths && listBox_pathCollection->SelectedIndex>-1 && index>-1 && index<PATHs->paths[listBox_pathCollection->SelectedIndex]->segments->Length)
		{
			int point_0 = PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[index]->startpoint;
			int point_3 = PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[index]->endpoint;

			if(point_0<PATHs->paths[listBox_pathCollection->SelectedIndex]->points->Length && point_3<PATHs->paths[listBox_pathCollection->SelectedIndex]->points->Length)
			{
				double x_0 = PATHs->paths[listBox_pathCollection->SelectedIndex]->points[point_0]->x;
				double alt_0 = PATHs->paths[listBox_pathCollection->SelectedIndex]->points[point_0]->altitude;
				double z_0 = PATHs->paths[listBox_pathCollection->SelectedIndex]->points[point_0]->z;

				double x_1 = PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[index]->x_1;
				double alt_1 = PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[index]->altitude_1;
				double z_1 = PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[index]->z_1;

				double x_2 = PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[index]->x_2;
				double alt_2 = PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[index]->altitude_2;
				double z_2 = PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[index]->z_2;

				double x_3 = PATHs->paths[listBox_pathCollection->SelectedIndex]->points[point_3]->x;
				double alt_3 = PATHs->paths[listBox_pathCollection->SelectedIndex]->points[point_3]->altitude;
				double z_3 = PATHs->paths[listBox_pathCollection->SelectedIndex]->points[point_3]->z;

				PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[index]->length =
					Convert::ToSingle(
						Math::Sqrt(Math::Pow(x_3-x_0, 2) + Math::Pow(alt_3-alt_0, 2) + Math::Pow(z_3-z_0, 2))
						/*
						Math::Sqrt(Math::Pow(x_1-x_0, 2) + Math::Pow(alt_1-alt_0, 2) + Math::Pow(z_1-z_0, 2)) +
						Math::Sqrt(Math::Pow(x_2-x_1, 2) + Math::Pow(alt_2-alt_1, 2) + Math::Pow(z_2-z_1, 2)) +
						Math::Sqrt(Math::Pow(x_3-x_2, 2) + Math::Pow(alt_3-alt_2, 2) + Math::Pow(z_3-z_2, 2))
						*/
					);
				if(listBox_pathSegments->SelectedIndex == index)
				{
					textBox_pathSegmentLength->Text = PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[index]->length.ToString("F3");
				}
			}
		}
	}
	private: System::Void path_switchBackground(System::Object^  sender, System::EventArgs^  e)
	{
		path_drawBackground();
		path_drawPath();
		path_scroll();
	}
	private: System::Void path_tooltip(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		
		if(e->X>-1 && e->X<pictureBox_path->BackgroundImage->Width && e->Y>-1 && e->Y<pictureBox_path->BackgroundImage->Height)
		{
			String^ text = "X: " + (e->X-(pictureBox_path->BackgroundImage->Width/2)+0.5).ToString("F1") + "\nZ: " + (-(e->Y)+(pictureBox_path->BackgroundImage->Height/2)-0.5).ToString("F1");
			if(text != toolTip->GetToolTip(pictureBox_path))
			{
				toolTip->SetToolTip(pictureBox_path, text);
			}
		}
	}
	private: System::Void path_change(System::Object^  sender, System::EventArgs^  e)
	{
		if(PATHs->paths && listBox_pathCollection->SelectedIndex>-1)
		{
			textBox_pathID->Text = PATHs->paths[listBox_pathCollection->SelectedIndex]->id.ToString();
			textBox_pathUnknown1->Text = PATHs->paths[listBox_pathCollection->SelectedIndex]->unknown_1.ToString();
			textBox_pathSeperator1->Text = PATHs->paths[listBox_pathCollection->SelectedIndex]->seperator_1.ToString();
			textBox_pathSeperator2->Text = PATHs->paths[listBox_pathCollection->SelectedIndex]->seperator_2.ToString();

			listBox_pathPoints->Items->Clear();
			for(int i=0; i<PATHs->paths[listBox_pathCollection->SelectedIndex]->points->Length; i++)
			{
				listBox_pathPoints->Items->Add("[" + i + "]");
			}
			listBox_pathSegments->Items->Clear();
			for(int i=0; i<PATHs->paths[listBox_pathCollection->SelectedIndex]->segments->Length; i++)
			{
				listBox_pathSegments->Items->Add("[" + PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[i]->startpoint + "," + PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[i]->endpoint + "]");
			}
			path_drawPath();
			path_scroll();
		}
		else
		{
			textBox_pathID->Clear();
			textBox_pathUnknown1->Clear();
			textBox_pathSeperator1->Clear();
			textBox_pathSeperator2->Clear();
		}
	}
	private: System::Void path_changePoint(System::Object^  sender, System::EventArgs^  e)
	{
		if(listBox_pathPoints->SelectedIndex>-1)
		{
			textBox_pathPointX->Text = PATHs->paths[listBox_pathCollection->SelectedIndex]->points[listBox_pathPoints->SelectedIndex]->x .ToString("F3");
			textBox_pathPointAlt->Text = PATHs->paths[listBox_pathCollection->SelectedIndex]->points[listBox_pathPoints->SelectedIndex]->altitude .ToString("F3");
			textBox_pathPointZ->Text = PATHs->paths[listBox_pathCollection->SelectedIndex]->points[listBox_pathPoints->SelectedIndex]->z .ToString("F3");
			textBox_pathDirectionX->Text = PATHs->paths[listBox_pathCollection->SelectedIndex]->points[listBox_pathPoints->SelectedIndex]->direction_x .ToString("F3");
			textBox_pathDirectionAlt->Text = PATHs->paths[listBox_pathCollection->SelectedIndex]->points[listBox_pathPoints->SelectedIndex]->direction_altitude .ToString("F3");
			textBox_pathDirectionZ->Text = PATHs->paths[listBox_pathCollection->SelectedIndex]->points[listBox_pathPoints->SelectedIndex]->direction_z .ToString("F3");
		}
		else
		{
			textBox_pathPointX->Clear();
			textBox_pathPointAlt->Clear();
			textBox_pathPointZ->Clear();
			textBox_pathDirectionX->Clear();
			textBox_pathDirectionAlt->Clear();
			textBox_pathDirectionZ->Clear();
		}
		path_drawPath();
	}
	private: System::Void path_changeSegment(System::Object^  sender, System::EventArgs^  e)
	{
		if(listBox_pathSegments->SelectedIndex>-1)
		{
			textBox_pathSegmentHeadX->Text = PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[listBox_pathSegments->SelectedIndex]->x_1.ToString("F3");
			textBox_pathSegmentHeadAlt->Text = PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[listBox_pathSegments->SelectedIndex]->altitude_1.ToString("F3");
			textBox_pathSegmentHeadZ->Text = PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[listBox_pathSegments->SelectedIndex]->z_1.ToString("F3");
			textBox_pathSegmentTailX->Text = PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[listBox_pathSegments->SelectedIndex]->x_2.ToString("F3");
			textBox_pathSegmentTailAlt->Text = PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[listBox_pathSegments->SelectedIndex]->altitude_2.ToString("F3");
			textBox_pathSegmentTailZ->Text = PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[listBox_pathSegments->SelectedIndex]->z_2.ToString("F3");
			textBox_pathSegmentStart->Text = PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[listBox_pathSegments->SelectedIndex]->startpoint.ToString();
			textBox_pathSegmentEnd->Text = PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[listBox_pathSegments->SelectedIndex]->endpoint.ToString();
			textBox_pathSegmentLength->Text = PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[listBox_pathSegments->SelectedIndex]->length.ToString("F3");
		}
		else
		{
			textBox_pathSegmentHeadX->Clear();
			textBox_pathSegmentHeadAlt->Clear();
			textBox_pathSegmentHeadZ->Clear();
			textBox_pathSegmentTailX->Clear();
			textBox_pathSegmentTailAlt->Clear();
			textBox_pathSegmentTailZ->Clear();
			textBox_pathSegmentStart->Clear();
			textBox_pathSegmentEnd->Clear();
			textBox_pathSegmentLength->Clear();
		}
		path_drawPath();
	}
	private: System::Void path_add(System::Object^  sender, System::EventArgs^  e)
	{
		if(PATHs->paths)
		{
			if(contextMenuStrip_path->SourceControl == listBox_pathCollection)
			{
				PATHs->count++;
				Array::Resize(PATHs->paths, PATHs->paths->Length+1);
				PATHs->paths[PATHs->paths->Length-1] = gcnew path();
				PATHs->paths[PATHs->paths->Length-1]->id = 0;
				PATHs->paths[PATHs->paths->Length-1]->unknown_1 = 3;
				PATHs->paths[PATHs->paths->Length-1]->seperator_1 = -1;
				PATHs->paths[PATHs->paths->Length-1]->seperator_2 = -1;
				PATHs->paths[PATHs->paths->Length-1]->count_points = 0;
				PATHs->paths[PATHs->paths->Length-1]->points = gcnew array<path_point^>(0);
				PATHs->paths[PATHs->paths->Length-1]->count_segments = 0;
				PATHs->paths[PATHs->paths->Length-1]->segments = gcnew array<path_segment^>(0);

				listBox_pathCollection->Items->Add("0");
				listBox_pathCollection->SelectedIndex = listBox_pathCollection->Items->Count-1;
			}
			if(listBox_pathCollection->SelectedIndex>-1 && contextMenuStrip_path->SourceControl == listBox_pathPoints)
			{
				PATHs->paths[listBox_pathCollection->SelectedIndex]->count_points++;
				Array::Resize(PATHs->paths[listBox_pathCollection->SelectedIndex]->points, PATHs->paths[listBox_pathCollection->SelectedIndex]->points->Length+1);
				PATHs->paths[listBox_pathCollection->SelectedIndex]->points[PATHs->paths[listBox_pathCollection->SelectedIndex]->points->Length-1] = gcnew path_point();
				PATHs->paths[listBox_pathCollection->SelectedIndex]->points[PATHs->paths[listBox_pathCollection->SelectedIndex]->points->Length-1]->x = 0;
				PATHs->paths[listBox_pathCollection->SelectedIndex]->points[PATHs->paths[listBox_pathCollection->SelectedIndex]->points->Length-1]->altitude = 0;
				PATHs->paths[listBox_pathCollection->SelectedIndex]->points[PATHs->paths[listBox_pathCollection->SelectedIndex]->points->Length-1]->z = 0;
				PATHs->paths[listBox_pathCollection->SelectedIndex]->points[PATHs->paths[listBox_pathCollection->SelectedIndex]->points->Length-1]->direction_x = 0;
				PATHs->paths[listBox_pathCollection->SelectedIndex]->points[PATHs->paths[listBox_pathCollection->SelectedIndex]->points->Length-1]->direction_altitude = 0;
				PATHs->paths[listBox_pathCollection->SelectedIndex]->points[PATHs->paths[listBox_pathCollection->SelectedIndex]->points->Length-1]->direction_z = 0;

				listBox_pathPoints->Items->Add("[" + (PATHs->paths[listBox_pathCollection->SelectedIndex]->points->Length-1) + "]");
				listBox_pathPoints->SelectedIndex = listBox_pathPoints->Items->Count-1;
			}
			if(listBox_pathCollection->SelectedIndex>-1  && contextMenuStrip_path->SourceControl == listBox_pathSegments)
			{
				PATHs->paths[listBox_pathCollection->SelectedIndex]->count_segments++;
				Array::Resize(PATHs->paths[listBox_pathCollection->SelectedIndex]->segments, PATHs->paths[listBox_pathCollection->SelectedIndex]->segments->Length+1);
				PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[PATHs->paths[listBox_pathCollection->SelectedIndex]->segments->Length-1] = gcnew path_segment();
				PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[PATHs->paths[listBox_pathCollection->SelectedIndex]->segments->Length-1]->x_1 = 0;
				PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[PATHs->paths[listBox_pathCollection->SelectedIndex]->segments->Length-1]->altitude_1 = 0;
				PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[PATHs->paths[listBox_pathCollection->SelectedIndex]->segments->Length-1]->z_1 = 0;
				PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[PATHs->paths[listBox_pathCollection->SelectedIndex]->segments->Length-1]->x_2 = 0;
				PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[PATHs->paths[listBox_pathCollection->SelectedIndex]->segments->Length-1]->altitude_2 = 0;
				PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[PATHs->paths[listBox_pathCollection->SelectedIndex]->segments->Length-1]->z_2 = 0;
				PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[PATHs->paths[listBox_pathCollection->SelectedIndex]->segments->Length-1]->startpoint = 0;
				PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[PATHs->paths[listBox_pathCollection->SelectedIndex]->segments->Length-1]->endpoint = 0;
				PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[PATHs->paths[listBox_pathCollection->SelectedIndex]->segments->Length-1]->length = 0;

				listBox_pathSegments->Items->Add("[-0,-0]");
				listBox_pathSegments->SelectedIndex = listBox_pathSegments->Items->Count-1;
			}
		}
	}
	private: System::Void path_delete(System::Object^  sender, System::EventArgs^  e)
	{
		if(PATHs)
		{
			if(contextMenuStrip_path->SourceControl == listBox_pathCollection && listBox_pathCollection->SelectedIndex>-1)
			{
				if(PATHs->count>0)
				{
					PATHs->count--;

					array<path^>^ temp = gcnew array<path^>(PATHs->count);
					Array::Copy(PATHs->paths, 0, temp, 0, listBox_pathCollection->SelectedIndex);
					Array::Copy(PATHs->paths, listBox_pathCollection->SelectedIndex+1, temp, listBox_pathCollection->SelectedIndex, PATHs->count - listBox_pathCollection->SelectedIndex);
					PATHs->paths = temp;

					listBox_pathCollection->Items->RemoveAt(listBox_pathCollection->SelectedIndex);
					listBox_pathPoints->Items->Clear();
					listBox_pathSegments->Items->Clear();
				}
			}
			if(contextMenuStrip_path->SourceControl == listBox_pathPoints && listBox_pathCollection->SelectedIndex>-1 && listBox_pathPoints->SelectedIndex>-1)
			{
				if(PATHs->paths[listBox_pathCollection->SelectedIndex]->count_points>0)
				{
					PATHs->paths[listBox_pathCollection->SelectedIndex]->count_points--;

					array<path_point^>^ temp = gcnew array<path_point^>(PATHs->paths[listBox_pathCollection->SelectedIndex]->count_points);
					Array::Copy(PATHs->paths[listBox_pathCollection->SelectedIndex]->points, 0, temp, 0, listBox_pathPoints->SelectedIndex);
					Array::Copy(PATHs->paths[listBox_pathCollection->SelectedIndex]->points, listBox_pathPoints->SelectedIndex+1, temp, listBox_pathPoints->SelectedIndex, PATHs->paths[listBox_pathCollection->SelectedIndex]->count_points - listBox_pathPoints->SelectedIndex);
					PATHs->paths[listBox_pathCollection->SelectedIndex]->points = temp;

					listBox_pathPoints->Items->Clear();
					for(int i=0; i<PATHs->paths[listBox_pathCollection->SelectedIndex]->points->Length; i++)
					{
						listBox_pathPoints->Items->Add("[" + i + "]");
					}
					path_drawPath();
				}
			}
			if(contextMenuStrip_path->SourceControl == listBox_pathSegments && listBox_pathCollection->SelectedIndex>-1 && listBox_pathSegments->SelectedIndex>-1)
			{
				if(PATHs->paths[listBox_pathCollection->SelectedIndex]->count_segments>0)
				{
					PATHs->paths[listBox_pathCollection->SelectedIndex]->count_segments--;

					array<path_segment^>^ temp = gcnew array<path_segment^>(PATHs->paths[listBox_pathCollection->SelectedIndex]->count_segments);
					Array::Copy(PATHs->paths[listBox_pathCollection->SelectedIndex]->segments, 0, temp, 0, listBox_pathSegments->SelectedIndex);
					Array::Copy(PATHs->paths[listBox_pathCollection->SelectedIndex]->segments, listBox_pathSegments->SelectedIndex+1, temp, listBox_pathSegments->SelectedIndex, PATHs->paths[listBox_pathCollection->SelectedIndex]->count_segments - listBox_pathSegments->SelectedIndex);
					PATHs->paths[listBox_pathCollection->SelectedIndex]->segments = temp;

					listBox_pathSegments->Items->RemoveAt(listBox_pathSegments->SelectedIndex);
					path_drawPath();
				}
			}
		}
	}
	private: System::Void path_editValue(System::Object^  sender, System::EventArgs^  e)
	{
		try
		{
			if(listBox_pathCollection->SelectedIndex>-1)
			{
				if((Control^)sender == textBox_pathID)
				{
					PATHs->paths[listBox_pathCollection->SelectedIndex]->id = Convert::ToInt32(textBox_pathID->Text);
					listBox_pathCollection->Items[listBox_pathCollection->SelectedIndex] = textBox_pathID->Text;
				}
				if((Control^)sender == textBox_pathUnknown1)
				{
					PATHs->paths[listBox_pathCollection->SelectedIndex]->unknown_1 = Convert::ToInt32(textBox_pathUnknown1->Text);
				}
				if((Control^)sender == textBox_pathSeperator1)
				{
					PATHs->paths[listBox_pathCollection->SelectedIndex]->seperator_1 = Convert::ToInt32(textBox_pathSeperator1->Text);
				}
				if((Control^)sender == textBox_pathSeperator2)
				{
					PATHs->paths[listBox_pathCollection->SelectedIndex]->seperator_2 = Convert::ToInt32(textBox_pathSeperator2->Text);
				}

				if(listBox_pathPoints->SelectedIndex>-1)
				{
					if((Control^)sender == textBox_pathPointX)
					{
						PATHs->paths[listBox_pathCollection->SelectedIndex]->points[listBox_pathPoints->SelectedIndex]->x = Convert::ToSingle(textBox_pathPointX->Text);
						path_editSegmentLength(listBox_pathPoints->SelectedIndex-1);
						path_editSegmentLength(listBox_pathPoints->SelectedIndex);
					}
					if((Control^)sender == textBox_pathPointAlt)
					{
						PATHs->paths[listBox_pathCollection->SelectedIndex]->points[listBox_pathPoints->SelectedIndex]->altitude = Convert::ToSingle(textBox_pathPointAlt->Text);
						path_editSegmentLength(listBox_pathPoints->SelectedIndex-1);
						path_editSegmentLength(listBox_pathPoints->SelectedIndex);
					}
					if((Control^)sender == textBox_pathPointZ)
					{
						PATHs->paths[listBox_pathCollection->SelectedIndex]->points[listBox_pathPoints->SelectedIndex]->z = Convert::ToSingle(textBox_pathPointZ->Text);
						path_editSegmentLength(listBox_pathPoints->SelectedIndex-1);
						path_editSegmentLength(listBox_pathPoints->SelectedIndex);
					}
					if((Control^)sender == textBox_pathDirectionX)
					{
						PATHs->paths[listBox_pathCollection->SelectedIndex]->points[listBox_pathPoints->SelectedIndex]->direction_x = Convert::ToSingle(textBox_pathDirectionX->Text);
					}
					if((Control^)sender == textBox_pathDirectionAlt)
					{
						PATHs->paths[listBox_pathCollection->SelectedIndex]->points[listBox_pathPoints->SelectedIndex]->direction_altitude = Convert::ToSingle(textBox_pathDirectionAlt->Text);
					}
					if((Control^)sender == textBox_pathDirectionZ)
					{
						PATHs->paths[listBox_pathCollection->SelectedIndex]->points[listBox_pathPoints->SelectedIndex]->direction_z = Convert::ToSingle(textBox_pathDirectionZ->Text);
					}
				}

				if(listBox_pathSegments->SelectedIndex>-1)
				{
					if((Control^)sender == textBox_pathSegmentHeadX)
					{
						PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[listBox_pathSegments->SelectedIndex]->x_1 = Convert::ToSingle(textBox_pathSegmentHeadX->Text);
					}
					if((Control^)sender == textBox_pathSegmentHeadAlt)
					{
						PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[listBox_pathSegments->SelectedIndex]->altitude_1 = Convert::ToSingle(textBox_pathSegmentHeadAlt->Text);
					}
					if((Control^)sender == textBox_pathSegmentHeadZ)
					{
						PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[listBox_pathSegments->SelectedIndex]->z_1 = Convert::ToSingle(textBox_pathSegmentHeadZ->Text);
					}
					if((Control^)sender == textBox_pathSegmentTailX)
					{
						PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[listBox_pathSegments->SelectedIndex]->x_2 = Convert::ToSingle(textBox_pathSegmentTailX->Text);
					}
					if((Control^)sender == textBox_pathSegmentTailAlt)
					{
						PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[listBox_pathSegments->SelectedIndex]->altitude_2 = Convert::ToSingle(textBox_pathSegmentTailAlt->Text);
					}
					if((Control^)sender == textBox_pathSegmentTailZ)
					{
						PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[listBox_pathSegments->SelectedIndex]->z_2 = Convert::ToSingle(textBox_pathSegmentTailZ->Text);
					}
					if((Control^)sender == textBox_pathSegmentStart)
					{
						PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[listBox_pathSegments->SelectedIndex]->startpoint = Convert::ToInt32(textBox_pathSegmentStart->Text);
						listBox_pathSegments->Items[listBox_pathSegments->SelectedIndex] = "[" + PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[listBox_pathSegments->SelectedIndex]->startpoint + "," + PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[listBox_pathSegments->SelectedIndex]->endpoint + "]";
						path_editSegmentLength(listBox_pathSegments->SelectedIndex);
					}
					if((Control^)sender == textBox_pathSegmentEnd)
					{
						PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[listBox_pathSegments->SelectedIndex]->endpoint = Convert::ToInt32(textBox_pathSegmentEnd->Text);
						listBox_pathSegments->Items[listBox_pathSegments->SelectedIndex] = "[" + PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[listBox_pathSegments->SelectedIndex]->startpoint + "," + PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[listBox_pathSegments->SelectedIndex]->endpoint + "]";
						path_editSegmentLength(listBox_pathSegments->SelectedIndex);
					}
					if((Control^)sender == textBox_pathSegmentLength)
					{
						PATHs->paths[listBox_pathCollection->SelectedIndex]->segments[listBox_pathSegments->SelectedIndex]->length = Convert::ToSingle(textBox_pathSegmentLength->Text);
					}
				}

				path_drawPath();
			}
		}
		catch(...)
		{
			MessageBox::Show("ERROR\nValue must be in the correct format!");
		}
	}

#pragma endregion
#pragma region HMAP

	private: void InitializeHmap()
	{
		// Initialize Color Schemes
		{
			array<int>^ jet = gcnew array<int>(511);

			int tempvalue = -129; // DarkBlue
			for(int n=0; n<128; n++)
			{
				tempvalue += (256+1);
				jet[n] = tempvalue;
			}
			// tempvalue = 32766 -> DeepSkyBlue ?
			for(int n=128; n<256; n++)
			{
				tempvalue += (256*256+256-1);
				jet[n] = tempvalue;
			}
			// tempvalue = 8388479 -> PaleGreen ?
			for(int n=256; n<383; n++)
			{
				tempvalue += (256*256-256-1);
				jet[n] = tempvalue;
			}
			// tempvalue = 16744065 -> DarkOrange ?
			for(int n=383; n<447; n++)
			{
				tempvalue -= (2*256);
				jet[n] = tempvalue;
			}
			// tempvalue = 16711680 -> Red
			for(int n=447; n<511; n++)
			{
				tempvalue -= (2*256*256);
				jet[n] = tempvalue;
			}
			// tempvalue = 8323072 -> DarkRed

			HMAP->ColorScheme = jet;
		}

		colorValueExpansion = gcnew ::Controls::ColorExpansionBar();
		colorValueExpansion->MaxValue = 800;
		colorValueExpansion->MinValue = 0;
		colorValueExpansion->Location = System::Drawing::Point(tabPage1->Width-60-1, 0);
		colorValueExpansion->Width = 60;
		colorValueExpansion->Height = tabPage1->Height-3;
		colorValueExpansion->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) | System::Windows::Forms::AnchorStyles::Right);
		tabPage1->Controls->Add(colorValueExpansion);
		colorValueExpansion->RangeChanged += gcnew ::Controls::ColorExpansionBar::RangeEventHandler(this, &MainWindow::hmap_drawBackground);
	}
	private: System::Void hmap_load(System::Object^  sender, System::EventArgs^  e)
	{
		OpenFileDialog^ load = gcnew OpenFileDialog();
		load->Filter = "Height Map (*.hmap)|*.hmap|All Files (*.*)|*.*";
		if(load->ShowDialog() == Windows::Forms::DialogResult::OK && File::Exists(load->FileName))
		{
			try
			{
				Cursor = Windows::Forms::Cursors::AppStarting;

				FileStream^ fr = File::OpenRead(load->FileName);
				BinaryReader^ br = gcnew BinaryReader(fr);

				HMAP->Heights = gcnew array<float>(513*513);

				for(int i=0; i<513*513; i++)
				{
					HMAP->Heights[i] = br->ReadSingle();
				}

				br->Close();
				fr->Close();

				this->textBox_hmapFile->Text = load->FileName;

				hmap_drawBackground();

				Cursor = Windows::Forms::Cursors::Default;
			}
			catch(Exception^ e)
			{
				MessageBox::Show("LOADING ERROR!\n" + e->Message);
				Cursor = Windows::Forms::Cursors::Default;
			}
		}
	}
	private: System::Void hmap_save(System::Object^  sender, System::EventArgs^  e)
	{
		if(HMAP->Heights && File::Exists(textBox_hmapFile->Text))
		{
			try
			{
				Cursor = Windows::Forms::Cursors::AppStarting;

				FileStream^ fw = gcnew FileStream(textBox_hmapFile->Text, FileMode::Create, FileAccess::Write);
				BinaryWriter^ bw = gcnew BinaryWriter(fw);

				for(int i=0; i<HMAP->Heights->Length; i++)
				{
					bw->Write(HMAP->Heights[i]);
				}

				bw->Close();
				fw->Close();

				Cursor = Windows::Forms::Cursors::Default;
			}
			catch(Exception^ e)
			{
				MessageBox::Show("SAVING ERROR!\n" + e->Message);
				Cursor = Windows::Forms::Cursors::Default;
			}
		}
	}
	private: System::Void hmap_export(System::Object^ sender, System::EventArgs^ e)
	{
		if(HMAP->Heights && File::Exists(textBox_hmapFile->Text))
		{
			try
			{
				Cursor = Windows::Forms::Cursors::AppStarting;

				Bitmap^ bmp = gcnew Bitmap(513, 513,Imaging::PixelFormat::Format32bppArgb);
				array<unsigned char>^ bytes;

				Imaging::BitmapData^ bData = bmp->LockBits(Rectangle(Point(), Drawing::Size(513, 513)), Imaging::ImageLockMode::WriteOnly, Imaging::PixelFormat::Format32bppArgb);
				unsigned char *FrameBytes = (unsigned char*)(void*)bData->Scan0; 
				for(int i=0; i<513*513; i++)
				{
					bytes = BitConverter::GetBytes(HMAP->Heights[i]);
					FrameBytes[4*i+0] = bytes[0];
					FrameBytes[4*i+1] = bytes[1];
					FrameBytes[4*i+2] = bytes[2];
					FrameBytes[4*i+3] = bytes[3];
				}
				bmp->UnlockBits(bData);
				bmp->Save(textBox_hmapFile->Text + ".png", Imaging::ImageFormat::Png);
				delete bmp;

				Cursor = Windows::Forms::Cursors::Default;
			}
			catch(Exception^ e)
			{
				MessageBox::Show("EXPORT ERROR!\n" + e->Message);
				Cursor = Windows::Forms::Cursors::Default;
			}
		}
	}
	private: System::Void hmap_import(System::Object^ sender, System::EventArgs^ e)
	{
		if(HMAP->Heights && File::Exists(textBox_hmapFile->Text + ".png"))
		{
			try
			{
				Cursor = Windows::Forms::Cursors::AppStarting;

				Bitmap^ bmp = (Bitmap^)Bitmap::FromFile(textBox_hmapFile->Text + ".png");
				array<unsigned char>^ bytes = gcnew array<unsigned char>(4);

				Imaging::BitmapData^ bData = bmp->LockBits(Rectangle(Point(), Drawing::Size(513, 513)), Imaging::ImageLockMode::ReadOnly, Imaging::PixelFormat::Format32bppArgb);
				unsigned char *FrameBytes = (unsigned char*)(void*)bData->Scan0; 
				for(int i=0; i<513*513; i++)
				{
					bytes[0] = FrameBytes[4*i+0];
					bytes[1] = FrameBytes[4*i+1];
					bytes[2] = FrameBytes[4*i+2];
					bytes[3] = FrameBytes[4*i+3];
					HMAP->Heights[i] = BitConverter::ToSingle(bytes, 0);
				}
				bmp->UnlockBits(bData);
				delete bmp;

				hmap_drawBackground();

				Cursor = Windows::Forms::Cursors::Default;
			}
			catch(Exception^ e)
			{
				MessageBox::Show("IMPORT ERROR!\n" + e->Message);
				Cursor = Windows::Forms::Cursors::Default;
			}
		}
	}
	private: void hmap_drawBackground()
	{
		if(checkBox_hmapBackground->Checked)
		{
			pictureBox_hmap->BackgroundImage = HMAP->Overlay;
			GC::Collect();
			return;
		}

		if(HMAP->Heights)
		{
			HMAP->FrameBytes = gcnew array<unsigned char>(4 * 513 * 513);
			IntPtr pointer = Runtime::InteropServices::Marshal::UnsafeAddrOfPinnedArrayElement(HMAP->FrameBytes, 0);
			pictureBox_hmap->BackgroundImage = gcnew Bitmap(513, 513, 4*513, Imaging::PixelFormat::Format32bppArgb, pointer);

			Color^ c;
			for(int i=0; i<HMAP->Heights->Length; i++)
			{
				c = colorValueExpansion->mapValue(Convert::ToDouble(HMAP->Heights[i]*1000));
				HMAP->FrameBytes[4*i+0] = c->B;
				HMAP->FrameBytes[4*i+1] = c->G;
				HMAP->FrameBytes[4*i+2] = c->R;
				/*
				HMAP->FrameBytes[4*i+0] = Float_to_Color(HMAP->Heights[i]).B;
				HMAP->FrameBytes[4*i+1] = Float_to_Color(HMAP->Heights[i]).G;
				HMAP->FrameBytes[4*i+2] = Float_to_Color(HMAP->Heights[i]).R;
				*/
				HMAP->FrameBytes[4*i+3] = 255; // No Alpha
			}
			GC::Collect();
			return;
		}

		pictureBox_hmap->BackgroundImage = gcnew Bitmap(513, 513);
		GC::Collect();
	}
	private: System::Void hmap_tooltip(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		if(HMAP->Heights && e->X>-1 && e->X<513 && e->Y>-1 && e->Y<513)
		{
			String^ text = "X: " + e->X + "\nZ: " + e->Y + "\nAltitude: " + (800*HMAP->Heights[e->Y*513 + e->X]).ToString("F3");
			if(text != toolTip->GetToolTip(pictureBox_hmap))
			{
				toolTip->SetToolTip(pictureBox_hmap, text);
			}
		}
	}
	private: System::Void hmap_markPoint(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		if(HMAP->Heights)
		{
			if(ShiftDown && e->X>-1 && e->X<513 && e->Y>-1 && e->Y<513)
			{
				Decimal d = Convert::ToDecimal(800*HMAP->Heights[e->Y*513 + e->X]);
				numericUpDown_hmapSetNW->Value = d;
				numericUpDown_hmapSetNE->Value = d;
				numericUpDown_hmapSetSW->Value = d;
				numericUpDown_hmapSetSE->Value = d;
			}
			else
			{
				Graphics^ g = Graphics::FromImage(pictureBox_hmap->Image);
				Color clearColor = Color::FromArgb(0, 0, 0, 0);
				g->Clear(clearColor);

				if(e->Button == Windows::Forms::MouseButtons::Left)
				{
					if((Control^)sender == pictureBox_hmap)
					{
						HMAP->Selection->Add(gcnew Point(e->X, e->Y));
					}
					Pen^ stroke = gcnew Pen(Color::White);
					Brush^ fill = gcnew SolidBrush(Color::FromArgb(10,255,255,255));
					
					array<Rectangle>^ rects = gcnew array<Rectangle>(HMAP->Selection->Count);
					array<Point>^ points = gcnew array<Point>(HMAP->Selection->Count);
					for(int i=0; i<HMAP->Selection->Count; i++)
					{
						rects[i] = Rectangle(((Point^)HMAP->Selection[i])->X-1, ((Point^)HMAP->Selection[i])->Y-1, 2, 2);
						points[i] = Point(((Point^)HMAP->Selection[i])->X, ((Point^)HMAP->Selection[i])->Y);
					}
					
					if(points->Length>2)
					{
						g->FillPolygon(fill, points);
						// Use drawn polygon as inline check area to create the selected points...

						Imaging::BitmapData^ bData = ((Bitmap^)pictureBox_hmap->Image)->LockBits(Rectangle(Point(), pictureBox_hmap->Image->Size), Imaging::ImageLockMode::ReadOnly, Imaging::PixelFormat::Format32bppArgb);
						unsigned char *FrameBytes = (unsigned char*)(void*)bData->Scan0; 

						HMAP->SelectedHeights->Clear();
						for(int i=0; i<513*513; i++)
						{
							if(FrameBytes[4*i+3] != clearColor.A)
							{
								HMAP->SelectedHeights->Add(i);
							}
						}

						((Bitmap^)pictureBox_hmap->Image)->UnlockBits(bData);

						g->DrawPolygon(stroke, points);
					}
					if(rects->Length>0)
					{
						g->DrawRectangles(stroke, rects);
					}
				}

				if(e->Button == Windows::Forms::MouseButtons::Right)
				{
					HMAP->Selection->Clear();
					HMAP->SelectedHeights->Clear();
				}

				GC::Collect();
				pictureBox_hmap->Refresh();
			}
		}
	}
	private: System::Void hmap_setHeight(System::Object^  sender, System::EventArgs^  e)
	{
		if(HMAP->Heights)
		{
			int x_W = int::MaxValue;
			int y_N = int::MaxValue;
			int x_E = int::MinValue;
			int y_S = int::MinValue;

			int distance_NW;
			int distance_NE;
			int distance_SW;
			int distance_SE;

			int X;
			int Y;

			for(int i=0; i<HMAP->Selection->Count; i++)
			{
				x_W = Math::Min(x_W, ((Point^)HMAP->Selection[i])->X);
				y_N = Math::Min(y_N, ((Point^)HMAP->Selection[i])->Y);
				x_E = Math::Max(x_E, ((Point^)HMAP->Selection[i])->X);
				y_S = Math::Max(y_S, ((Point^)HMAP->Selection[i])->Y);
			}

			float max_distance = Convert::ToSingle((x_E-x_W)*(y_S-y_N));

			int index;

			for(int i=0; i<HMAP->SelectedHeights->Count; i++)
			{
				index = (int)(HMAP->SelectedHeights[i]);
				// calculate X and Y location for the current height and interpolate the value of the bounding rectangle
				// using equal distant weight interpolation
				// Distance Metric: distance = delta_x * delta_y

				Y = index / 513;
				X = index % 513;

				distance_NW = (X-x_W)*(Y-y_N);
				distance_NE = (x_E-X)*(Y-y_N);
				distance_SW = (X-x_W)*(y_S-Y);
				distance_SE = (x_E-X)*(y_S-Y);

				HMAP->Heights[index] = 0;
				HMAP->Heights[index] += Convert::ToSingle(distance_NW * numericUpDown_hmapSetSE->Value);
				HMAP->Heights[index] += Convert::ToSingle(distance_NE * numericUpDown_hmapSetSW->Value);
				HMAP->Heights[index] += Convert::ToSingle(distance_SW * numericUpDown_hmapSetNE->Value);
				HMAP->Heights[index] += Convert::ToSingle(distance_SE * numericUpDown_hmapSetNW->Value);
				HMAP->Heights[index] /= max_distance;
				HMAP->Heights[index] /= 800;
			}
			hmap_drawBackground();
		}
	}
	private: System::Void hmap_switchBackground(System::Object^  sender, System::EventArgs^  e)
	{
		hmap_drawBackground();
	}
	private: System::Void hmap_changeBackground(System::Object^  sender, System::EventArgs^  e)
	{
		if(File::Exists(Application::StartupPath + "\\maps\\" + comboBox_hmapBackground->SelectedItem->ToString()))
		{
			HMAP->Overlay = Image::FromFile(Application::StartupPath + "\\maps\\" + comboBox_hmapBackground->SelectedItem->ToString());
			hmap_drawBackground();
		}
	}
	
#pragma endregion
#pragma region RMAP

	private: void InitializeRmap()
	{
		comboBox_rmapValue->SelectedIndex = 0;
	}
	private: System::Void rmap_load(System::Object^  sender, System::EventArgs^  e)
	{
		OpenFileDialog^ load = gcnew OpenFileDialog();
		load->Filter = "Raster Map (*.rmap)|*.rmap|All Files (*.*)|*.*";
		if(load->ShowDialog() == Windows::Forms::DialogResult::OK && File::Exists(load->FileName))
		{
			try
			{
				Cursor = Windows::Forms::Cursors::AppStarting;

				FileStream^ fr = File::OpenRead(load->FileName);
				BinaryReader^ br = gcnew BinaryReader(fr);

				RMAP->Version = br->ReadInt32();
				RMAP->ByteCount = br->ReadInt32();
				RMAP->LineSize = br->ReadInt32();
				RMAP->MapWidth = br->ReadInt32();
				RMAP->MapHeight = br->ReadInt32();
				RMAP->LineCount = br->ReadInt32();
				RMAP->Unknown = br->ReadSingle();

				RMAP->Lines = gcnew array<BitArray^>(RMAP->LineCount);

				// flip lines vertical while loading
				for(int i=RMAP->Lines->Length-1; i>-1; i--)
				{
					RMAP->Lines[i] = gcnew BitArray(br->ReadBytes(RMAP->LineSize));
				}

				br->Close();
				fr->Close();

				this->textBox_rmapFile->Text = load->FileName;

				rmap_drawBackground();

				Cursor = Windows::Forms::Cursors::Default;
			}
			catch(Exception^ e)
			{
				MessageBox::Show("LOADING ERROR!\n" + e->Message);
				Cursor = Windows::Forms::Cursors::Default;
			}
		}
	}
	private: System::Void rmap_save(System::Object^  sender, System::EventArgs^  e)
	{
		if(RMAP->Lines && File::Exists(textBox_rmapFile->Text))
		{
			try
			{
				Cursor = Windows::Forms::Cursors::AppStarting;

				FileStream^ fw = gcnew FileStream(textBox_rmapFile->Text, FileMode::Create, FileAccess::Write);
				BinaryWriter^ bw = gcnew BinaryWriter(fw);

				bw->Write(RMAP->Version);
				bw->Write(RMAP->ByteCount);
				bw->Write(RMAP->LineSize);
				bw->Write(RMAP->MapWidth);
				bw->Write(RMAP->MapHeight);
				bw->Write(RMAP->LineCount);
				bw->Write(RMAP->Unknown);

				// reverse vertical flipping image
				for(int i=RMAP->Lines->Length-1; i>-1; i--)
				{
					array<unsigned char>^ bytes = gcnew array<unsigned char>(RMAP->LineSize);
					RMAP->Lines[i]->CopyTo(bytes, 0);
					bw->Write(bytes);
				}

				bw->Close();
				fw->Close();

				Cursor = Windows::Forms::Cursors::Default;
			}
			catch(Exception^ e)
			{
				MessageBox::Show("SAVING ERROR!\n" + e->Message);
				Cursor = Windows::Forms::Cursors::Default;
			}
		}
	}
	private: System::Void rmap_export(System::Object^ sender, System::EventArgs^ e)
	{
		if(RMAP->Lines && File::Exists(textBox_rmapFile->Text))
		{
			try
			{
				Cursor = Windows::Forms::Cursors::AppStarting;

				IntPtr pointer = Runtime::InteropServices::Marshal::UnsafeAddrOfPinnedArrayElement(RMAP->FrameBytes, 0);
				Bitmap^ bmp = gcnew Bitmap(RMAP->MapWidth, RMAP->MapHeight, RMAP->MapWidth, Imaging::PixelFormat::Format8bppIndexed, pointer);
				bmp->Save(textBox_rmapFile->Text + ".png", Imaging::ImageFormat::Png);
				delete bmp;

				Cursor = Windows::Forms::Cursors::Default;
			}
			catch(Exception^ e)
			{
				MessageBox::Show("EXPORT ERROR!\n" + e->Message);
				Cursor = Windows::Forms::Cursors::Default;
			}
		}
	}
	private: System::Void rmap_import(System::Object^ sender, System::EventArgs^ e)
	{
		if(RMAP->Lines && File::Exists(textBox_rmapFile->Text + ".png"))
		{
			try
			{
				Cursor = Windows::Forms::Cursors::AppStarting;

				Bitmap^ bmp = (Bitmap^)Bitmap::FromFile(textBox_rmapFile->Text + ".png");

				Imaging::BitmapData^ bData = bmp->LockBits(Rectangle(Point(), Drawing::Size(RMAP->MapWidth, RMAP->MapHeight)), Imaging::ImageLockMode::ReadOnly, Imaging::PixelFormat::Format8bppIndexed);
				unsigned char *FrameBytes = (unsigned char*)(void*)bData->Scan0; 
				int x;
				int y;
				for(int i=0; i<RMAP->MapWidth*RMAP->MapHeight; i++)
				{
					y = i/RMAP->MapWidth;
					x = i%RMAP->MapWidth;
					RMAP->Lines[y][x] = Convert::ToBoolean(FrameBytes[i]);
					RMAP->FrameBytes[i] = FrameBytes[i];
				}
				bmp->UnlockBits(bData);
				delete bmp;

				rmap_drawBackground();

				Cursor = Windows::Forms::Cursors::Default;
			}
			catch(Exception^ e)
			{
				MessageBox::Show("IMPORT ERROR!\n" + e->Message);
				Cursor = Windows::Forms::Cursors::Default;
			}
		}
	}
	private: void rmap_drawBackground()
	{
		if(checkBox_rmapBackground->Checked)
		{
			pictureBox_rmap->BackgroundImage = RMAP->Overlay;
			GC::Collect();
			return;
		}

		if(RMAP->Lines)
		{
			RMAP->FrameBytes = gcnew array<unsigned char>(RMAP->MapWidth * RMAP->MapHeight);
			IntPtr pointer = Runtime::InteropServices::Marshal::UnsafeAddrOfPinnedArrayElement(RMAP->FrameBytes, 0);
			pictureBox_rmap->BackgroundImage = gcnew Bitmap(RMAP->MapWidth, RMAP->MapHeight, RMAP->MapWidth, Imaging::PixelFormat::Format8bppIndexed, pointer);

			int p=0;

			for(int y=0; y<RMAP->Lines->Length; y++)
			{
				for(int x=0; x<RMAP->Lines[y]->Count; x++)
				{
					if(RMAP->Lines[y][x])
					{
						//RMAP->FrameBytes[Block_to_Image_Position(i,n,k)] = 255;
						RMAP->FrameBytes[p] = 255;
					}
					p++;
				}
			}
			GC::Collect();
			return;
		}

		pictureBox_rmap->BackgroundImage = gcnew Bitmap(1024, 1024);
		GC::Collect();
	}
	private: System::Void rmap_tooltip(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		if(RMAP->Lines && e->X>-1 && e->X<8*RMAP->LineSize && e->Y>-1 && e->Y<RMAP->LineCount)
		{
			String^ text = "X: " + e->X + "\nZ: " + e->Y + "\nEnter: " + (RMAP->Lines[e->Y][e->X]).ToString();
			if(text != toolTip->GetToolTip(pictureBox_rmap))
			{
				toolTip->SetToolTip(pictureBox_rmap, text);
			}
		}
	}
	private: System::Void rmap_markPoint(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		if(RMAP->Lines)
		{
			Graphics^ g = Graphics::FromImage(pictureBox_rmap->Image);
			Color clearColor = Color::FromArgb(0, 0, 0, 0);
			g->Clear(clearColor);

			if(e->Button == Windows::Forms::MouseButtons::Left)
			{
				if((Control^)sender == pictureBox_rmap)
				{
					RMAP->Selection->Add(gcnew Point(e->X, e->Y));
				}
				Pen^ stroke = gcnew Pen(Color::FromArgb(128,255,0,0));
				Brush^ fill = gcnew SolidBrush(Color::FromArgb(32,255,0,0));

				array<Rectangle>^ rects = gcnew array<Rectangle>(RMAP->Selection->Count);
				array<Point>^ points = gcnew array<Point>(RMAP->Selection->Count);
				for(int i=0; i<RMAP->Selection->Count; i++)
				{
					rects[i] = Rectangle(((Point^)RMAP->Selection[i])->X-1, ((Point^)RMAP->Selection[i])->Y-1, 2, 2);
					points[i] = Point(((Point^)RMAP->Selection[i])->X, ((Point^)RMAP->Selection[i])->Y);
				}

				if(points->Length>1)
				{
					if(radioButton_rmapPFill->Checked)
					{
						g->FillPolygon(fill, points);
						g->DrawPolygon(stroke, points);
					}
					if(radioButton_rmapPLine->Checked)
					{
						g->DrawPolygon(stroke, points);
					}
					if(radioButton_rmapLines->Checked)
					{
						g->DrawLines(stroke, points);
					}
					
					// Use drawn polygon as inline check area to create the selected points...

					Imaging::BitmapData^ bData = ((Bitmap^)pictureBox_rmap->Image)->LockBits(Rectangle(Point(), pictureBox_rmap->Image->Size), Imaging::ImageLockMode::ReadOnly, Imaging::PixelFormat::Format32bppArgb);
					unsigned char *FrameBytes = (unsigned char*)(void*)bData->Scan0; 

					RMAP->SelectedBits->Clear();
					for(int i=0; i<RMAP->LineCount*8*RMAP->LineSize; i++)
					{
						if(FrameBytes[4*i+3] != clearColor.A)
						{
							RMAP->SelectedBits->Add(i);
						}
					}

					((Bitmap^)pictureBox_rmap->Image)->UnlockBits(bData);
				}
				if(rects->Length>0)
				{
					g->DrawRectangles(stroke, rects);
				}
			}

			if(e->Button == Windows::Forms::MouseButtons::Right)
			{
				RMAP->Selection->Clear();
				RMAP->SelectedBits->Clear();
			}

			GC::Collect();
			pictureBox_rmap->Refresh();
		}
	}
	private: System::Void rmap_setBits(System::Object^  sender, System::EventArgs^  e)
	{
		if(RMAP->Lines)
		{
			int x;
			int y;

			for(int i=0; i<RMAP->SelectedBits->Count; i++)
			{
				y = (int)(RMAP->SelectedBits[i])/(8*RMAP->LineSize);
				x = (int)(RMAP->SelectedBits[i])%(8*RMAP->LineSize);

				RMAP->Lines[y][x] = Convert::ToBoolean(comboBox_rmapValue->SelectedItem);
			}
			rmap_drawBackground();
		}
	}
	private: System::Void rmap_switchBackground(System::Object^  sender, System::EventArgs^  e)
	{
		rmap_drawBackground();
	}
	private: System::Void rmap_changeBackground(System::Object^  sender, System::EventArgs^  e)
	{
		if(File::Exists(Application::StartupPath + "\\maps\\" + comboBox_rmapBackground->SelectedItem->ToString()))
		{
			RMAP->Overlay = Image::FromFile(Application::StartupPath + "\\maps\\" + comboBox_rmapBackground->SelectedItem->ToString());
			rmap_drawBackground();
		}
	}	
#pragma endregion
#pragma region WMAP
	private: void InitializeWmap()
	{
	}
	private: System::Void wmap_load(System::Object^  sender, System::EventArgs^  e)
	{
		OpenFileDialog^ load = gcnew OpenFileDialog();
		load->Filter = "Water Map (*.wmap)|*.wmap|All Files (*.*)|*.*";
		if(load->ShowDialog() == Windows::Forms::DialogResult::OK && File::Exists(load->FileName))
		{
			try
			{
				Cursor = Windows::Forms::Cursors::AppStarting;

				listBox_wmapCollection->Items->Clear();

				FileStream^ fr = File::OpenRead(load->FileName);
				BinaryReader^ br = gcnew BinaryReader(fr);

				WMAP->version = br->ReadInt32();
				WMAP->map_width = br->ReadSingle();
				WMAP->map_height = br->ReadSingle();
				WMAP->surface_count = br->ReadInt32();

				WMAP->surfaces = gcnew array<water^>(WMAP->surface_count);

				// flip lines vertical while loading
				for(int i=0; i<WMAP->surfaces->Length; i++)
				{
					listBox_wmapCollection->Items->Add("Surface " + i.ToString());
					WMAP->surfaces[i] = gcnew water();
					WMAP->surfaces[i]->center_x = br->ReadSingle();
					WMAP->surfaces[i]->center_y = br->ReadSingle();
					WMAP->surfaces[i]->span_x = br->ReadSingle();
					WMAP->surfaces[i]->span_y = br->ReadSingle();
					WMAP->surfaces[i]->altitude = br->ReadSingle();
				}

				br->Close();
				fr->Close();

				this->textBox_wmapFile->Text = load->FileName;

				wmap_drawBackground();

				Cursor = Windows::Forms::Cursors::Default;
			}
			catch(Exception^ e)
			{
				MessageBox::Show("LOADING ERROR!\n" + e->Message);
				Cursor = Windows::Forms::Cursors::Default;
			}
		}
	}
	private: System::Void wmap_save(System::Object^  sender, System::EventArgs^  e)
	{
		if(WMAP->surfaces && File::Exists(textBox_wmapFile->Text))
		{
			try
			{
				Cursor = Windows::Forms::Cursors::AppStarting;

				FileStream^ fw = gcnew FileStream(textBox_wmapFile->Text, FileMode::Create, FileAccess::Write);
				BinaryWriter^ bw = gcnew BinaryWriter(fw);

				bw->Write(WMAP->version);
				bw->Write(WMAP->map_width);
				bw->Write(WMAP->map_height);
				bw->Write(WMAP->surfaces->Length);

				for(int i=0; i<WMAP->surfaces->Length; i++)
				{
					bw->Write(WMAP->surfaces[i]->center_x);
					bw->Write(WMAP->surfaces[i]->center_y);
					bw->Write(WMAP->surfaces[i]->span_x);
					bw->Write(WMAP->surfaces[i]->span_y);
					bw->Write(WMAP->surfaces[i]->altitude);
				}

				bw->Close();
				fw->Close();

				Cursor = Windows::Forms::Cursors::Default;
			}
			catch(Exception^ e)
			{
				MessageBox::Show("SAVING ERROR!\n" + e->Message);
				Cursor = Windows::Forms::Cursors::Default;
			}
		}
	}
	private: void wmap_drawBackground()
	{
		Cursor = Cursors::AppStarting;

		if(checkBox_wmapBackground->Checked && comboBox_wmapBackground->SelectedItem && File::Exists(Application::StartupPath + "\\maps\\" + comboBox_wmapBackground->SelectedItem->ToString()))
		{
			pictureBox_wmap->BackgroundImage = Image::FromFile(Application::StartupPath + "\\maps\\" + comboBox_wmapBackground->SelectedItem->ToString());
		}
		else
		{
			pictureBox_wmap->BackgroundImage = gcnew Bitmap(1024, 1024);
		}
		GC::Collect();

		Cursor = Cursors::Default;
	}
	private: void wmap_drawWater()
	{
		Cursor = Cursors::AppStarting;

		if(WMAP->surfaces && listBox_wmapCollection->SelectedIndex>-1)
		{
			try
			{
				pictureBox_wmap->Image = gcnew Bitmap(pictureBox_wmap->Image->Width, pictureBox_wmap->Image->Height);
				Graphics^ g = Graphics::FromImage(pictureBox_wmap->Image);
				Color clearColor = Color::FromArgb(0, 0, 0, 0);
				g->Clear(clearColor);

				Pen^ stroke = gcnew Pen(Color::Blue);
				Brush^ fill = gcnew SolidBrush(Color::FromArgb(50,0,0,255));
				
				array<Rectangle>^ rects = gcnew array<Rectangle>(4);
				array<Point>^ points = gcnew array<Point>(4);

				int x;
				int y;

				x = Convert::ToInt32(Math::Round((WMAP->surfaces[listBox_wmapCollection->SelectedIndex]->center_x - WMAP->surfaces[listBox_wmapCollection->SelectedIndex]->span_x + (pictureBox_wmap->Image->Width/2)) / 2));
				y = Convert::ToInt32(Math::Round(((pictureBox_wmap->Image->Height/2) - WMAP->surfaces[listBox_wmapCollection->SelectedIndex]->center_y + WMAP->surfaces[listBox_wmapCollection->SelectedIndex]->span_y) / 2));
				rects[0] = Rectangle(x-1, y-1, 2, 2);
				points[0] = Point(x, y);

				x = Convert::ToInt32(Math::Round((WMAP->surfaces[listBox_wmapCollection->SelectedIndex]->center_x + WMAP->surfaces[listBox_wmapCollection->SelectedIndex]->span_x + (pictureBox_wmap->Image->Width/2)) / 2));
				y = Convert::ToInt32(Math::Round(((pictureBox_wmap->Image->Height/2) - WMAP->surfaces[listBox_wmapCollection->SelectedIndex]->center_y + WMAP->surfaces[listBox_wmapCollection->SelectedIndex]->span_y) / 2));
				rects[1] = Rectangle(x-1, y-1, 2, 2);
				points[1] = Point(x, y);

				x = Convert::ToInt32(Math::Round((WMAP->surfaces[listBox_wmapCollection->SelectedIndex]->center_x + WMAP->surfaces[listBox_wmapCollection->SelectedIndex]->span_x + (pictureBox_wmap->Image->Width/2)) / 2));
				y = Convert::ToInt32(Math::Round(((pictureBox_wmap->Image->Height/2) - WMAP->surfaces[listBox_wmapCollection->SelectedIndex]->center_y - WMAP->surfaces[listBox_wmapCollection->SelectedIndex]->span_y) / 2));
				rects[2] = Rectangle(x-1, y-1, 2, 2);
				points[2] = Point(x, y);

				x = Convert::ToInt32(Math::Round((WMAP->surfaces[listBox_wmapCollection->SelectedIndex]->center_x - WMAP->surfaces[listBox_wmapCollection->SelectedIndex]->span_x + (pictureBox_wmap->Image->Width/2)) / 2));
				y = Convert::ToInt32(Math::Round(((pictureBox_wmap->Image->Height/2) - WMAP->surfaces[listBox_wmapCollection->SelectedIndex]->center_y - WMAP->surfaces[listBox_wmapCollection->SelectedIndex]->span_y) / 2));
				rects[3] = Rectangle(x-1, y-1, 2, 2);
				points[3] = Point(x, y);

				g->FillPolygon(fill, points);
				g->DrawRectangles(stroke, rects);

				GC::Collect();
				pictureBox_wmap->Refresh();
			}
			catch(...)
			{
				// Prevent Double Paint on fast Clicking in Pointlist
			}
		}

		Cursor = Cursors::Default;
	}
	private: System::Void wmap_switchBackground(System::Object^  sender, System::EventArgs^  e)
	{
		wmap_drawBackground();
		wmap_drawWater();
	}
	private: System::Void wmap_tooltip(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		if(WMAP->surfaces && e->X>-1 && e->Y>-1)
		{
			String^ text = "X: " + (2*e->X-(pictureBox_wmap->Image->Width/2)).ToString("F1") + "\nZ: " + (-(2*e->Y)+(pictureBox_wmap->Image->Height/2)).ToString("F1");
			if(text != toolTip->GetToolTip(pictureBox_wmap))
			{
				toolTip->SetToolTip(pictureBox_wmap, text);
			}
		}
	}
	private: System::Void wmap_change(System::Object^  sender, System::EventArgs^  e)
	{
		if(WMAP->surfaces && listBox_wmapCollection->SelectedIndex>-1)
		{
			textBox_wmapCenterX->Text = WMAP->surfaces[listBox_wmapCollection->SelectedIndex]->center_x.ToString("F3");
			textBox_wmapCenterY->Text = WMAP->surfaces[listBox_wmapCollection->SelectedIndex]->center_y.ToString("F3");
			textBox_wmapSpanX->Text = WMAP->surfaces[listBox_wmapCollection->SelectedIndex]->span_x.ToString("F3");
			textBox_wmapSpanY->Text = WMAP->surfaces[listBox_wmapCollection->SelectedIndex]->span_y.ToString("F3");
			textBox_wmapAltitude->Text = WMAP->surfaces[listBox_wmapCollection->SelectedIndex]->altitude.ToString("F3");

			wmap_drawWater();
		}
		else
		{
			textBox_wmapCenterX->Clear();
			textBox_wmapCenterY->Clear();
			textBox_wmapSpanX->Clear();
			textBox_wmapSpanY->Clear();
			textBox_wmapAltitude->Clear();
		}
	}
	private: System::Void wmap_add(System::Object^  sender, System::EventArgs^  e)
	{
		if(WMAP->surfaces)
		{
			if(contextMenuStrip_water->SourceControl == listBox_wmapCollection)
			{
				WMAP->surface_count++;
				Array::Resize(WMAP->surfaces, WMAP->surfaces->Length+1);
				WMAP->surfaces[WMAP->surfaces->Length-1] = gcnew water();
				WMAP->surfaces[WMAP->surfaces->Length-1]->center_x = 0.0f;
				WMAP->surfaces[WMAP->surfaces->Length-1]->center_y = 0.0f;
				WMAP->surfaces[WMAP->surfaces->Length-1]->span_x = 64.0f;
				WMAP->surfaces[WMAP->surfaces->Length-1]->span_y = 64.0f;
				WMAP->surfaces[WMAP->surfaces->Length-1]->altitude = 200.0f;

				listBox_wmapCollection->Items->Add("Surface " + listBox_wmapCollection->Items->Count.ToString());
				listBox_wmapCollection->SelectedIndex = listBox_wmapCollection->Items->Count-1;
			}
		}
	}
	private: System::Void wmap_delete(System::Object^  sender, System::EventArgs^  e)
	{
		if(WMAP)
		{
			if(contextMenuStrip_water->SourceControl == listBox_wmapCollection && listBox_wmapCollection->SelectedIndex>-1)
			{
				if(WMAP->surface_count>0)
				{
					WMAP->surface_count--;

					array<water^>^ temp = gcnew array<water^>(WMAP->surface_count);
					Array::Copy(WMAP->surfaces, 0, temp, 0, listBox_wmapCollection->SelectedIndex);
					Array::Copy(WMAP->surfaces, listBox_wmapCollection->SelectedIndex+1, temp, listBox_wmapCollection->SelectedIndex, WMAP->surface_count - listBox_wmapCollection->SelectedIndex);
					WMAP->surfaces = temp;

					listBox_wmapCollection->Items->RemoveAt(listBox_wmapCollection->SelectedIndex);
				}
			}
		}
	}
	private: System::Void wmap_editValue(System::Object^  sender, System::EventArgs^  e)
	{
		try
		{
			if(listBox_wmapCollection->SelectedIndex>-1)
			{
				if((Control^)sender == textBox_wmapCenterX)
				{
					WMAP->surfaces[listBox_wmapCollection->SelectedIndex]->center_x = Convert::ToSingle(textBox_wmapCenterX->Text);
				}
				if((Control^)sender == textBox_wmapCenterY)
				{
					WMAP->surfaces[listBox_wmapCollection->SelectedIndex]->center_y = Convert::ToSingle(textBox_wmapCenterY->Text);
				}
				if((Control^)sender == textBox_wmapSpanX)
				{
					WMAP->surfaces[listBox_wmapCollection->SelectedIndex]->span_x = Convert::ToSingle(textBox_wmapSpanX->Text);
				}
				if((Control^)sender == textBox_wmapSpanY)
				{
					WMAP->surfaces[listBox_wmapCollection->SelectedIndex]->span_y = Convert::ToSingle(textBox_wmapSpanY->Text);
				}
				if((Control^)sender == textBox_wmapAltitude)
				{
					WMAP->surfaces[listBox_wmapCollection->SelectedIndex]->altitude = Convert::ToSingle(textBox_wmapAltitude->Text);
				}

				wmap_drawWater();
			}
		}
		catch(...)
		{
			MessageBox::Show("ERROR\nValue must be in the correct format!");
		}
	}
#pragma endregion
};