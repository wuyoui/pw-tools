#pragma once

#include "..\COMMON\boutique.h"

using namespace System;
using namespace System::IO;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Net;

/// <summary>
/// Summary for MainWindow
///
/// WARNING: If you change the name of this class, you will need to change the
///          'Resource File Name' property for the managed resource compiler tool
///          associated with all .resx files this class depends on.  Otherwise,
///          the designers will not be able to interact properly with localized
///          resources associated with this form.
/// </summary>
public ref class MainWindow : public System::Windows::Forms::Form
{
	public:
		MainWindow(void)
		{
			InitializeComponent();
			initialize();
			movingIndex = new int;
			this->Icon = (Drawing::Icon^)((gcnew Resources::ResourceManager("sTools.icons", Reflection::Assembly::GetExecutingAssembly()))->GetObject("app"));
			//
			//TODO: Add the constructor code here
			//
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

		private: Boutique^ GSHOP;
		int *movingIndex;
		int max_item_id;
		// Map the shop id of an item to the corresponding index
		SortedList^ item_id_index_map;
		SortedList^ itemDescriptions;
		private: System::Windows::Forms::ComboBox^  comboBox_dbSource;
		private: System::Windows::Forms::TextBox^  textBox_duration;
		private: System::Windows::Forms::Label^  label18;
		private: System::Windows::Forms::Label^  label2;
		private: System::Windows::Forms::Label^  label1;
		private: System::Windows::Forms::Label^  label17;
		private: System::Windows::Forms::TextBox^  textBox_SubCat;
		private: System::Windows::Forms::GroupBox^  groupBox3;
		private: System::Windows::Forms::TextBox^  textBox_Cat;
		private: System::Windows::Forms::ListBox^  listBox_Cats;
		private: System::Windows::Forms::ListBox^  listBox_SubCats;
		private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip_SubCat;
		private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem1;
		private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem2;
		private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
		private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem_moveCat;
		private: System::Windows::Forms::ListBox^  listBox_Items;
		private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip_Item;
		private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem3;
		private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem12;
		private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
		private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem_moveItem;
		private: System::Windows::Forms::GroupBox^  groupBox2;
		private: System::Windows::Forms::Label^  label9;
		private: System::Windows::Forms::NumericUpDown^  numericUpDown_price;
		private: System::Windows::Forms::Label^  label8;
		private: System::Windows::Forms::NumericUpDown^  numericUpDown_amount;
		private: System::Windows::Forms::Label^  label7;
		private: System::Windows::Forms::ComboBox^  comboBox_surface;
		private: System::Windows::Forms::Button^  button_autoDetect;
		private: System::Windows::Forms::NumericUpDown^  numericUpDown_itemID;
		private: System::Windows::Forms::TextBox^  textBox_name;
		private: System::Windows::Forms::Label^  label6;
		private: System::Windows::Forms::Label^  label5;
		private: System::Windows::Forms::Label^  label4;
		private: System::Windows::Forms::Label^  label3;
		private: System::Windows::Forms::TextBox^  textBox_description;
		private: System::Windows::Forms::PictureBox^  pictureBox_surface;
		private: System::Windows::Forms::TextBox^  textBox_search;
		private: System::Windows::Forms::Button^  button_search;
		private: System::Windows::Forms::ComboBox^  comboBox_sale_option;
		private: System::Windows::Forms::GroupBox^  groupBox4;
		private: System::Windows::Forms::Label^  label16;
		private: System::Windows::Forms::Label^  label15;
		private: System::Windows::Forms::Label^  label13;
		private: System::Windows::Forms::Label^  label12;
		private: System::Windows::Forms::Label^  label11;
		private: System::Windows::Forms::Label^  label14;
		private: System::Windows::Forms::ComboBox^  comboBox_status;
		private: System::Windows::Forms::NumericUpDown^  numericUpDown_gift_amount;
		private: System::Windows::Forms::Label^  label20;
		private: System::Windows::Forms::NumericUpDown^  numericUpDown_gift_id;
		private: System::Windows::Forms::Label^  label19;
		private: System::Windows::Forms::TextBox^  textBox_start_date;
		private: System::Windows::Forms::TextBox^  textBox_end_date;
		private: System::Windows::Forms::Label^  label10;
		private: System::Windows::Forms::Label^  label21;
		private: System::Windows::Forms::TextBox^  textBox_gift_duration;
		private: System::Windows::Forms::Label^  label22;
		private: System::Windows::Forms::NumericUpDown^  numericUpDown_log_price;
		private: System::Windows::Forms::TextBox^  textBox_flags;
		private: System::Windows::Forms::TextBox^  textBox_day;
		private: System::Windows::Forms::ComboBox^  comboBox_type;
		private: System::Windows::Forms::MenuStrip^  menuStrip1;
		private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^  loadToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
		private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator3;
		private: System::Windows::Forms::ToolStripMenuItem^  impoertToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^  importServerToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^  exportClientToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^  exportServerToolStripMenuItem;
		private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator4;
		private: System::Windows::Forms::CheckBox^  checkBox_active;
		private: System::Windows::Forms::ToolStripMenuItem^  import136ClientServerToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^  export136ToolStripMenuItem;
		private: System::Windows::Forms::TextBox^  textBox_timestamp;
		private: System::Windows::Forms::Label^  label23;
		private: System::Windows::Forms::Button^  button_timestamp;
		private: System::Windows::Forms::ToolStripMenuItem^  toolsToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^  setAllPricesToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^  setAllControlTypesClientToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^  setAllControlTypesServerToolStripMenuItem;

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
			this->comboBox_dbSource = (gcnew System::Windows::Forms::ComboBox());
			this->textBox_duration = (gcnew System::Windows::Forms::TextBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->textBox_SubCat = (gcnew System::Windows::Forms::TextBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->button_timestamp = (gcnew System::Windows::Forms::Button());
			this->textBox_timestamp = (gcnew System::Windows::Forms::TextBox());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->textBox_Cat = (gcnew System::Windows::Forms::TextBox());
			this->listBox_Cats = (gcnew System::Windows::Forms::ListBox());
			this->listBox_SubCats = (gcnew System::Windows::Forms::ListBox());
			this->contextMenuStrip_SubCat = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripMenuItem_moveCat = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->listBox_Items = (gcnew System::Windows::Forms::ListBox());
			this->contextMenuStrip_Item = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->toolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem12 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripMenuItem_moveItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox_active = (gcnew System::Windows::Forms::CheckBox());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown_log_price = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown_gift_amount = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox_gift_duration = (gcnew System::Windows::Forms::TextBox());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown_gift_id = (gcnew System::Windows::Forms::NumericUpDown());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->comboBox_sale_option = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->comboBox_type = (gcnew System::Windows::Forms::ComboBox());
			this->textBox_day = (gcnew System::Windows::Forms::TextBox());
			this->textBox_flags = (gcnew System::Windows::Forms::TextBox());
			this->textBox_start_date = (gcnew System::Windows::Forms::TextBox());
			this->textBox_end_date = (gcnew System::Windows::Forms::TextBox());
			this->comboBox_status = (gcnew System::Windows::Forms::ComboBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown_price = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown_amount = (gcnew System::Windows::Forms::NumericUpDown());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->comboBox_surface = (gcnew System::Windows::Forms::ComboBox());
			this->button_autoDetect = (gcnew System::Windows::Forms::Button());
			this->numericUpDown_itemID = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox_name = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox_description = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox_surface = (gcnew System::Windows::Forms::PictureBox());
			this->textBox_search = (gcnew System::Windows::Forms::TextBox());
			this->button_search = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->export136ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exportClientToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exportServerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator4 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->import136ClientServerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->impoertToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->importServerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->setAllPricesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->setAllControlTypesClientToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->setAllControlTypesServerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox3->SuspendLayout();
			this->contextMenuStrip_SubCat->SuspendLayout();
			this->contextMenuStrip_Item->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown_log_price))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown_gift_amount))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown_gift_id))->BeginInit();
			this->groupBox4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown_price))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown_amount))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown_itemID))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox_surface))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// comboBox_dbSource
			// 
			this->comboBox_dbSource->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox_dbSource->FormattingEnabled = true;
			this->comboBox_dbSource->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"item_ext_desc.txt", L"pwdatabase.com/pwi", 
				L"pwdatabase.com/my", L"pwdatabase.com/ms", L"pwdatabase.com/ru"});
			this->comboBox_dbSource->Location = System::Drawing::Point(81, 67);
			this->comboBox_dbSource->Name = L"comboBox_dbSource";
			this->comboBox_dbSource->Size = System::Drawing::Size(133, 21);
			this->comboBox_dbSource->TabIndex = 5;
			// 
			// textBox_duration
			// 
			this->textBox_duration->Location = System::Drawing::Point(139, 123);
			this->textBox_duration->Name = L"textBox_duration";
			this->textBox_duration->Size = System::Drawing::Size(82, 20);
			this->textBox_duration->TabIndex = 21;
			this->textBox_duration->Leave += gcnew System::EventHandler(this, &MainWindow::edit_item);
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(157, 45);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(35, 13);
			this->label18->TabIndex = 6;
			this->label18->Text = L"Items:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(3, 202);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(82, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Sub Categories:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 45);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(60, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Categories:";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(6, 71);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(45, 13);
			this->label17->TabIndex = 4;
			this->label17->Text = L"Update:";
			// 
			// textBox_SubCat
			// 
			this->textBox_SubCat->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->textBox_SubCat->Location = System::Drawing::Point(6, 500);
			this->textBox_SubCat->MaxLength = 12;
			this->textBox_SubCat->Name = L"textBox_SubCat";
			this->textBox_SubCat->Size = System::Drawing::Size(148, 20);
			this->textBox_SubCat->TabIndex = 5;
			this->textBox_SubCat->TextChanged += gcnew System::EventHandler(this, &MainWindow::rename_subcat);
			// 
			// groupBox3
			// 
			this->groupBox3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox3->Controls->Add(this->button_timestamp);
			this->groupBox3->Controls->Add(this->textBox_timestamp);
			this->groupBox3->Controls->Add(this->label23);
			this->groupBox3->Controls->Add(this->label18);
			this->groupBox3->Controls->Add(this->label2);
			this->groupBox3->Controls->Add(this->label1);
			this->groupBox3->Controls->Add(this->textBox_SubCat);
			this->groupBox3->Controls->Add(this->textBox_Cat);
			this->groupBox3->Controls->Add(this->listBox_Cats);
			this->groupBox3->Controls->Add(this->listBox_SubCats);
			this->groupBox3->Controls->Add(this->listBox_Items);
			this->groupBox3->Location = System::Drawing::Point(2, 27);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(355, 526);
			this->groupBox3->TabIndex = 2;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"GENERAL";
			// 
			// button_timestamp
			// 
			this->button_timestamp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F));
			this->button_timestamp->Location = System::Drawing::Point(313, 17);
			this->button_timestamp->Name = L"button_timestamp";
			this->button_timestamp->Size = System::Drawing::Size(36, 20);
			this->button_timestamp->TabIndex = 10;
			this->button_timestamp->Text = L"Get";
			this->button_timestamp->UseVisualStyleBackColor = true;
			this->button_timestamp->Click += gcnew System::EventHandler(this, &MainWindow::click_get_timestamp);
			// 
			// textBox_timestamp
			// 
			this->textBox_timestamp->Location = System::Drawing::Point(186, 17);
			this->textBox_timestamp->Name = L"textBox_timestamp";
			this->textBox_timestamp->Size = System::Drawing::Size(121, 20);
			this->textBox_timestamp->TabIndex = 9;
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(3, 20);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(177, 13);
			this->label23->TabIndex = 8;
			this->label23->Text = L"Timestamp (yyyy-MM-dd HH:mm:ss):";
			// 
			// textBox_Cat
			// 
			this->textBox_Cat->Location = System::Drawing::Point(6, 175);
			this->textBox_Cat->MaxLength = 12;
			this->textBox_Cat->Name = L"textBox_Cat";
			this->textBox_Cat->Size = System::Drawing::Size(148, 20);
			this->textBox_Cat->TabIndex = 2;
			this->textBox_Cat->TextChanged += gcnew System::EventHandler(this, &MainWindow::rename_cat);
			// 
			// listBox_Cats
			// 
			this->listBox_Cats->FormattingEnabled = true;
			this->listBox_Cats->Location = System::Drawing::Point(6, 61);
			this->listBox_Cats->Name = L"listBox_Cats";
			this->listBox_Cats->Size = System::Drawing::Size(148, 108);
			this->listBox_Cats->TabIndex = 1;
			this->listBox_Cats->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::mouseUp_StopMove);
			this->listBox_Cats->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::change_cat);
			this->listBox_Cats->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::mouseMove_MoveCat);
			this->listBox_Cats->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::mouseDown_StartMove);
			// 
			// listBox_SubCats
			// 
			this->listBox_SubCats->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left));
			this->listBox_SubCats->ContextMenuStrip = this->contextMenuStrip_SubCat;
			this->listBox_SubCats->FormattingEnabled = true;
			this->listBox_SubCats->Location = System::Drawing::Point(6, 218);
			this->listBox_SubCats->Name = L"listBox_SubCats";
			this->listBox_SubCats->Size = System::Drawing::Size(148, 277);
			this->listBox_SubCats->TabIndex = 4;
			this->listBox_SubCats->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::mouseUp_StopMove);
			this->listBox_SubCats->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::change_subcat);
			this->listBox_SubCats->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::mouseMove_MoveSubCat);
			this->listBox_SubCats->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::mouseDown_StartMove);
			// 
			// contextMenuStrip_SubCat
			// 
			this->contextMenuStrip_SubCat->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->toolStripMenuItem1, 
				this->toolStripMenuItem2, this->toolStripSeparator1, this->toolStripMenuItem_moveCat});
			this->contextMenuStrip_SubCat->Name = L"contextMenuStrip_SubCat";
			this->contextMenuStrip_SubCat->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
			this->contextMenuStrip_SubCat->ShowImageMargin = false;
			this->contextMenuStrip_SubCat->Size = System::Drawing::Size(91, 76);
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(90, 22);
			this->toolStripMenuItem1->Text = L"Add";
			this->toolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainWindow::click_addSubCat);
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(90, 22);
			this->toolStripMenuItem2->Text = L"Delete";
			this->toolStripMenuItem2->Click += gcnew System::EventHandler(this, &MainWindow::click_deleteSubCat);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(87, 6);
			// 
			// toolStripMenuItem_moveCat
			// 
			this->toolStripMenuItem_moveCat->Name = L"toolStripMenuItem_moveCat";
			this->toolStripMenuItem_moveCat->Size = System::Drawing::Size(90, 22);
			this->toolStripMenuItem_moveCat->Text = L"Move To";
			// 
			// listBox_Items
			// 
			this->listBox_Items->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->listBox_Items->ContextMenuStrip = this->contextMenuStrip_Item;
			this->listBox_Items->FormattingEnabled = true;
			this->listBox_Items->Location = System::Drawing::Point(160, 61);
			this->listBox_Items->Name = L"listBox_Items";
			this->listBox_Items->Size = System::Drawing::Size(189, 459);
			this->listBox_Items->TabIndex = 7;
			this->listBox_Items->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::mouseUp_StopMove);
			this->listBox_Items->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::listBox_Items_MouseDoubleClick);
			this->listBox_Items->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::change_item);
			this->listBox_Items->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::mouseMove_MoveItem);
			this->listBox_Items->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::mouseDown_StartMove);
			// 
			// contextMenuStrip_Item
			// 
			this->contextMenuStrip_Item->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->toolStripMenuItem3, 
				this->toolStripMenuItem12, this->toolStripSeparator2, this->toolStripMenuItem_moveItem});
			this->contextMenuStrip_Item->Name = L"contextMenuStrip_Item";
			this->contextMenuStrip_Item->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
			this->contextMenuStrip_Item->ShowImageMargin = false;
			this->contextMenuStrip_Item->Size = System::Drawing::Size(91, 76);
			// 
			// toolStripMenuItem3
			// 
			this->toolStripMenuItem3->Name = L"toolStripMenuItem3";
			this->toolStripMenuItem3->Size = System::Drawing::Size(90, 22);
			this->toolStripMenuItem3->Text = L"Add";
			this->toolStripMenuItem3->Click += gcnew System::EventHandler(this, &MainWindow::click_addItem);
			// 
			// toolStripMenuItem12
			// 
			this->toolStripMenuItem12->Name = L"toolStripMenuItem12";
			this->toolStripMenuItem12->Size = System::Drawing::Size(90, 22);
			this->toolStripMenuItem12->Text = L"Delete";
			this->toolStripMenuItem12->Click += gcnew System::EventHandler(this, &MainWindow::click_deleteItem);
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(87, 6);
			// 
			// toolStripMenuItem_moveItem
			// 
			this->toolStripMenuItem_moveItem->Name = L"toolStripMenuItem_moveItem";
			this->toolStripMenuItem_moveItem->Size = System::Drawing::Size(90, 22);
			this->toolStripMenuItem_moveItem->Text = L"Move To";
			// 
			// groupBox2
			// 
			this->groupBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox2->Controls->Add(this->checkBox_active);
			this->groupBox2->Controls->Add(this->label22);
			this->groupBox2->Controls->Add(this->label21);
			this->groupBox2->Controls->Add(this->numericUpDown_log_price);
			this->groupBox2->Controls->Add(this->numericUpDown_gift_amount);
			this->groupBox2->Controls->Add(this->textBox_gift_duration);
			this->groupBox2->Controls->Add(this->label20);
			this->groupBox2->Controls->Add(this->numericUpDown_gift_id);
			this->groupBox2->Controls->Add(this->label19);
			this->groupBox2->Controls->Add(this->label14);
			this->groupBox2->Controls->Add(this->comboBox_sale_option);
			this->groupBox2->Controls->Add(this->groupBox4);
			this->groupBox2->Controls->Add(this->comboBox_dbSource);
			this->groupBox2->Controls->Add(this->label17);
			this->groupBox2->Controls->Add(this->numericUpDown_amount);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->comboBox_surface);
			this->groupBox2->Controls->Add(this->button_autoDetect);
			this->groupBox2->Controls->Add(this->numericUpDown_itemID);
			this->groupBox2->Controls->Add(this->textBox_name);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->textBox_description);
			this->groupBox2->Controls->Add(this->pictureBox_surface);
			this->groupBox2->Location = System::Drawing::Point(363, 27);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(427, 552);
			this->groupBox2->TabIndex = 3;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"ITEM";
			// 
			// checkBox_active
			// 
			this->checkBox_active->AutoSize = true;
			this->checkBox_active->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->checkBox_active->ForeColor = System::Drawing::Color::Red;
			this->checkBox_active->Location = System::Drawing::Point(9, 19);
			this->checkBox_active->Name = L"checkBox_active";
			this->checkBox_active->Size = System::Drawing::Size(156, 17);
			this->checkBox_active->TabIndex = 38;
			this->checkBox_active->Text = L"Activate Item in Server";
			this->checkBox_active->UseVisualStyleBackColor = true;
			this->checkBox_active->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::edit_item);
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->ForeColor = System::Drawing::Color::Gray;
			this->label22->Location = System::Drawing::Point(6, 528);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(55, 13);
			this->label22->TabIndex = 36;
			this->label22->Text = L"Log Price:";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->ForeColor = System::Drawing::Color::Gray;
			this->label21->Location = System::Drawing::Point(6, 503);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(69, 13);
			this->label21->TabIndex = 37;
			this->label21->Text = L"Gift Duration:";
			// 
			// numericUpDown_log_price
			// 
			this->numericUpDown_log_price->DecimalPlaces = 2;
			this->numericUpDown_log_price->Location = System::Drawing::Point(81, 526);
			this->numericUpDown_log_price->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {9999999, 0, 0, 131072});
			this->numericUpDown_log_price->Name = L"numericUpDown_log_price";
			this->numericUpDown_log_price->Size = System::Drawing::Size(65, 20);
			this->numericUpDown_log_price->TabIndex = 37;
			this->numericUpDown_log_price->Leave += gcnew System::EventHandler(this, &MainWindow::edit_item);
			// 
			// numericUpDown_gift_amount
			// 
			this->numericUpDown_gift_amount->Location = System::Drawing::Point(81, 474);
			this->numericUpDown_gift_amount->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {99999, 0, 0, 0});
			this->numericUpDown_gift_amount->Name = L"numericUpDown_gift_amount";
			this->numericUpDown_gift_amount->Size = System::Drawing::Size(65, 20);
			this->numericUpDown_gift_amount->TabIndex = 36;
			this->numericUpDown_gift_amount->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->numericUpDown_gift_amount->Leave += gcnew System::EventHandler(this, &MainWindow::edit_item);
			// 
			// textBox_gift_duration
			// 
			this->textBox_gift_duration->Location = System::Drawing::Point(81, 500);
			this->textBox_gift_duration->Name = L"textBox_gift_duration";
			this->textBox_gift_duration->Size = System::Drawing::Size(65, 20);
			this->textBox_gift_duration->TabIndex = 36;
			this->textBox_gift_duration->Leave += gcnew System::EventHandler(this, &MainWindow::edit_item);
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->ForeColor = System::Drawing::Color::Gray;
			this->label20->Location = System::Drawing::Point(6, 476);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(65, 13);
			this->label20->TabIndex = 35;
			this->label20->Text = L"Gift Amount:";
			// 
			// numericUpDown_gift_id
			// 
			this->numericUpDown_gift_id->Location = System::Drawing::Point(81, 448);
			this->numericUpDown_gift_id->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {99999, 0, 0, 0});
			this->numericUpDown_gift_id->Name = L"numericUpDown_gift_id";
			this->numericUpDown_gift_id->Size = System::Drawing::Size(65, 20);
			this->numericUpDown_gift_id->TabIndex = 34;
			this->numericUpDown_gift_id->Leave += gcnew System::EventHandler(this, &MainWindow::edit_item);
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->ForeColor = System::Drawing::Color::Gray;
			this->label19->Location = System::Drawing::Point(6, 450);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(40, 13);
			this->label19->TabIndex = 33;
			this->label19->Text = L"Gift ID:";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(6, 208);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(65, 13);
			this->label14->TabIndex = 32;
			this->label14->Text = L"Sale Option:";
			// 
			// comboBox_sale_option
			// 
			this->comboBox_sale_option->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox_sale_option->FormattingEnabled = true;
			this->comboBox_sale_option->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"Default", L"Option 1", L"Option 2", 
				L"Option 3"});
			this->comboBox_sale_option->Location = System::Drawing::Point(81, 205);
			this->comboBox_sale_option->Name = L"comboBox_sale_option";
			this->comboBox_sale_option->Size = System::Drawing::Size(65, 21);
			this->comboBox_sale_option->TabIndex = 31;
			this->comboBox_sale_option->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::change_item);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->comboBox_type);
			this->groupBox4->Controls->Add(this->textBox_day);
			this->groupBox4->Controls->Add(this->textBox_flags);
			this->groupBox4->Controls->Add(this->textBox_start_date);
			this->groupBox4->Controls->Add(this->textBox_end_date);
			this->groupBox4->Controls->Add(this->comboBox_status);
			this->groupBox4->Controls->Add(this->label16);
			this->groupBox4->Controls->Add(this->label15);
			this->groupBox4->Controls->Add(this->label13);
			this->groupBox4->Controls->Add(this->label12);
			this->groupBox4->Controls->Add(this->label11);
			this->groupBox4->Controls->Add(this->label8);
			this->groupBox4->Controls->Add(this->label9);
			this->groupBox4->Controls->Add(this->label10);
			this->groupBox4->Controls->Add(this->numericUpDown_price);
			this->groupBox4->Controls->Add(this->textBox_duration);
			this->groupBox4->Location = System::Drawing::Point(152, 205);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(269, 229);
			this->groupBox4->TabIndex = 30;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"SALE OPTION";
			// 
			// comboBox_type
			// 
			this->comboBox_type->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox_type->FormattingEnabled = true;
			this->comboBox_type->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"Client", L"Server"});
			this->comboBox_type->Location = System::Drawing::Point(139, 44);
			this->comboBox_type->Name = L"comboBox_type";
			this->comboBox_type->Size = System::Drawing::Size(82, 21);
			this->comboBox_type->TabIndex = 38;
			this->comboBox_type->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::edit_item);
			// 
			// textBox_day
			// 
			this->textBox_day->Location = System::Drawing::Point(139, 149);
			this->textBox_day->Name = L"textBox_day";
			this->textBox_day->Size = System::Drawing::Size(82, 20);
			this->textBox_day->TabIndex = 37;
			this->textBox_day->Leave += gcnew System::EventHandler(this, &MainWindow::edit_item);
			// 
			// textBox_flags
			// 
			this->textBox_flags->Location = System::Drawing::Point(139, 202);
			this->textBox_flags->Name = L"textBox_flags";
			this->textBox_flags->Size = System::Drawing::Size(82, 20);
			this->textBox_flags->TabIndex = 36;
			this->textBox_flags->Leave += gcnew System::EventHandler(this, &MainWindow::edit_item);
			// 
			// textBox_start_date
			// 
			this->textBox_start_date->Location = System::Drawing::Point(139, 71);
			this->textBox_start_date->Name = L"textBox_start_date";
			this->textBox_start_date->Size = System::Drawing::Size(124, 20);
			this->textBox_start_date->TabIndex = 35;
			this->textBox_start_date->Leave += gcnew System::EventHandler(this, &MainWindow::edit_item);
			// 
			// textBox_end_date
			// 
			this->textBox_end_date->Location = System::Drawing::Point(139, 97);
			this->textBox_end_date->Name = L"textBox_end_date";
			this->textBox_end_date->Size = System::Drawing::Size(124, 20);
			this->textBox_end_date->TabIndex = 34;
			this->textBox_end_date->Leave += gcnew System::EventHandler(this, &MainWindow::edit_item);
			// 
			// comboBox_status
			// 
			this->comboBox_status->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox_status->FormattingEnabled = true;
			this->comboBox_status->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"0 - Normal", L"1 - New\?", L"2 - \?", L"3 - Hot\?", 
				L"4 - Sale\?"});
			this->comboBox_status->Location = System::Drawing::Point(139, 175);
			this->comboBox_status->Name = L"comboBox_status";
			this->comboBox_status->Size = System::Drawing::Size(82, 21);
			this->comboBox_status->TabIndex = 33;
			this->comboBox_status->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::edit_item);
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->ForeColor = System::Drawing::Color::Gray;
			this->label16->Location = System::Drawing::Point(6, 205);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(35, 13);
			this->label16->TabIndex = 31;
			this->label16->Text = L"Flags:";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->ForeColor = System::Drawing::Color::Gray;
			this->label15->Location = System::Drawing::Point(6, 178);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(40, 13);
			this->label15->TabIndex = 30;
			this->label15->Text = L"Status:";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->ForeColor = System::Drawing::Color::Gray;
			this->label13->Location = System::Drawing::Point(6, 152);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(29, 13);
			this->label13->TabIndex = 29;
			this->label13->Text = L"Day:";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->ForeColor = System::Drawing::Color::Gray;
			this->label12->Location = System::Drawing::Point(6, 74);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(83, 13);
			this->label12->TabIndex = 28;
			this->label12->Text = L"Activation Date:";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(6, 126);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(128, 13);
			this->label11->TabIndex = 27;
			this->label11->Text = L"Duration (dd-HH:MM:SS):";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(6, 20);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(34, 13);
			this->label8->TabIndex = 15;
			this->label8->Text = L"Price:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->ForeColor = System::Drawing::Color::Gray;
			this->label9->Location = System::Drawing::Point(6, 47);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(70, 13);
			this->label9->TabIndex = 16;
			this->label9->Text = L"Control Type:";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->ForeColor = System::Drawing::Color::Gray;
			this->label10->Location = System::Drawing::Point(6, 100);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(65, 13);
			this->label10->TabIndex = 17;
			this->label10->Text = L"Expire Date:";
			// 
			// numericUpDown_price
			// 
			this->numericUpDown_price->DecimalPlaces = 2;
			this->numericUpDown_price->Location = System::Drawing::Point(139, 18);
			this->numericUpDown_price->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {99999999, 0, 0, 131072});
			this->numericUpDown_price->Name = L"numericUpDown_price";
			this->numericUpDown_price->Size = System::Drawing::Size(82, 20);
			this->numericUpDown_price->TabIndex = 19;
			this->numericUpDown_price->Leave += gcnew System::EventHandler(this, &MainWindow::edit_item);
			// 
			// numericUpDown_amount
			// 
			this->numericUpDown_amount->Location = System::Drawing::Point(220, 42);
			this->numericUpDown_amount->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {99999, 0, 0, 0});
			this->numericUpDown_amount->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->numericUpDown_amount->Name = L"numericUpDown_amount";
			this->numericUpDown_amount->Size = System::Drawing::Size(65, 20);
			this->numericUpDown_amount->TabIndex = 3;
			this->numericUpDown_amount->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->numericUpDown_amount->Leave += gcnew System::EventHandler(this, &MainWindow::edit_item);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(168, 46);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(46, 13);
			this->label7->TabIndex = 2;
			this->label7->Text = L"Amount:";
			// 
			// comboBox_surface
			// 
			this->comboBox_surface->FormattingEnabled = true;
			this->comboBox_surface->Location = System::Drawing::Point(81, 178);
			this->comboBox_surface->Name = L"comboBox_surface";
			this->comboBox_surface->Size = System::Drawing::Size(340, 21);
			this->comboBox_surface->TabIndex = 12;
			this->comboBox_surface->Leave += gcnew System::EventHandler(this, &MainWindow::edit_item);
			this->comboBox_surface->TextChanged += gcnew System::EventHandler(this, &MainWindow::load_surface);
			// 
			// button_autoDetect
			// 
			this->button_autoDetect->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button_autoDetect->Location = System::Drawing::Point(220, 67);
			this->button_autoDetect->Name = L"button_autoDetect";
			this->button_autoDetect->Size = System::Drawing::Size(65, 21);
			this->button_autoDetect->TabIndex = 6;
			this->button_autoDetect->Text = L"Detect";
			this->button_autoDetect->UseVisualStyleBackColor = true;
			this->button_autoDetect->Click += gcnew System::EventHandler(this, &MainWindow::click_autoDetect);
			// 
			// numericUpDown_itemID
			// 
			this->numericUpDown_itemID->Location = System::Drawing::Point(81, 42);
			this->numericUpDown_itemID->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {99999, 0, 0, 0});
			this->numericUpDown_itemID->Name = L"numericUpDown_itemID";
			this->numericUpDown_itemID->Size = System::Drawing::Size(65, 20);
			this->numericUpDown_itemID->TabIndex = 1;
			this->numericUpDown_itemID->Leave += gcnew System::EventHandler(this, &MainWindow::edit_item);
			// 
			// textBox_name
			// 
			this->textBox_name->Location = System::Drawing::Point(81, 94);
			this->textBox_name->MaxLength = 32;
			this->textBox_name->Name = L"textBox_name";
			this->textBox_name->Size = System::Drawing::Size(204, 20);
			this->textBox_name->TabIndex = 8;
			this->textBox_name->Leave += gcnew System::EventHandler(this, &MainWindow::edit_item);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(6, 97);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(38, 13);
			this->label6->TabIndex = 7;
			this->label6->Text = L"Name:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(6, 46);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(44, 13);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Item ID:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 181);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(47, 13);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Surface:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 123);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(63, 13);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Description:";
			// 
			// textBox_description
			// 
			this->textBox_description->Location = System::Drawing::Point(81, 120);
			this->textBox_description->MaxLength = 512;
			this->textBox_description->Multiline = true;
			this->textBox_description->Name = L"textBox_description";
			this->textBox_description->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox_description->Size = System::Drawing::Size(204, 52);
			this->textBox_description->TabIndex = 10;
			this->textBox_description->Leave += gcnew System::EventHandler(this, &MainWindow::edit_item);
			// 
			// pictureBox_surface
			// 
			this->pictureBox_surface->BackColor = System::Drawing::Color::Gray;
			this->pictureBox_surface->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox_surface->Location = System::Drawing::Point(291, 42);
			this->pictureBox_surface->Name = L"pictureBox_surface";
			this->pictureBox_surface->Size = System::Drawing::Size(130, 130);
			this->pictureBox_surface->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox_surface->TabIndex = 6;
			this->pictureBox_surface->TabStop = false;
			// 
			// textBox_search
			// 
			this->textBox_search->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox_search->Location = System::Drawing::Point(2, 559);
			this->textBox_search->Name = L"textBox_search";
			this->textBox_search->Size = System::Drawing::Size(256, 20);
			this->textBox_search->TabIndex = 5;
			this->textBox_search->Text = L"ID or Name";
			this->textBox_search->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox_search->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainWindow::keyPress_search);
			// 
			// button_search
			// 
			this->button_search->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button_search->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button_search->Location = System::Drawing::Point(264, 559);
			this->button_search->Name = L"button_search";
			this->button_search->Size = System::Drawing::Size(93, 20);
			this->button_search->TabIndex = 6;
			this->button_search->Text = L"Find Next";
			this->button_search->UseVisualStyleBackColor = true;
			this->button_search->Click += gcnew System::EventHandler(this, &MainWindow::click_search);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->fileToolStripMenuItem, 
				this->toolsToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
			this->menuStrip1->Size = System::Drawing::Size(792, 24);
			this->menuStrip1->TabIndex = 7;
			this->menuStrip1->Text = L"menuStrip_main";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(10) {this->loadToolStripMenuItem, 
				this->saveToolStripMenuItem, this->toolStripSeparator3, this->export136ToolStripMenuItem, this->exportClientToolStripMenuItem, 
				this->exportServerToolStripMenuItem, this->toolStripSeparator4, this->import136ClientServerToolStripMenuItem, this->impoertToolStripMenuItem, 
				this->importServerToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(35, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// loadToolStripMenuItem
			// 
			this->loadToolStripMenuItem->Name = L"loadToolStripMenuItem";
			this->loadToolStripMenuItem->Size = System::Drawing::Size(182, 22);
			this->loadToolStripMenuItem->Text = L"Load DB...";
			this->loadToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::click_load);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(182, 22);
			this->saveToolStripMenuItem->Text = L"Save DB...";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::click_save);
			// 
			// toolStripSeparator3
			// 
			this->toolStripSeparator3->Name = L"toolStripSeparator3";
			this->toolStripSeparator3->Size = System::Drawing::Size(179, 6);
			// 
			// export136ToolStripMenuItem
			// 
			this->export136ToolStripMenuItem->Name = L"export136ToolStripMenuItem";
			this->export136ToolStripMenuItem->Size = System::Drawing::Size(182, 22);
			this->export136ToolStripMenuItem->Text = L"Export 1.3.6...";
			this->export136ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::click_export_136);
			// 
			// exportClientToolStripMenuItem
			// 
			this->exportClientToolStripMenuItem->Name = L"exportClientToolStripMenuItem";
			this->exportClientToolStripMenuItem->Size = System::Drawing::Size(182, 22);
			this->exportClientToolStripMenuItem->Text = L"Export 1.4.4 Client...";
			this->exportClientToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::click_export_client);
			// 
			// exportServerToolStripMenuItem
			// 
			this->exportServerToolStripMenuItem->Name = L"exportServerToolStripMenuItem";
			this->exportServerToolStripMenuItem->Size = System::Drawing::Size(182, 22);
			this->exportServerToolStripMenuItem->Text = L"Export 1.4.4 Server...";
			this->exportServerToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::click_export_server);
			// 
			// toolStripSeparator4
			// 
			this->toolStripSeparator4->Name = L"toolStripSeparator4";
			this->toolStripSeparator4->Size = System::Drawing::Size(179, 6);
			// 
			// import136ClientServerToolStripMenuItem
			// 
			this->import136ClientServerToolStripMenuItem->Name = L"import136ClientServerToolStripMenuItem";
			this->import136ClientServerToolStripMenuItem->Size = System::Drawing::Size(182, 22);
			this->import136ClientServerToolStripMenuItem->Text = L"Import 1.3.6...";
			this->import136ClientServerToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::click_import_136);
			// 
			// impoertToolStripMenuItem
			// 
			this->impoertToolStripMenuItem->Name = L"impoertToolStripMenuItem";
			this->impoertToolStripMenuItem->Size = System::Drawing::Size(182, 22);
			this->impoertToolStripMenuItem->Text = L"Import 1.4.4 Client...";
			this->impoertToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::click_import_client);
			// 
			// importServerToolStripMenuItem
			// 
			this->importServerToolStripMenuItem->Name = L"importServerToolStripMenuItem";
			this->importServerToolStripMenuItem->Size = System::Drawing::Size(182, 22);
			this->importServerToolStripMenuItem->Text = L"Import 1.4.4 Server...";
			this->importServerToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::click_import_server);
			// 
			// toolsToolStripMenuItem
			// 
			this->toolsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->setAllPricesToolStripMenuItem, 
				this->setAllControlTypesClientToolStripMenuItem, this->setAllControlTypesServerToolStripMenuItem});
			this->toolsToolStripMenuItem->Name = L"toolsToolStripMenuItem";
			this->toolsToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->toolsToolStripMenuItem->Text = L"Edit";
			// 
			// setAllPricesToolStripMenuItem
			// 
			this->setAllPricesToolStripMenuItem->Name = L"setAllPricesToolStripMenuItem";
			this->setAllPricesToolStripMenuItem->Size = System::Drawing::Size(209, 22);
			this->setAllPricesToolStripMenuItem->Text = L"Set All Default Prices 0.01";
			this->setAllPricesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::click_set_prices);
			// 
			// setAllControlTypesClientToolStripMenuItem
			// 
			this->setAllControlTypesClientToolStripMenuItem->Name = L"setAllControlTypesClientToolStripMenuItem";
			this->setAllControlTypesClientToolStripMenuItem->Size = System::Drawing::Size(209, 22);
			this->setAllControlTypesClientToolStripMenuItem->Text = L"Set All Control Types Client";
			this->setAllControlTypesClientToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::click_set_control_type_client);
			// 
			// setAllControlTypesServerToolStripMenuItem
			// 
			this->setAllControlTypesServerToolStripMenuItem->Name = L"setAllControlTypesServerToolStripMenuItem";
			this->setAllControlTypesServerToolStripMenuItem->Size = System::Drawing::Size(209, 22);
			this->setAllControlTypesServerToolStripMenuItem->Text = L"Set All Control Types Server";
			this->setAllControlTypesServerToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::click_set_control_type_server);
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(792, 581);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->button_search);
			this->Controls->Add(this->textBox_search);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->MainMenuStrip = this->menuStrip1;
			this->MinimumSize = System::Drawing::Size(800, 608);
			this->Name = L"MainWindow";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L" sGSHOPedit";
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->contextMenuStrip_SubCat->ResumeLayout(false);
			this->contextMenuStrip_Item->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown_log_price))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown_gift_amount))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown_gift_id))->EndInit();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown_price))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown_amount))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown_itemID))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox_surface))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		void initialize()
		{
			comboBox_dbSource->SelectedIndex = 0;
			comboBox_sale_option->SelectedIndex = 0;
			comboBox_status->SelectedIndex = 0;
			comboBox_type->SelectedIndex = 0;
			comboBox_surface->Items->Clear();
			click_get_timestamp(nullptr, nullptr);
			array<String^>^ files = Directory::GetFiles(Application::StartupPath + L"\\surfaces\\百宝阁");

			for(int i=0; i<files->Length; i++)
			{
				comboBox_surface->Items->Add(files[i]->Replace(Application::StartupPath + "\\", "")->Replace(".jpg", ".dds"));
			}

			itemDescriptions = gcnew SortedList();

			if(File::Exists(Application::StartupPath + "\\" + "item_ext_desc.txt"))
			{
				StreamReader^ sr = gcnew StreamReader(Application::StartupPath + "\\" + "item_ext_desc.txt", System::Text::Encoding::GetEncoding("Unicode"));
				String^ line;

				while((line = sr->ReadLine()))
				{
					if(line!="" && !line->StartsWith("/") && !line->StartsWith("#"))
					{
						array<String^>^ pair = line->Split(gcnew array<wchar_t>{'"'});
						itemDescriptions->Add(pair[0]->Trim(), pair[1]);
					}
				}

				sr->Close();
			}
		}

		void build_contextMenus()
		{
			toolStripMenuItem_moveCat->DropDownItems->Clear();
			toolStripMenuItem_moveItem->DropDownItems->Clear();
			for(int i=0; i<GSHOP->categories->Length; i++)
			{
				toolStripMenuItem_moveCat->DropDownItems->Add(bytes_to_string(GSHOP->categories[i]->name, "Unicode")->Split(gcnew array<wchar_t>{'\0'})[0]);
				toolStripMenuItem_moveCat->DropDownItems[i]->Click += gcnew System::EventHandler(this, &MainWindow::move_subcat);
				toolStripMenuItem_moveItem->DropDownItems->Add(bytes_to_string(GSHOP->categories[i]->name, "Unicode")->Split(gcnew array<wchar_t>{'\0'})[0]);
				for(int n=0; n<GSHOP->categories[i]->sub_cats->Length; n++)
				{
					((ToolStripMenuItem^)toolStripMenuItem_moveItem->DropDownItems[i])->DropDownItems->Add(bytes_to_string(GSHOP->categories[i]->sub_cats[n], "Unicode")->Split(gcnew array<wchar_t>{'\0'})[0]);
					((ToolStripMenuItem^)toolStripMenuItem_moveItem->DropDownItems[i])->DropDownItems[n]->Click += gcnew System::EventHandler(this, &MainWindow::move_item);
				}
			}
		}
		unsigned int string_to_timestamp(String^ date)
		{
			DateTime target = DateTime::Parse(date); // parsing depends on culture, application was set to invariant culture
			return Convert::ToUInt32(target.Subtract( DateTime(1970, 1, 1, 0, 0, 0, 0) ).TotalSeconds);
		}
		String^ timestamp_to_string(unsigned int timestamp)
		{
			DateTime origin(1970, 1, 1, 0, 0, 0, 0);
			origin = origin.AddSeconds(timestamp);
			return origin.ToString("yyyy-MM-dd HH:mm:ss");
		}
		unsigned int string_to_seconds(String^ time)
		{
			try
			{
				array<String^>^ times = time->Split(gcnew array<wchar_t>{'-', ':'});
				return ( (86400*Convert::ToUInt32(times[0])) + (3600*Convert::ToUInt32(times[1])) + (60*Convert::ToUInt32(times[2])) + Convert::ToUInt32(times[3]) );
			}
			catch(...)
			{
				return 0;
			}
		}
		String^ seconds_to_string(unsigned int time)
		{
			try
			{
				unsigned int days = time/86400;
				time = time-(days*86400);
				unsigned int hours = time/3600;
				time = time-(hours*3600);
				unsigned int minutes = time/60;
				unsigned int seconds = time-(minutes*60);

				return (days.ToString("D2") + "-" + hours.ToString("D2") + ":" + minutes.ToString("D2") + ":" + seconds.ToString("D2"));
			}
			catch(...)
			{
				return "0";
			}
		}
		String^ bytes_to_string(array<unsigned char>^ value, String^ code)
		{
			System::Text::Encoding^ enc = System::Text::Encoding::GetEncoding(code);
			return enc->GetString(value);
		}

		array<unsigned char>^ string_to_bytes(String^ value, String^ code, int bytes)
		{
			System::Text::Encoding^ enc = System::Text::Encoding::GetEncoding(code);
			array<unsigned char>^ target = gcnew array<unsigned char>(bytes);
			array<unsigned char>^ source = enc->GetBytes(value);
			if(target->Length > source->Length)
			{
				Array::Copy(source, target, source->Length);
			}
			else
			{
				Array::Copy(source, target, target->Length);
			}
			return target;
		}

		String^ ByteArray_to_HexString(array<unsigned char>^ value)
		{
			return BitConverter::ToString(value);
		}

		array<unsigned char>^ HexString_to_ByteArray(String^ value)
		{
			// Convert from Hex to byte[]
			array<String^>^ hex = value->Split(gcnew array<wchar_t>{'-'});
			array<unsigned char>^ bytes = gcnew array<unsigned char>(hex->Length);
			for(int i=0; i<hex->Length; i++)
			{
				bytes[i] = Convert::ToByte(hex[i], 16);
			}
			return bytes;
		}


		//
		private: System::Void click_load(System::Object^  sender, System::EventArgs^  e)
		{
			OpenFileDialog^ load = gcnew OpenFileDialog();
			load->Filter = "GShop DB (*.db)|*.db|All Files (*.*)|*.*";
			if(load->ShowDialog() == Windows::Forms::DialogResult::OK && File::Exists(load->FileName))
			{
				try
				{
					Cursor = Windows::Forms::Cursors::WaitCursor;
					listBox_Cats->Items->Clear();
					listBox_SubCats->Items->Clear();
					listBox_Items->Items->Clear();

					GSHOP = gcnew Boutique();

					item_id_index_map = gcnew SortedList();
					max_item_id = 0;

					FileStream^ fr = File::OpenRead(load->FileName);
					BinaryReader^ br = gcnew BinaryReader(fr);

					GSHOP->timestamp = br->ReadInt32();
					GSHOP->item_count = br->ReadInt32();
					GSHOP->items = gcnew array<Item^>(GSHOP->item_count);
					for(int i=0; i<GSHOP->items->Length; i++)
					{
						GSHOP->items[i] = gcnew Item();
						GSHOP->items[i]->activate = br->ReadBoolean();
						GSHOP->items[i]->shop_id = br->ReadInt32();
//						GSHOP->items[i]->shop_id = i;
						max_item_id = Math::Max(max_item_id, GSHOP->items[i]->shop_id);
						item_id_index_map->Add(GSHOP->items[i]->shop_id, i);
						GSHOP->items[i]->cat_index = br->ReadInt32();
						GSHOP->items[i]->sub_cat_index = br->ReadInt32();
						GSHOP->items[i]->surface_path = br->ReadBytes(128);
						GSHOP->items[i]->item_id = br->ReadInt32();
						GSHOP->items[i]->item_amount = br->ReadInt32();

						GSHOP->items[i]->sale_options = gcnew array<SaleOption^>(4);
						for(int n=0; n<GSHOP->items[i]->sale_options->Length; n++)
						{
							GSHOP->items[i]->sale_options[n] = gcnew SaleOption();
							GSHOP->items[i]->sale_options[n]->price = br->ReadInt32();
							GSHOP->items[i]->sale_options[n]->expire_date = br->ReadInt32();
							GSHOP->items[i]->sale_options[n]->duration = br->ReadInt32();
							GSHOP->items[i]->sale_options[n]->start_date = br->ReadInt32();
							GSHOP->items[i]->sale_options[n]->control_type = br->ReadInt32();
							GSHOP->items[i]->sale_options[n]->day = br->ReadInt32();
							GSHOP->items[i]->sale_options[n]->status = br->ReadInt32();
							GSHOP->items[i]->sale_options[n]->flags = br->ReadInt32();
						}

						GSHOP->items[i]->description = br->ReadBytes(1024);
						GSHOP->items[i]->name = br->ReadBytes(64);
						GSHOP->items[i]->gift_id = br->ReadInt32();
						GSHOP->items[i]->gift_amount = br->ReadInt32();
						GSHOP->items[i]->gift_duration = br->ReadInt32();
						GSHOP->items[i]->log_price = br->ReadInt32();
					}

					GSHOP->categories = gcnew array<Category^>(8);
					for(int i=0; i<GSHOP->categories->Length; i++)
					{
						GSHOP->categories[i] = gcnew Category();
						GSHOP->categories[i]->name = br->ReadBytes(128);
						GSHOP->categories[i]->sub_cats_count = br->ReadInt32();
						GSHOP->categories[i]->sub_cats = gcnew array<array<unsigned char>^>(GSHOP->categories[i]->sub_cats_count);
						for(int n=0; n<GSHOP->categories[i]->sub_cats->Length; n++)
						{
							GSHOP->categories[i]->sub_cats[n] = br->ReadBytes(128);
						}

						listBox_Cats->Items->Add(bytes_to_string(GSHOP->categories[i]->name, "Unicode"));
					}

					br->Close();
					fr->Close();

					build_contextMenus();
					textBox_timestamp->Text = timestamp_to_string(GSHOP->timestamp);

					Cursor = Windows::Forms::Cursors::Default;
				}
				catch(Exception^ e)
				{
					Cursor = Windows::Forms::Cursors::Default;
					MessageBox::Show("LOADING ERROR!\n\n" + e->Message);
				}
			}
		}

		private: System::Void click_import_136(System::Object^  sender, System::EventArgs^  e)
		{
			OpenFileDialog^ load = gcnew OpenFileDialog();
			load->Filter = "GShop (*.data)|*.data|All Files (*.*)|*.*";
			if(load->ShowDialog() == Windows::Forms::DialogResult::OK && File::Exists(load->FileName))
			{
				try
				{
					Cursor = Windows::Forms::Cursors::WaitCursor;
					listBox_Cats->Items->Clear();
					listBox_SubCats->Items->Clear();
					listBox_Items->Items->Clear();

					GSHOP = gcnew Boutique();
					item_id_index_map = gcnew SortedList();
					max_item_id = 0;

					FileStream^ fr = File::OpenRead(load->FileName);
					BinaryReader^ br = gcnew BinaryReader(fr);

					GSHOP->timestamp = br->ReadInt32();
					GSHOP->item_count = br->ReadInt32();
					GSHOP->items = gcnew array<Item^>(GSHOP->item_count);
					for(int i=0; i<GSHOP->items->Length; i++)
					{
						GSHOP->items[i] = gcnew Item();
						GSHOP->items[i]->activate = true;
						GSHOP->items[i]->shop_id = br->ReadInt32();
//						GSHOP->items[i]->shop_id = i;
						max_item_id = Math::Max(max_item_id, GSHOP->items[i]->shop_id);
						item_id_index_map->Add(GSHOP->items[i]->shop_id, i);
						GSHOP->items[i]->cat_index = br->ReadInt32();
						GSHOP->items[i]->sub_cat_index = br->ReadInt32();
						GSHOP->items[i]->surface_path = br->ReadBytes(128);
						GSHOP->items[i]->item_id = br->ReadInt32();
						GSHOP->items[i]->item_amount = br->ReadInt32();

						GSHOP->items[i]->sale_options = gcnew array<SaleOption^>(4);
						for(int n=0; n<GSHOP->items[i]->sale_options->Length; n++)
						{
							GSHOP->items[i]->sale_options[n] = gcnew SaleOption();
							// read price
							GSHOP->items[i]->sale_options[n]->price = br->ReadInt32();
							// ignore unknown value
							br->ReadInt32();
							GSHOP->items[i]->sale_options[n]->expire_date = 0;
							// read duration
							GSHOP->items[i]->sale_options[n]->duration = br->ReadInt32();
							GSHOP->items[i]->sale_options[n]->start_date = 0;
							GSHOP->items[i]->sale_options[n]->control_type = -1;
							GSHOP->items[i]->sale_options[n]->day = 0;
							GSHOP->items[i]->sale_options[n]->status = 0;
							GSHOP->items[i]->sale_options[n]->flags = 0;
						}

						// read status and apply to first sale option
						GSHOP->items[i]->sale_options[0]->status = br->ReadInt32();

						GSHOP->items[i]->description = br->ReadBytes(1024);
						GSHOP->items[i]->name = br->ReadBytes(64);
						GSHOP->items[i]->gift_id = 0;
						GSHOP->items[i]->gift_amount = 0;
						GSHOP->items[i]->gift_duration = 0;
						GSHOP->items[i]->log_price = 0;
					}

					GSHOP->categories = gcnew array<Category^>(8);
					for(int i=0; i<GSHOP->categories->Length; i++)
					{
						GSHOP->categories[i] = gcnew Category();
						GSHOP->categories[i]->name = br->ReadBytes(128);
						GSHOP->categories[i]->sub_cats_count = br->ReadInt32();
						GSHOP->categories[i]->sub_cats = gcnew array<array<unsigned char>^>(GSHOP->categories[i]->sub_cats_count);
						for(int n=0; n<GSHOP->categories[i]->sub_cats->Length; n++)
						{
							GSHOP->categories[i]->sub_cats[n] = br->ReadBytes(128);
						}

						listBox_Cats->Items->Add(bytes_to_string(GSHOP->categories[i]->name, "Unicode"));
					}

					br->Close();
					fr->Close();

					build_contextMenus();
					textBox_timestamp->Text = timestamp_to_string(GSHOP->timestamp);

					Cursor = Windows::Forms::Cursors::Default;
				}
				catch(Exception^ e)
				{
					Cursor = Windows::Forms::Cursors::Default;
					MessageBox::Show("IMPORT ERROR!\n\n" + e->Message);
				}
			}
		}

		private: System::Void click_import_client(System::Object^  sender, System::EventArgs^  e)
		{
			OpenFileDialog^ load = gcnew OpenFileDialog();
			load->Filter = "GShop (*.data)|*.data|All Files (*.*)|*.*";
			if(load->ShowDialog() == Windows::Forms::DialogResult::OK && File::Exists(load->FileName))
			{
				try
				{
					Cursor = Windows::Forms::Cursors::WaitCursor;
					listBox_Cats->Items->Clear();
					listBox_SubCats->Items->Clear();
					listBox_Items->Items->Clear();

					GSHOP = gcnew Boutique();
					item_id_index_map = gcnew SortedList();
					max_item_id = 0;

					FileStream^ fr = File::OpenRead(load->FileName);
					BinaryReader^ br = gcnew BinaryReader(fr);

					GSHOP->timestamp = br->ReadInt32();
					GSHOP->item_count = br->ReadInt32();
					GSHOP->items = gcnew array<Item^>(GSHOP->item_count);
					for(int i=0; i<GSHOP->items->Length; i++)
					{
						GSHOP->items[i] = gcnew Item();
						GSHOP->items[i]->activate = true;
						GSHOP->items[i]->shop_id = br->ReadInt32();
//						GSHOP->items[i]->shop_id = i;
						max_item_id = Math::Max(max_item_id, GSHOP->items[i]->shop_id);
						item_id_index_map->Add(GSHOP->items[i]->shop_id, i);
						GSHOP->items[i]->cat_index = br->ReadInt32();
						GSHOP->items[i]->sub_cat_index = br->ReadInt32();
						GSHOP->items[i]->surface_path = br->ReadBytes(128);
						GSHOP->items[i]->item_id = br->ReadInt32();
						GSHOP->items[i]->item_amount = br->ReadInt32();

						GSHOP->items[i]->sale_options = gcnew array<SaleOption^>(4);
						for(int n=0; n<GSHOP->items[i]->sale_options->Length; n++)
						{
							GSHOP->items[i]->sale_options[n] = gcnew SaleOption();
							GSHOP->items[i]->sale_options[n]->price = br->ReadInt32();
							GSHOP->items[i]->sale_options[n]->expire_date = br->ReadInt32();
							GSHOP->items[i]->sale_options[n]->duration = br->ReadInt32();
							GSHOP->items[i]->sale_options[n]->start_date = br->ReadInt32();
							GSHOP->items[i]->sale_options[n]->control_type = br->ReadInt32();
							GSHOP->items[i]->sale_options[n]->day = br->ReadInt32();
							GSHOP->items[i]->sale_options[n]->status = br->ReadInt32();
							GSHOP->items[i]->sale_options[n]->flags = br->ReadInt32();
						}

						GSHOP->items[i]->description = br->ReadBytes(1024);
						GSHOP->items[i]->name = br->ReadBytes(64);
						GSHOP->items[i]->gift_id = br->ReadInt32();
						GSHOP->items[i]->gift_amount = br->ReadInt32();
						GSHOP->items[i]->gift_duration = br->ReadInt32();
						GSHOP->items[i]->log_price = br->ReadInt32();
					}

					GSHOP->categories = gcnew array<Category^>(8);
					for(int i=0; i<GSHOP->categories->Length; i++)
					{
						GSHOP->categories[i] = gcnew Category();
						GSHOP->categories[i]->name = br->ReadBytes(128);
						GSHOP->categories[i]->sub_cats_count = br->ReadInt32();
						GSHOP->categories[i]->sub_cats = gcnew array<array<unsigned char>^>(GSHOP->categories[i]->sub_cats_count);
						for(int n=0; n<GSHOP->categories[i]->sub_cats->Length; n++)
						{
							GSHOP->categories[i]->sub_cats[n] = br->ReadBytes(128);
						}

						listBox_Cats->Items->Add(bytes_to_string(GSHOP->categories[i]->name, "Unicode"));
					}

					br->Close();
					fr->Close();

					build_contextMenus();
					textBox_timestamp->Text = timestamp_to_string(GSHOP->timestamp);

					Cursor = Windows::Forms::Cursors::Default;
				}
				catch(Exception^ e)
				{
					Cursor = Windows::Forms::Cursors::Default;
					MessageBox::Show("IMPORT ERROR!\n\n" + e->Message);
				}
			}
		}

		private: System::Void click_import_server(System::Object^  sender, System::EventArgs^  e)
		{
			OpenFileDialog^ load = gcnew OpenFileDialog();
			load->Filter = "GShop (*.data)|*.data|All Files (*.*)|*.*";
			if(load->ShowDialog() == Windows::Forms::DialogResult::OK && File::Exists(load->FileName))
			{
				try
				{
					Cursor = Windows::Forms::Cursors::WaitCursor;
					listBox_Cats->Items->Clear();
					listBox_SubCats->Items->Clear();
					listBox_Items->Items->Clear();

					GSHOP = gcnew Boutique();
					GSHOP->categories = gcnew array<Category^>(8);
					for(int i=0; i<GSHOP->categories->Length; i++)
					{
						GSHOP->categories[i] = gcnew Category();
						GSHOP->categories[i]->name = string_to_bytes("NULL", "Unicode", 128);
						GSHOP->categories[i]->sub_cats_count = 0;
					}
					item_id_index_map = gcnew SortedList();
					max_item_id = 0;

					FileStream^ fr = File::OpenRead(load->FileName);
					BinaryReader^ br = gcnew BinaryReader(fr);

					GSHOP->timestamp = br->ReadInt32();
					GSHOP->item_count = br->ReadInt32();
					GSHOP->items = gcnew array<Item^>(GSHOP->item_count);
					for(int i=0; i<GSHOP->items->Length; i++)
					{
						GSHOP->items[i] = gcnew Item();
						GSHOP->items[i]->activate = true;
						GSHOP->items[i]->shop_id = br->ReadInt32();
//						GSHOP->items[i]->shop_id = i;
						max_item_id = Math::Max(max_item_id, GSHOP->items[i]->shop_id);
						item_id_index_map->Add(GSHOP->items[i]->shop_id, i);
						GSHOP->items[i]->cat_index = br->ReadInt32();
						GSHOP->items[i]->sub_cat_index = br->ReadInt32();
						// update counter for subcategories
						GSHOP->categories[GSHOP->items[i]->cat_index]->sub_cats_count = Math::Max(GSHOP->categories[GSHOP->items[i]->cat_index]->sub_cats_count, GSHOP->items[i]->sub_cat_index+1);
						GSHOP->items[i]->surface_path = gcnew array<unsigned char>(128);
						GSHOP->items[i]->item_id = br->ReadInt32();
						GSHOP->items[i]->item_amount = br->ReadInt32();

						GSHOP->items[i]->sale_options = gcnew array<SaleOption^>(4);
						for(int n=0; n<GSHOP->items[i]->sale_options->Length; n++)
						{
							GSHOP->items[i]->sale_options[n] = gcnew SaleOption();
							GSHOP->items[i]->sale_options[n]->price = br->ReadInt32();
							GSHOP->items[i]->sale_options[n]->expire_date = br->ReadInt32();
							GSHOP->items[i]->sale_options[n]->duration = br->ReadInt32();
							GSHOP->items[i]->sale_options[n]->start_date = br->ReadInt32();
							GSHOP->items[i]->sale_options[n]->control_type = br->ReadInt32();
							GSHOP->items[i]->sale_options[n]->day = br->ReadInt32();
							GSHOP->items[i]->sale_options[n]->status = br->ReadInt32();
							GSHOP->items[i]->sale_options[n]->flags = br->ReadInt32();
						}

						GSHOP->items[i]->description = gcnew array<unsigned char>(1024);
						GSHOP->items[i]->name = gcnew array<unsigned char>(64);
						GSHOP->items[i]->gift_id = br->ReadInt32();
						GSHOP->items[i]->gift_amount = br->ReadInt32();
						GSHOP->items[i]->gift_duration = br->ReadInt32();
						GSHOP->items[i]->log_price = br->ReadInt32();
					}

					for(int i=0; i<GSHOP->categories->Length; i++)
					{
						GSHOP->categories[i]->sub_cats = gcnew array<array<unsigned char>^>(GSHOP->categories[i]->sub_cats_count);
						for(int n=0; n<GSHOP->categories[i]->sub_cats->Length; n++)
						{
							GSHOP->categories[i]->sub_cats[n] = string_to_bytes("NULL", "Unicode", 128);
						}

						listBox_Cats->Items->Add(bytes_to_string(GSHOP->categories[i]->name, "Unicode"));
					}

					br->Close();
					fr->Close();

					build_contextMenus();
					textBox_timestamp->Text = timestamp_to_string(GSHOP->timestamp);

					Cursor = Windows::Forms::Cursors::Default;
				}
				catch(Exception^ e)
				{
					Cursor = Windows::Forms::Cursors::Default;
					MessageBox::Show("IMPORT ERROR!\n\n" + e->Message);
				}
			}
		}

		private: System::Void click_save(System::Object^  sender, System::EventArgs^  e)
		{
			SaveFileDialog^ save = gcnew SaveFileDialog();
			save->Filter = "GShop DB (*.db)|*.db|All Files (*.*)|*.*";
			if(GSHOP && save->ShowDialog() == Windows::Forms::DialogResult::OK)
			{
				try
				{
					Cursor = Windows::Forms::Cursors::WaitCursor;

					FileStream^ fw = gcnew FileStream(save->FileName, FileMode::Create, FileAccess::Write);
					BinaryWriter^ bw = gcnew BinaryWriter(fw);

					GSHOP->timestamp = string_to_timestamp(textBox_timestamp->Text);
					bw->Write(GSHOP->timestamp);
					bw->Write(GSHOP->item_count);
					int	shop_id = 0;
					for(int i=0; i<GSHOP->items->Length; i++)
					{
						if(GSHOP->items[i]->cat_index>-1 && GSHOP->items[i]->sub_cat_index>-1)
						{
							bw->Write(GSHOP->items[i]->activate);
							bw->Write(GSHOP->items[i]->shop_id);; //bw->Write(shop_id);
							bw->Write(GSHOP->items[i]->cat_index);
							bw->Write(GSHOP->items[i]->sub_cat_index);
							bw->Write(GSHOP->items[i]->surface_path);
							bw->Write(GSHOP->items[i]->item_id);
							bw->Write(GSHOP->items[i]->item_amount);

							for(int n=0; n<GSHOP->items[i]->sale_options->Length; n++)
							{
								bw->Write(GSHOP->items[i]->sale_options[n]->price);
								bw->Write(GSHOP->items[i]->sale_options[n]->expire_date);
								bw->Write(GSHOP->items[i]->sale_options[n]->duration);
								bw->Write(GSHOP->items[i]->sale_options[n]->start_date);
								bw->Write(GSHOP->items[i]->sale_options[n]->control_type);
								bw->Write(GSHOP->items[i]->sale_options[n]->day);
								bw->Write(GSHOP->items[i]->sale_options[n]->status);
								bw->Write(GSHOP->items[i]->sale_options[n]->flags);
							}

							bw->Write(GSHOP->items[i]->description);
							bw->Write(GSHOP->items[i]->name);
							bw->Write(GSHOP->items[i]->gift_id);
							bw->Write(GSHOP->items[i]->gift_amount);
							bw->Write(GSHOP->items[i]->gift_duration);
							bw->Write(GSHOP->items[i]->log_price);

							shop_id++;
						}
					}

					for(int i=0;i<GSHOP->categories->Length; i++)
					{
						bw->Write(GSHOP->categories[i]->name);
						bw->Write(GSHOP->categories[i]->sub_cats->Length);
						for(int n=0; n<GSHOP->categories[i]->sub_cats->Length; n++)
						{
							bw->Write(GSHOP->categories[i]->sub_cats[n]);
						}
					}

					bw->Close();
					fw->Close();;

					Cursor = Windows::Forms::Cursors::Default;
				}
				catch(Exception^ e)
				{
					Cursor = Windows::Forms::Cursors::Default;
					MessageBox::Show("SAVING ERROR!\n\n" + e->Message);
				}
			}
		}

		private: System::Void click_export_136(System::Object^  sender, System::EventArgs^  e)
		{
			MessageBox::Show("Currently not Available!");
			/*
			SaveFileDialog^ save = gcnew SaveFileDialog();
			save->Filter = "GShop (*.data)|*.data|All Files (*.*)|*.*";
			if(GSHOP && save->ShowDialog() == Windows::Forms::DialogResult::OK)
			{
				try
				{
					Cursor = Windows::Forms::Cursors::WaitCursor;

					FileStream^ fw = gcnew FileStream(save->FileName, FileMode::Create, FileAccess::Write);
					BinaryWriter^ bw = gcnew BinaryWriter(fw);

					bw->Write(GSHOP->timestamp);
					bw->Write(GSHOP->item_count);
					int	shop_id = 0;
					for(int i=0; i<GSHOP->items->Length; i++)
					{
						if(GSHOP->items[i]->cat_index>-1 && GSHOP->items[i]->sub_cat_index>-1)
						{
							// shop id in client server cn be different
							// so we can use an increment value
							bw->Write(shop_id);
							bw->Write(GSHOP->items[i]->cat_index);
							bw->Write(GSHOP->items[i]->sub_cat_index);
							bw->Write(GSHOP->items[i]->surface_path);
							bw->Write(GSHOP->items[i]->item_id);
							bw->Write(GSHOP->items[i]->item_amount);

							for(int n=0; n<GSHOP->items[i]->sale_options->Length; n++)
							{
								bw->Write(GSHOP->items[i]->sale_options[n]->price);
								bw->Write(0); //bw->Write(GSHOP->items[i]->sale_options[n]->expire_date);
								bw->Write(GSHOP->items[i]->sale_options[n]->duration);
								bw->Write(0); //bw->Write(GSHOP->items[i]->sale_options[n]->start_date);
								bw->Write(GSHOP->items[i]->sale_options[n]->type);
								bw->Write(GSHOP->items[i]->sale_options[n]->day);
								bw->Write(GSHOP->items[i]->sale_options[n]->status);
								bw->Write(GSHOP->items[i]->sale_options[n]->flags);
							}

							bw->Write(GSHOP->items[i]->description);
							bw->Write(GSHOP->items[i]->name);
							bw->Write(GSHOP->items[i]->gift_id);
							bw->Write(GSHOP->items[i]->gift_amount);
							bw->Write(GSHOP->items[i]->gift_duration);
							bw->Write(GSHOP->items[i]->log_price);

							shop_id++;
						}
					}

					for(int i=0;i<GSHOP->categories->Length; i++)
					{
						bw->Write(GSHOP->categories[i]->name);
						bw->Write(GSHOP->categories[i]->sub_cats->Length);
						for(int n=0; n<GSHOP->categories[i]->sub_cats->Length; n++)
						{
							bw->Write(GSHOP->categories[i]->sub_cats[n]);
						}
					}

					bw->Close();
					fw->Close();;

					Cursor = Windows::Forms::Cursors::Default;
				}
				catch(Exception^ e)
				{
					Cursor = Windows::Forms::Cursors::Default;
					MessageBox::Show("EXPORT ERROR!\n\n" + e->Message);
				}
			}
			*/
		}

		private: System::Void click_export_client(System::Object^  sender, System::EventArgs^  e)
		{
			SaveFileDialog^ save = gcnew SaveFileDialog();
			save->Filter = "GShop (*.data)|*.data|All Files (*.*)|*.*";
			if(GSHOP && save->ShowDialog() == Windows::Forms::DialogResult::OK)
			{
				try
				{
					Cursor = Windows::Forms::Cursors::WaitCursor;

					FileStream^ fw = gcnew FileStream(save->FileName, FileMode::Create, FileAccess::Write);
					BinaryWriter^ bw = gcnew BinaryWriter(fw);

					GSHOP->timestamp = string_to_timestamp(textBox_timestamp->Text);
					bw->Write(GSHOP->timestamp);
					bw->Write(GSHOP->item_count);
					int	shop_id = 0;
					for(int i=0; i<GSHOP->items->Length; i++)
					{
						if(GSHOP->items[i]->cat_index>-1 && GSHOP->items[i]->sub_cat_index>-1)
						{
							bw->Write(GSHOP->items[i]->shop_id);; //bw->Write(shop_id);
							bw->Write(GSHOP->items[i]->cat_index);
							bw->Write(GSHOP->items[i]->sub_cat_index);
							bw->Write(GSHOP->items[i]->surface_path);
							bw->Write(GSHOP->items[i]->item_id);
							bw->Write(GSHOP->items[i]->item_amount);

							for(int n=0; n<GSHOP->items[i]->sale_options->Length; n++)
							{
								// only write values to client when control_type = "client"
								if(GSHOP->items[i]->sale_options[n]->control_type == -1)
								{
									bw->Write(GSHOP->items[i]->sale_options[n]->price);
									bw->Write(GSHOP->items[i]->sale_options[n]->expire_date);
									bw->Write(GSHOP->items[i]->sale_options[n]->duration);
									bw->Write(GSHOP->items[i]->sale_options[n]->start_date);
								}
								else
								{
									bw->Write((unsigned int)0);
									bw->Write((unsigned int)0);
									bw->Write((unsigned int)0);
									bw->Write((unsigned int)0);
								}
								//bw->Write((unsigned int)0); // never write end_date to client (seems to be controled by server)
								//bw->Write(GSHOP->items[i]->sale_options[n]->duration); // always write duration to client
								//bw->Write((unsigned int)0); // never write start_date to client (seems to be controled by server)
								bw->Write(GSHOP->items[i]->sale_options[n]->control_type);
								bw->Write(GSHOP->items[i]->sale_options[n]->day);
								bw->Write(GSHOP->items[i]->sale_options[n]->status);
								bw->Write(GSHOP->items[i]->sale_options[n]->flags);
							}

							bw->Write(GSHOP->items[i]->description);
							bw->Write(GSHOP->items[i]->name);
							bw->Write(GSHOP->items[i]->gift_id);
							bw->Write(GSHOP->items[i]->gift_amount);
							bw->Write(GSHOP->items[i]->gift_duration);
							bw->Write(GSHOP->items[i]->log_price);

							shop_id++;
						}
					}

					for(int i=0;i<GSHOP->categories->Length; i++)
					{
						bw->Write(GSHOP->categories[i]->name);
						bw->Write(GSHOP->categories[i]->sub_cats->Length);
						for(int n=0; n<GSHOP->categories[i]->sub_cats->Length; n++)
						{
							bw->Write(GSHOP->categories[i]->sub_cats[n]);
						}
					}

					bw->Close();
					fw->Close();;

					Cursor = Windows::Forms::Cursors::Default;
				}
				catch(Exception^ e)
				{
					Cursor = Windows::Forms::Cursors::Default;
					MessageBox::Show("EXPORT ERROR!\n\n" + e->Message);
				}
			}
		}

		private: System::Void click_export_server(System::Object^  sender, System::EventArgs^  e)
		{
			SaveFileDialog^ save = gcnew SaveFileDialog();
			save->Filter = "GShopSev (*.data)|*.data|All Files (*.*)|*.*";
			if(GSHOP && save->ShowDialog() == Windows::Forms::DialogResult::OK)
			{
				try
				{
					Cursor = Windows::Forms::Cursors::WaitCursor;

					FileStream^ fw = gcnew FileStream(save->FileName, FileMode::Create, FileAccess::Write);
					BinaryWriter^ bw = gcnew BinaryWriter(fw);

					GSHOP->timestamp = string_to_timestamp(textBox_timestamp->Text);
					bw->Write(GSHOP->timestamp);
					int active_item_count = 0;
					for(int i=0; i<GSHOP->items->Length; i++)
					{
						if(GSHOP->items[i]->activate && GSHOP->items[i]->cat_index>-1 && GSHOP->items[i]->sub_cat_index>-1)
						{
							active_item_count++;
						}
					}
					bw->Write(active_item_count); //bw->Write(GSHOP->item_count);
					int	shop_id = 0;
					for(int i=0; i<GSHOP->items->Length; i++)
					{
						if(GSHOP->items[i]->activate && GSHOP->items[i]->cat_index>-1 && GSHOP->items[i]->sub_cat_index>-1)
						{
							bw->Write(GSHOP->items[i]->shop_id);; //bw->Write(shop_id);
							bw->Write(GSHOP->items[i]->cat_index);
							bw->Write(GSHOP->items[i]->sub_cat_index);
							bw->Write(GSHOP->items[i]->item_id);
							bw->Write(GSHOP->items[i]->item_amount);

							for(int n=0; n<GSHOP->items[i]->sale_options->Length; n++)
							{
								bw->Write(GSHOP->items[i]->sale_options[n]->price);
								bw->Write(GSHOP->items[i]->sale_options[n]->expire_date);
								bw->Write(GSHOP->items[i]->sale_options[n]->duration);
								bw->Write(GSHOP->items[i]->sale_options[n]->start_date);
								bw->Write(GSHOP->items[i]->sale_options[n]->control_type);
								bw->Write(GSHOP->items[i]->sale_options[n]->day);
								bw->Write(GSHOP->items[i]->sale_options[n]->status);
								bw->Write(GSHOP->items[i]->sale_options[n]->flags);
							}

							bw->Write(GSHOP->items[i]->gift_id);
							bw->Write(GSHOP->items[i]->gift_amount);
							bw->Write(GSHOP->items[i]->gift_duration);
							bw->Write(GSHOP->items[i]->log_price);

							shop_id++;
						}
					}

					bw->Close();
					fw->Close();;

					Cursor = Windows::Forms::Cursors::Default;
				}
				catch(Exception^ e)
				{
					Cursor = Windows::Forms::Cursors::Default;
					MessageBox::Show("EXPORT ERROR!\n\n" + e->Message);
				}
			}
		}

		//
		private: System::Void change_cat(System::Object^  sender, System::EventArgs^  e)
		{
			if(GSHOP && listBox_Cats->SelectedIndex>-1)
			{
				if(listBox_Cats->SelectedItem->ToString() != textBox_Cat->Text)
				{
					textBox_Cat->Text = bytes_to_string(GSHOP->categories[listBox_Cats->SelectedIndex]->name, "Unicode");
				}
				listBox_SubCats->Items->Clear();
				listBox_Items->Items->Clear();
				for(int i=0; i<GSHOP->categories[listBox_Cats->SelectedIndex]->sub_cats->Length; i++)
				{
					listBox_SubCats->Items->Add(bytes_to_string(GSHOP->categories[listBox_Cats->SelectedIndex]->sub_cats[i], "Unicode"));
				}
			}
		}
		private: System::Void change_subcat(System::Object^  sender, System::EventArgs^  e)
		{
			if(GSHOP && listBox_Cats->SelectedIndex>-1 && listBox_SubCats->SelectedIndex>-1)
			{
				if(listBox_SubCats->SelectedItem->ToString() != textBox_SubCat->Text)
				{
					textBox_SubCat->Text = bytes_to_string(GSHOP->categories[listBox_Cats->SelectedIndex]->sub_cats[listBox_SubCats->SelectedIndex], "Unicode");
				}
				listBox_Items->Items->Clear();
				for(int i=0; i<GSHOP->items->Length; i++)
				{
					if(GSHOP->items[i]->cat_index == listBox_Cats->SelectedIndex && GSHOP->items[i]->sub_cat_index == listBox_SubCats->SelectedIndex)
					{
						listBox_Items->Items->Add("[" + GSHOP->items[i]->shop_id + "] " + bytes_to_string(GSHOP->items[i]->name, "Unicode"));
					}
				}
			}
		}

		private: System::Void change_item(System::Object^  sender, System::EventArgs^  e)
		{
			if(GSHOP && listBox_Items->SelectedIndex>-1)
			{
				int id = Convert::ToInt32(listBox_Items->SelectedItem->ToString()->Substring(1, listBox_Items->SelectedItem->ToString()->IndexOf("]")-1));
				int current_item_index = (int)item_id_index_map[id];

				if(current_item_index>-1)
				{
					checkBox_active->Checked = GSHOP->items[current_item_index]->activate;
					numericUpDown_itemID->Value = GSHOP->items[current_item_index]->item_id;
					numericUpDown_amount->Value = GSHOP->items[current_item_index]->item_amount;
					textBox_name->Text =  bytes_to_string(GSHOP->items[current_item_index]->name, "Unicode");
					comboBox_surface->Text = bytes_to_string(GSHOP->items[current_item_index]->surface_path, "GBK");
					textBox_description->Text = bytes_to_string(GSHOP->items[current_item_index]->description, "Unicode");

					if(comboBox_sale_option->SelectedIndex > -1)
					{
						numericUpDown_price->Value = Convert::ToDecimal(GSHOP->items[current_item_index]->sale_options[comboBox_sale_option->SelectedIndex]->price)/100;
						textBox_end_date->Text = timestamp_to_string(GSHOP->items[current_item_index]->sale_options[comboBox_sale_option->SelectedIndex]->expire_date);
						textBox_duration->Text = seconds_to_string(GSHOP->items[current_item_index]->sale_options[comboBox_sale_option->SelectedIndex]->duration);
						textBox_start_date->Text = timestamp_to_string(GSHOP->items[current_item_index]->sale_options[comboBox_sale_option->SelectedIndex]->start_date);
						comboBox_type->SelectedIndex = GSHOP->items[current_item_index]->sale_options[comboBox_sale_option->SelectedIndex]->control_type+1;
						textBox_day->Text = GSHOP->items[current_item_index]->sale_options[comboBox_sale_option->SelectedIndex]->day.ToString();
						comboBox_status->SelectedIndex = GSHOP->items[current_item_index]->sale_options[comboBox_sale_option->SelectedIndex]->status;
						textBox_flags->Text = GSHOP->items[current_item_index]->sale_options[comboBox_sale_option->SelectedIndex]->flags.ToString();
					}

					numericUpDown_gift_id->Value = GSHOP->items[current_item_index]->gift_id;
					numericUpDown_gift_amount->Value = GSHOP->items[current_item_index]->gift_amount;
					textBox_gift_duration->Text = GSHOP->items[current_item_index]->gift_duration.ToString();
					numericUpDown_log_price->Value = Convert::ToDecimal(GSHOP->items[current_item_index]->log_price)/100;
				}
			}
		}
		void mouseDown_StartMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
		{
			if(e->Button == Windows::Forms::MouseButtons::Left)
			{
				this->Cursor = System::Windows::Forms::Cursors::SizeNS;
				*movingIndex = ((ListBox^)sender)->SelectedIndex;
			}
		}

		void mouseMove_MoveCat(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
		{
			 if(e->Button == Windows::Forms::MouseButtons::Left && ((ListBox^)sender)->Items->Count>1 && *movingIndex != ((ListBox^)sender)->SelectedIndex)
			 {
				 // Removing Event Handlers
				 this->listBox_Cats->SelectedIndexChanged -= gcnew System::EventHandler(this, &MainWindow::change_cat);

				 if(Math::Abs(*movingIndex-((ListBox^)sender)->SelectedIndex) == 1)
				 {
					 // Swap categories
					 Category^ movingCat = GSHOP->categories[*movingIndex];
					 GSHOP->categories[*movingIndex] = GSHOP->categories[((ListBox^)sender)->SelectedIndex];
					 GSHOP->categories[((ListBox^)sender)->SelectedIndex] = movingCat;

					 // Swap listbox items
					 Object^ movingListBoxItem = ((ListBox^)sender)->Items[*movingIndex];
					 ((ListBox^)sender)->Items[*movingIndex] = ((ListBox^)sender)->Items[((ListBox^)sender)->SelectedIndex];
					 ((ListBox^)sender)->Items[((ListBox^)sender)->SelectedIndex] = movingListBoxItem;

					 // Change all Items: Cat Index from movingIndex to ((ListBox^)sender)->SelectedIndex
					 for(int i=0; i<GSHOP->items->Length; i++)
					 {
						 if(GSHOP->items[i]->cat_index == *movingIndex)
						 {
							GSHOP->items[i]->cat_index = ((ListBox^)sender)->SelectedIndex;
						 }
						 else
						 {
							 if(GSHOP->items[i]->cat_index == ((ListBox^)sender)->SelectedIndex)
							 {
								GSHOP->items[i]->cat_index = int(*movingIndex);
							 }
						 }
					 }
					 
					 build_contextMenus();
					 
					 *movingIndex = ((ListBox^)sender)->SelectedIndex;					 
				 }
				 // Adding Event Handlers
				 this->listBox_Cats->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::change_cat);
			}
		}

		void mouseMove_MoveSubCat(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
		{
			 if(e->Button == Windows::Forms::MouseButtons::Left && ((ListBox^)sender)->Items->Count>1 && *movingIndex != ((ListBox^)sender)->SelectedIndex)
			 {
				 // Removing Event Handlers
				 this->listBox_SubCats->SelectedIndexChanged -= gcnew System::EventHandler(this, &MainWindow::change_subcat);

				 if(Math::Abs(*movingIndex-((ListBox^)sender)->SelectedIndex) == 1)
				 {
					 // Swap categories
					 array<unsigned char>^ movingSubCat = GSHOP->categories[listBox_Cats->SelectedIndex]->sub_cats[*movingIndex];
					 GSHOP->categories[listBox_Cats->SelectedIndex]->sub_cats[*movingIndex] = GSHOP->categories[listBox_Cats->SelectedIndex]->sub_cats[((ListBox^)sender)->SelectedIndex];
					 GSHOP->categories[listBox_Cats->SelectedIndex]->sub_cats[((ListBox^)sender)->SelectedIndex] = movingSubCat;

					 // Swap listbox items
					 Object^ movingListBoxItem = ((ListBox^)sender)->Items[*movingIndex];
					 ((ListBox^)sender)->Items[*movingIndex] = ((ListBox^)sender)->Items[((ListBox^)sender)->SelectedIndex];
					 ((ListBox^)sender)->Items[((ListBox^)sender)->SelectedIndex] = movingListBoxItem;

					 // Change all Items: SubCat Index from movingIndex to ((ListBox^)sender)->SelectedIndex
					 for(int i=0; i<GSHOP->items->Length; i++)
					 {
						 if(GSHOP->items[i]->cat_index == listBox_Cats->SelectedIndex)
						 {
							 if(GSHOP->items[i]->sub_cat_index == *movingIndex)
							 {
								GSHOP->items[i]->sub_cat_index = ((ListBox^)sender)->SelectedIndex;
							 }
							 else
							 {
								 if(GSHOP->items[i]->sub_cat_index == ((ListBox^)sender)->SelectedIndex)
								 {
									GSHOP->items[i]->sub_cat_index = int(*movingIndex);
								 }
							 }
						 }
					 }
					 
					 build_contextMenus();
					 
					 *movingIndex = ((ListBox^)sender)->SelectedIndex;					 
				 }
				 // Adding Event Handlers
				 this->listBox_SubCats->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::change_subcat);
			}
		}

		void mouseMove_MoveItem(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
		{
			 if(e->Button == Windows::Forms::MouseButtons::Left && ((ListBox^)sender)->Items->Count>1 && *movingIndex != ((ListBox^)sender)->SelectedIndex)
			 {
				 // Removing Event Handlers
				 this->listBox_Items->SelectedIndexChanged -= gcnew System::EventHandler(this, &MainWindow::change_item);

				 if(Math::Abs(*movingIndex-((ListBox^)sender)->SelectedIndex) == 1)
				 {
					 int source_id, target_id;
					 source_id = Convert::ToInt32(listBox_Items->Items[*movingIndex]->ToString()->Substring(1, listBox_Items->Items[*movingIndex]->ToString()->IndexOf("]")-1));
					 target_id = Convert::ToInt32(listBox_Items->Items[listBox_Items->SelectedIndex]->ToString()->Substring(1, listBox_Items->Items[listBox_Items->SelectedIndex]->ToString()->IndexOf("]")-1));

					 // Swap gshop items and update id_index_map
					 Item^ movingItem = GSHOP->items[(int)item_id_index_map[source_id]];
					 GSHOP->items[(int)item_id_index_map[source_id]] = GSHOP->items[(int)item_id_index_map[target_id]];
					 GSHOP->items[(int)item_id_index_map[target_id]] = movingItem;

					 // Swap id_index_map
					 int movingMap = (int)item_id_index_map[source_id];
					 item_id_index_map[source_id] = item_id_index_map[target_id];
					 item_id_index_map[target_id] =  movingMap;

					 // Swap listbox items
					 Object^ movingListBoxItem = ((ListBox^)sender)->Items[*movingIndex];
					 ((ListBox^)sender)->Items[*movingIndex] = ((ListBox^)sender)->Items[((ListBox^)sender)->SelectedIndex];
					 ((ListBox^)sender)->Items[((ListBox^)sender)->SelectedIndex] = movingListBoxItem;

					 *movingIndex = ((ListBox^)sender)->SelectedIndex;
				 }
				 // Adding Event Handlers
				 this->listBox_Items->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::change_item);
			 }
		}

		void mouseUp_StopMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
		{
			this->Cursor = System::Windows::Forms::Cursors::Default;
		}
		private: System::Void move_subcat(System::Object^  sender, System::EventArgs^  e)
		{
			if(GSHOP && listBox_Cats->SelectedIndex>-1 && listBox_SubCats->SelectedIndex>-1)
			{
				int source_cat = listBox_Cats->SelectedIndex;
				int source_subCat = listBox_SubCats->SelectedIndex;
				int target_cat = toolStripMenuItem_moveCat->DropDownItems->IndexOf((ToolStripMenuItem^)sender);

				if(GSHOP->categories[target_cat]->sub_cats->Length<8)
				{
					int target_sub_cat = GSHOP->categories[target_cat]->sub_cats_count;

					// create new subCat in target cat
					GSHOP->categories[target_cat]->sub_cats_count++;
					Array::Resize(GSHOP->categories[target_cat]->sub_cats, GSHOP->categories[target_cat]->sub_cats_count);
					GSHOP->categories[target_cat]->sub_cats[GSHOP->categories[target_cat]->sub_cats->Length-1] = GSHOP->categories[source_cat]->sub_cats[source_subCat];

					// move all items to new subCat
					for(int i=0; i<GSHOP->items->Length; i++)
					{
						if(GSHOP->items[i]->cat_index==source_cat && GSHOP->items[i]->sub_cat_index==source_subCat)
						{
							GSHOP->items[i]->cat_index = target_cat;
							GSHOP->items[i]->sub_cat_index = target_sub_cat;
						}
					}

					// delete source subCat
					click_deleteSubCat(nullptr, nullptr);

					build_contextMenus();
				}
				else
				{
					MessageBox::Show("Target already has 8 SubCategories!");
				}
			}
		}
		private: System::Void move_item(System::Object^  sender, System::EventArgs^  e)
		{
			if(GSHOP && listBox_Items->SelectedIndex>-1)
			{
				int id = Convert::ToInt32(listBox_Items->SelectedItem->ToString()->Substring(1, listBox_Items->SelectedItem->ToString()->IndexOf("]")-1));
				int current_item_index = (int)item_id_index_map[id];

				for(int i=0; i<toolStripMenuItem_moveItem->DropDownItems->Count; i++)
				{
					if(((ToolStripMenuItem^)toolStripMenuItem_moveItem->DropDownItems[i])->DropDownItems->Contains((ToolStripMenuItem^)sender))
					{
						GSHOP->items[current_item_index]->cat_index = i;
						GSHOP->items[current_item_index]->sub_cat_index = ((ToolStripMenuItem^)toolStripMenuItem_moveItem->DropDownItems[i])->DropDownItems->IndexOf((ToolStripMenuItem^)((ToolStripMenuItem^)sender));
						break;
					}
				}

				listBox_Items->Items->RemoveAt(listBox_Items->SelectedIndex);
			}

		}

		private: System::Void rename_cat(System::Object^  sender, System::EventArgs^  e)
		{
			if(listBox_Cats->SelectedIndex>-1)
			{
				GSHOP->categories[listBox_Cats->SelectedIndex]->name = string_to_bytes(textBox_Cat->Text, "Unicode", 128);
				listBox_Cats->Items[listBox_Cats->SelectedIndex] = textBox_Cat->Text;

				build_contextMenus();
			}
		}
		private: System::Void rename_subcat(System::Object^  sender, System::EventArgs^  e)
		{
			if(listBox_Cats->SelectedIndex>-1 && listBox_SubCats->SelectedIndex>-1)
			{
				GSHOP->categories[listBox_Cats->SelectedIndex]->sub_cats[listBox_SubCats->SelectedIndex] = string_to_bytes(textBox_SubCat->Text, "Unicode", 128);
				listBox_SubCats->Items[listBox_SubCats->SelectedIndex] = textBox_SubCat->Text;

				build_contextMenus();
			}
		}
		private: System::Void edit_item(System::Object^  sender, System::EventArgs^  e)
		{
			if(listBox_Items->SelectedIndex>-1)
			{
				int id = Convert::ToInt32(listBox_Items->SelectedItem->ToString()->Substring(1, listBox_Items->SelectedItem->ToString()->IndexOf("]")-1));
				int current_item_index = (int)item_id_index_map[id];
				int current_sale_index = comboBox_sale_option->SelectedIndex;

				if((Control^)sender == checkBox_active)
				{
					GSHOP->items[current_item_index]->activate = checkBox_active->Checked;
				}
				if((Control^)sender == numericUpDown_itemID)
				{
					GSHOP->items[current_item_index]->item_id = Convert::ToInt32(numericUpDown_itemID->Value);
				}
				if((Control^)sender == numericUpDown_amount)
				{
					GSHOP->items[current_item_index]->item_amount = Convert::ToInt32(numericUpDown_amount->Value);
				}
				if((Control^)sender == textBox_name)
				{
					GSHOP->items[current_item_index]->name = string_to_bytes(textBox_name->Text, "Unicode", 64);
					listBox_Items->Items[listBox_Items->SelectedIndex] = "[" + GSHOP->items[current_item_index]->shop_id + "] " + textBox_name->Text;
				}
				if((Control^)sender == textBox_description)
				{
					GSHOP->items[current_item_index]->description = string_to_bytes(textBox_description->Text, "Unicode", 1024);
				}
				if((Control^)sender == comboBox_surface)
				{
					GSHOP->items[current_item_index]->surface_path = string_to_bytes(comboBox_surface->Text, "GBK", 128);
				}
				if((Control^)sender == numericUpDown_price)
				{
					GSHOP->items[current_item_index]->sale_options[current_sale_index]->price = Convert::ToInt32(100*numericUpDown_price->Value);
				}
				if((Control^)sender == comboBox_type)
				{
					GSHOP->items[current_item_index]->sale_options[current_sale_index]->control_type = Convert::ToInt32(comboBox_type->SelectedIndex-1);
				}
				if((Control^)sender == textBox_start_date)
				{
					GSHOP->items[current_item_index]->sale_options[current_sale_index]->start_date = string_to_timestamp(textBox_start_date->Text);
				}
				if((Control^)sender == textBox_end_date)
				{
					GSHOP->items[current_item_index]->sale_options[current_sale_index]->expire_date = string_to_timestamp(textBox_end_date->Text);
				}
				if((Control^)sender == textBox_duration)
				{
					GSHOP->items[current_item_index]->sale_options[current_sale_index]->duration = string_to_seconds(textBox_duration->Text);
				}
				if((Control^)sender == textBox_day)
				{
					GSHOP->items[current_item_index]->sale_options[current_sale_index]->day = Convert::ToUInt32(textBox_day->Text);
				}
				if((Control^)sender == comboBox_status)
				{
					GSHOP->items[current_item_index]->sale_options[current_sale_index]->status = comboBox_status->SelectedIndex;
				}
				if((Control^)sender == textBox_flags)
				{
					GSHOP->items[current_item_index]->sale_options[current_sale_index]->flags = Convert::ToUInt32(textBox_flags->Text);
				}
				if((Control^)sender == numericUpDown_gift_id)
				{
					GSHOP->items[current_item_index]->gift_id = Convert::ToInt32(numericUpDown_gift_id->Value);
				}
				if((Control^)sender == numericUpDown_gift_amount)
				{
					GSHOP->items[current_item_index]->gift_amount = Convert::ToInt32(numericUpDown_gift_amount->Value);
				}
				if((Control^)sender == textBox_gift_duration)
				{
					GSHOP->items[current_item_index]->gift_duration = Convert::ToUInt32(textBox_gift_duration->Text);//string_to_seconds(textBox_gift_duration->Text);
				}
				if((Control^)sender == numericUpDown_log_price)
				{
					GSHOP->items[current_item_index]->log_price = Convert::ToInt32(100*numericUpDown_log_price->Value);
				}
			}
		}
		private: System::Void click_autoDetect(System::Object^  sender, System::EventArgs^  e)
		{
			Cursor = Cursors::AppStarting;

			if(comboBox_dbSource->SelectedIndex < 1)
			{
				String^ description = (String^)itemDescriptions[numericUpDown_itemID->Value.ToString()];
				if(description)
				{
					description = description->Replace("\\r", " \\r");
					textBox_description->Text = description;
				}

				edit_item(textBox_description, nullptr);
			}
			else
			{
				try
				{
					int index;
					int length;

					HttpWebRequest^ request  = (HttpWebRequest^)WebRequest::Create("http://www." + comboBox_dbSource->SelectedItem->ToString() + "/items/" + numericUpDown_itemID->Value.ToString());
					request->Proxy = nullptr;
					HttpWebResponse^ response = (HttpWebResponse^)request->GetResponse();
					StreamReader^ wr = gcnew StreamReader(response->GetResponseStream());
					String^ content = wr->ReadToEnd();
					wr->Close();

					// Find Item Name
					index = content->IndexOf("<th class=\"itemHeader\"") + 35;
					if(index>34)
					{
						length = content->IndexOf("<a href", index) - index;
						String^ name = content->Substring(index, length);
						// Remove span + color
						if(name->Contains("<"))
						{
							name = name->Substring(name->IndexOf(">")+1);
							name = name->Substring(0, name->IndexOf("</"));
						}
						name = name->Replace("&#9734;", L"★");
						textBox_name->Text = name;
						edit_item(textBox_name, nullptr);
					}

					// Find if Item Contains Shop Info
					index = content->IndexOf("<a href=\"shopitem/", index) + 18;

					if(index>18)
					{
						length = content->IndexOf("\">", index) - index;
						String^ shop_id = content->Substring(index, length);

						// Load Shop Description
						request  = (HttpWebRequest^)WebRequest::Create("http://www." + comboBox_dbSource->SelectedItem->ToString() + "/shopitem/" + shop_id);
						request->Proxy = nullptr;
						response = (HttpWebResponse^)request->GetResponse();
						wr = gcnew StreamReader(response->GetResponseStream());
						content = wr->ReadToEnd();
						wr->Close();

						index = content->IndexOf("<h3>Description</h3><p>") + 23;
						if(index>22)
						{
							length = content->IndexOf("</p>", index) - index;
							String^ description = content->Substring(index, length);

							description = description->Replace("<span style='color:", "");
							description = description->Replace("#", "^");
							description = description->Replace(";", "");
							description = description->Replace("'>", "");
							description = description->Replace("<br />", "\\r");
							description = description->Replace("<br/>", "\\r");
							description = description->Replace("<br>", "\\r");
							description = description->Replace("</span>", "");
							description = description->Replace("\\r", " \\r");

							textBox_description->Text = description;
						}
					}

					edit_item(textBox_description, nullptr);
				}
				catch(...)
				{
					MessageBox::Show("Connection Failed!");
				}
			}

			Cursor = Cursors::Default;
		}
		private: System::Void click_addSubCat(System::Object^  sender, System::EventArgs^  e)
		{
			if(GSHOP && listBox_Cats->SelectedIndex>-1)
			{
				if(GSHOP->categories[listBox_Cats->SelectedIndex]->sub_cats->Length<8)
				{
					GSHOP->categories[listBox_Cats->SelectedIndex]->sub_cats_count++;
					Array::Resize(GSHOP->categories[listBox_Cats->SelectedIndex]->sub_cats, GSHOP->categories[listBox_Cats->SelectedIndex]->sub_cats_count);
					GSHOP->categories[listBox_Cats->SelectedIndex]->sub_cats[GSHOP->categories[listBox_Cats->SelectedIndex]->sub_cats->Length-1] = string_to_bytes("New", "Unicode", 128);
					listBox_SubCats->Items->Add("New");
					listBox_SubCats->SelectedIndex = listBox_SubCats->Items->Count-1;

					build_contextMenus();
				}
				else
				{
					MessageBox::Show("Maximum of 8 reached!");
				}
			}
		}
		private: System::Void click_deleteSubCat(System::Object^  sender, System::EventArgs^  e)
		{
			if(GSHOP && listBox_Cats->SelectedIndex>-1 && listBox_SubCats->SelectedIndex>-1)
			{
				GSHOP->categories[listBox_Cats->SelectedIndex]->sub_cats_count--;

				array<array<unsigned char>^>^ temp = gcnew array<array<unsigned char>^>(GSHOP->categories[listBox_Cats->SelectedIndex]->sub_cats_count);
				Array::Copy(GSHOP->categories[listBox_Cats->SelectedIndex]->sub_cats, 0, temp, 0, listBox_SubCats->SelectedIndex);
				Array::Copy(GSHOP->categories[listBox_Cats->SelectedIndex]->sub_cats, listBox_SubCats->SelectedIndex+1, temp, listBox_SubCats->SelectedIndex, GSHOP->categories[listBox_Cats->SelectedIndex]->sub_cats_count - listBox_SubCats->SelectedIndex);
				GSHOP->categories[listBox_Cats->SelectedIndex]->sub_cats = temp;

				// remove items / update subcats of all items
				for(int i=0; i<GSHOP->items->Length; i++)
				{
					if(GSHOP->items[i]->cat_index == listBox_Cats->SelectedIndex)
					{
						if(GSHOP->items[i]->sub_cat_index == listBox_SubCats->SelectedIndex)
						{
// mark this item as not to be saved
							GSHOP->item_count--;
							GSHOP->items[i]->cat_index = -1;
							GSHOP->items[i]->sub_cat_index = -1;
							item_id_index_map->Remove(GSHOP->items[i]->shop_id);
						}

						if(GSHOP->items[i]->sub_cat_index > listBox_SubCats->SelectedIndex)
						{
							GSHOP->items[i]->sub_cat_index--;
						}
					}
				}

				listBox_SubCats->Items->RemoveAt(listBox_SubCats->SelectedIndex);
				listBox_Items->Items->Clear();
			}
		}
		private: System::Void click_addItem(System::Object^  sender, System::EventArgs^  e)
		{
			if(GSHOP && listBox_Cats->SelectedIndex>-1 && listBox_SubCats->SelectedIndex>-1)
			{
				GSHOP->item_count++;
				Array::Resize(GSHOP->items, GSHOP->items->Length+1);
				GSHOP->items[GSHOP->items->Length-1] = gcnew Item();
				GSHOP->items[GSHOP->items->Length-1]->activate = true;
				GSHOP->items[GSHOP->items->Length-1]->shop_id = max_item_id+1;
				GSHOP->items[GSHOP->items->Length-1]->cat_index = listBox_Cats->SelectedIndex;
				GSHOP->items[GSHOP->items->Length-1]->sub_cat_index = listBox_SubCats->SelectedIndex;
				GSHOP->items[GSHOP->items->Length-1]->surface_path = string_to_bytes("", "GBK", 128);
				GSHOP->items[GSHOP->items->Length-1]->item_id = 1;
				GSHOP->items[GSHOP->items->Length-1]->item_amount = 1;
				
				GSHOP->items[GSHOP->items->Length-1]->sale_options = gcnew array<SaleOption^>(4);
				for(int n=0; n<GSHOP->items[GSHOP->items->Length-1]->sale_options->Length; n++)
				{
					GSHOP->items[GSHOP->items->Length-1]->sale_options[n] = gcnew SaleOption();
					GSHOP->items[GSHOP->items->Length-1]->sale_options[n]->price = 0;
					GSHOP->items[GSHOP->items->Length-1]->sale_options[n]->expire_date = 0;
					GSHOP->items[GSHOP->items->Length-1]->sale_options[n]->duration = 0;
					GSHOP->items[GSHOP->items->Length-1]->sale_options[n]->start_date = 0;
					GSHOP->items[GSHOP->items->Length-1]->sale_options[n]->control_type = -1;
					GSHOP->items[GSHOP->items->Length-1]->sale_options[n]->day = 0;
					GSHOP->items[GSHOP->items->Length-1]->sale_options[n]->status = 0;
					GSHOP->items[GSHOP->items->Length-1]->sale_options[n]->flags = 0;
				}

				GSHOP->items[GSHOP->items->Length-1]->description = string_to_bytes("", "Unicode", 1024);
				GSHOP->items[GSHOP->items->Length-1]->name = string_to_bytes("New", "Unicode", 64);
				GSHOP->items[GSHOP->items->Length-1]->gift_id = 0;
				GSHOP->items[GSHOP->items->Length-1]->gift_amount = 0;
				GSHOP->items[GSHOP->items->Length-1]->gift_duration = 0;
				GSHOP->items[GSHOP->items->Length-1]->log_price = 0;

				item_id_index_map->Add(GSHOP->items[GSHOP->items->Length-1]->shop_id, GSHOP->items->Length-1);

				listBox_Items->Items->Add("[" + GSHOP->items[GSHOP->items->Length-1]->shop_id + "] New");
				listBox_Items->SelectedIndex = listBox_Items->Items->Count-1;

				max_item_id++;
			}
		}
		private: System::Void click_deleteItem(System::Object^  sender, System::EventArgs^  e)
		{
			if(GSHOP && listBox_Items->SelectedIndex>-1)
			{
				int id = Convert::ToInt32(listBox_Items->SelectedItem->ToString()->Substring(1, listBox_Items->SelectedItem->ToString()->IndexOf("]")-1));
				int current_item_index = (int)item_id_index_map[id];

// mark this item as not to be saved
				GSHOP->item_count--;
				GSHOP->items[current_item_index]->cat_index = -1;
				GSHOP->items[current_item_index]->sub_cat_index = -1;

				item_id_index_map->Remove(GSHOP->items[current_item_index]->shop_id);
				listBox_Items->Items->RemoveAt(listBox_Items->SelectedIndex);
			}
		}
		private: System::Void load_surface(System::Object^  sender, System::EventArgs^  e)
		{
			String^ surface = Application::StartupPath + "\\" + comboBox_surface->Text->Replace(".dds", ".jpg");
			String^ path = surface->Substring(0, surface->LastIndexOf("\\"));
			String^ file = surface->Substring(surface->LastIndexOf("\\")+1);
			if(path->IndexOfAny(Path::GetInvalidPathChars())<0 && file->IndexOfAny(Path::GetInvalidFileNameChars())<0 && File::Exists(surface))
			{
				pictureBox_surface->Image = Bitmap::FromFile(surface);
			}
			else
			{
				pictureBox_surface->Image = gcnew Bitmap(128, 128);
			}
			GC::Collect();
		 }
		private: System::Void keyPress_search(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
		{
			if(e->KeyChar == (wchar_t)Keys::Enter)
			{
				click_search(nullptr, nullptr);
			}
		}
		private: System::Void click_search(System::Object^  sender, System::EventArgs^  e)
		{
			if(GSHOP)
			{
				// Get the index of current selected item
				int current_item_index = 0;
				if(listBox_Items->SelectedIndex>-1)
				{
					int id = Convert::ToInt32(listBox_Items->SelectedItem->ToString()->Substring(1, listBox_Items->SelectedItem->ToString()->IndexOf("]")-1));
					current_item_index = (int)item_id_index_map[id]+1;
				}

				for(int i=current_item_index; i<GSHOP->items->Length; i++)
				{
					if(GSHOP->items[i]->cat_index>-1 && GSHOP->items[i]->sub_cat_index>-1)
					{
						if(textBox_search->Text == GSHOP->items[i]->item_id.ToString() || bytes_to_string(GSHOP->items[i]->name, "Unicode")->Contains(textBox_search->Text))
						{
							listBox_Cats->SelectedIndex = GSHOP->items[i]->cat_index;
							listBox_SubCats->SelectedIndex = GSHOP->items[i]->sub_cat_index;
							listBox_Items->SelectedIndex = listBox_Items->Items->IndexOf("[" + GSHOP->items[i]->shop_id.ToString() + "] " + bytes_to_string(GSHOP->items[i]->name, "Unicode"));
							return;
						}
					}
				}

				MessageBox::Show("Search reached end of List without result");
			}
		}
		private: System::Void click_get_timestamp(System::Object^  sender, System::EventArgs^  e)
		{
			int current_timestamp = Convert::ToUInt32(DateTime::UtcNow.Subtract( DateTime(1970, 1, 1, 0, 0, 0, 0) ).TotalSeconds);
			if(GSHOP)
			{
				GSHOP->timestamp = current_timestamp;
			}
			textBox_timestamp->Text = timestamp_to_string(current_timestamp);
		}
		private: System::Void click_set_prices(System::Object^  sender, System::EventArgs^  e)
		{
			if(GSHOP)
			{
				Cursor = Windows::Forms::Cursors::WaitCursor;

				for(int i=0; i<GSHOP->items->Length; i++)
				{
					/*
					for(int n=0; n<GSHOP->items[i]->sale_options->Length; n++)
					{
						GSHOP->items[i]->sale_options[n]->price = 1000;
					}
					*/
					GSHOP->items[i]->sale_options[0]->price = 1;
				}

				change_item(nullptr, nullptr);

				Cursor = Windows::Forms::Cursors::Default;
			}
		}
		private: System::Void click_set_control_type_client(System::Object^  sender, System::EventArgs^  e)
		{
			if(GSHOP)
			{
				Cursor = Windows::Forms::Cursors::WaitCursor;

				for(int i=0; i<GSHOP->items->Length; i++)
				{
					for(int n=0; n<GSHOP->items[i]->sale_options->Length; n++)
					{
						GSHOP->items[i]->sale_options[n]->control_type = -1;
					}
				}

				change_item(nullptr, nullptr);

				Cursor = Windows::Forms::Cursors::Default;
			}
		}
		private: System::Void click_set_control_type_server(System::Object^  sender, System::EventArgs^  e)
		{
			if(GSHOP)
			{
				Cursor = Windows::Forms::Cursors::WaitCursor;

				for(int i=0; i<GSHOP->items->Length; i++)
				{
					for(int n=0; n<GSHOP->items[i]->sale_options->Length; n++)
					{
						GSHOP->items[i]->sale_options[n]->control_type = 0;
					}
				}

				change_item(nullptr, nullptr);

				Cursor = Windows::Forms::Cursors::Default;
			}
		}
private: System::Void listBox_Items_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
		{
			IDataObject^ data = Clipboard::GetDataObject( );
			
			if (data)
			{
				if (data->GetDataPresent(DataFormats::Text)) 
				{
					String^ text = static_cast<String^>
					(data->GetData(DataFormats::Text));
					{
						array<Char>^chars = {'	'};
						array<String^>^x = text->Split( chars );

						bool is_number = true;
						try
						{
							int::Parse(x[0]);
						} catch (...) {
							is_number = false;
						}

						if (is_number && (x->Length == 2))
						{

							if(GSHOP && listBox_Cats->SelectedIndex>-1 && listBox_SubCats->SelectedIndex>-1)
							{
								GSHOP->item_count++;
								Array::Resize(GSHOP->items, GSHOP->items->Length+1);
								GSHOP->items[GSHOP->items->Length-1] = gcnew Item();
								GSHOP->items[GSHOP->items->Length-1]->activate = true;
								GSHOP->items[GSHOP->items->Length-1]->shop_id = max_item_id+1;
								GSHOP->items[GSHOP->items->Length-1]->cat_index = listBox_Cats->SelectedIndex;
								GSHOP->items[GSHOP->items->Length-1]->sub_cat_index = listBox_SubCats->SelectedIndex;
								GSHOP->items[GSHOP->items->Length-1]->surface_path = string_to_bytes("", "GBK", 128);
								GSHOP->items[GSHOP->items->Length-1]->item_id = int::Parse(x[0]);
								GSHOP->items[GSHOP->items->Length-1]->item_amount = 1;
							
								GSHOP->items[GSHOP->items->Length-1]->sale_options = gcnew array<SaleOption^>(4);
								for(int n=0; n<GSHOP->items[GSHOP->items->Length-1]->sale_options->Length; n++)
								{
									GSHOP->items[GSHOP->items->Length-1]->sale_options[n] = gcnew SaleOption();
									GSHOP->items[GSHOP->items->Length-1]->sale_options[n]->price = 0;
									GSHOP->items[GSHOP->items->Length-1]->sale_options[n]->expire_date = 0;
									GSHOP->items[GSHOP->items->Length-1]->sale_options[n]->duration = 0;
									GSHOP->items[GSHOP->items->Length-1]->sale_options[n]->start_date = 0;
									GSHOP->items[GSHOP->items->Length-1]->sale_options[n]->control_type = -1;
									GSHOP->items[GSHOP->items->Length-1]->sale_options[n]->day = 0;
									GSHOP->items[GSHOP->items->Length-1]->sale_options[n]->status = 0;
									GSHOP->items[GSHOP->items->Length-1]->sale_options[n]->flags = 0;
							}
			
								GSHOP->items[GSHOP->items->Length-1]->description = string_to_bytes("", "Unicode", 1024);
								GSHOP->items[GSHOP->items->Length-1]->name = string_to_bytes(x[1], "Unicode", 64);
								GSHOP->items[GSHOP->items->Length-1]->gift_id = 0;
								GSHOP->items[GSHOP->items->Length-1]->gift_amount = 0;
								GSHOP->items[GSHOP->items->Length-1]->gift_duration = 0;
								GSHOP->items[GSHOP->items->Length-1]->log_price = 0;
				
								item_id_index_map->Add(GSHOP->items[GSHOP->items->Length-1]->shop_id, GSHOP->items->Length-1);
				
								listBox_Items->Items->Add("[" + GSHOP->items[GSHOP->items->Length-1]->shop_id + "] " + x[1]);
								listBox_Items->SelectedIndex = listBox_Items->Items->Count-1;
			
								max_item_id++;
							}
						}
						else
						{
							MessageBox::Show("Clipboard data has an incorrect format.");
						}
					}
				}
				else
				{
					MessageBox::Show("Nontext data is in the Clipboard.");
				}
			}
			else 
			{
				MessageBox::Show("No data was found in the Clipboard.");
			}
		}
};