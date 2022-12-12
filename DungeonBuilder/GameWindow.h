#pragma once
#include <string>
#include "Tile.h"
#include "Floor.h"
#include "SaveGame.h"
#include "LoadGame.h"
#include "TileSelectionController.h"
#include "GameController.h"
#include "FloorSelection.h"
#include "BiomeSelection.h"

namespace DungeonBuilder {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GameWindow
	/// </summary>
	public ref class GameWindow : public System::Windows::Forms::Form
	{
	public:
		GameWindow(void)
		{
			InitializeComponent();
			tileSelectionController = new TileSelectionController(tileSelectionPictureBox, tileDescriptionTextBox);
			gameController = new GameController(turnNumberLabel, manaAmountLabel);
			floorSelection = new FloorSelection();
			biomeSelection = new BiomeSelection();
			saveGame = new SaveGame();
			loadGame = new LoadGame();
			image = gcnew Drawing::Bitmap("WorldMap.bmp");
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GameWindow()
		{
			if (components)
			{
				delete components;
			}
		}

   // constants for indexes of different screens
	private:
		const int TITLE_SCREEN = 0;
		const int SETTINGS_SCREEN = 1;
		const int SAVE_GAME_SCREEN = 2;
		const int LOAD_GAME_SCREEN = 3;
		const int BIOME_SELECTION_SCREEN = 4;
		const int FLOOR_SELECTION_SCREEN = 5;
		const int FLOOR_SCREEN = 6;
		int prevScreen = 0;

	private: Drawing::Bitmap^ image;
	private: GameController* gameController;
	private: TileSelectionController* tileSelectionController;
	private: Floor* floor;
	private: SaveGame* saveGame;
	private: LoadGame* loadGame;
	private: FloorSelection* floorSelection;
	private: BiomeSelection* biomeSelection;
	private: System::String^ floorEditorBiome;


	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ SettingsScreen;
	private: System::Windows::Forms::TabPage^ SaveGameScreen;
	private: System::Windows::Forms::TabPage^ LoadGameScreen;
	private: System::Windows::Forms::TabPage^ BiomeSelectionScreen;
	private: System::Windows::Forms::TabPage^ TitleScreen;

	private: System::Windows::Forms::Button^ loadGameButton;

	private: System::Windows::Forms::Button^ newGameButton;

	private: System::Windows::Forms::TabPage^ FloorSelectionScreen;
	private: System::Windows::Forms::TabPage^ FloorScreen;
	private: System::Windows::Forms::Panel^ biomeSelectionPanel;
	private: System::Windows::Forms::Panel^ tileSelectionPanel;
	private: System::Windows::Forms::Button^ floorSelectionButton;
	private: System::Windows::Forms::Panel^ tileDescriptionPanel;
	private: System::Windows::Forms::Label^ tileDescriptionLabel;
	private: System::Windows::Forms::Panel^ floorGridPanel;
	private: System::Windows::Forms::Button^ designButton;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Label^ turnNumberLabel;
	private: System::Windows::Forms::Label^ manaAmountLabel;
	private: System::Windows::Forms::ListBox^ designTileList;
	private: System::Windows::Forms::Button^ trapsButton;
	private: System::Windows::Forms::Button^ monstersButton;
	private: System::Windows::Forms::ListBox^ monstersTileList;
	private: System::Windows::Forms::ListBox^ trapsTileList;
	private: System::Windows::Forms::Label^ floorEditorLabel;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ tileSelectionLabel;
	private: System::Windows::Forms::PictureBox^ tileSelectionPictureBox;
	private: System::Windows::Forms::RichTextBox^ tileDescriptionTextBox;
	private: System::Windows::Forms::CheckBox^ eraseModeCheckBox;

	private: System::Windows::Forms::TableLayoutPanel^ loadGameLayout;
	private: System::Windows::Forms::Label^ loadSlot1Label;
	private: System::Windows::Forms::Button^ loadButton;
	private: System::Windows::Forms::Label^ loadSlot2Label;
	private: System::Windows::Forms::Label^ loadSlot3Label;
private: System::Windows::Forms::CheckBox^ loadGame1;
private: System::Windows::Forms::CheckBox^ loadGame3;
private: System::Windows::Forms::CheckBox^ loadGame2;
private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
private: System::Windows::Forms::CheckBox^ saveGame3;
private: System::Windows::Forms::CheckBox^ saveGame2;
private: System::Windows::Forms::CheckBox^ saveGame1;
private: System::Windows::Forms::Label^ saveSlot3Label;
private: System::Windows::Forms::Label^ saveSlot1Label;
private: System::Windows::Forms::Button^ saveButton;
private: System::Windows::Forms::Label^ saveSlot2Label;

	private: System::Windows::Forms::Label^ floorTurnNumberLabel;


private: System::Windows::Forms::CheckBox^ floor1;
private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
private: System::Windows::Forms::Label^ playerMana;
private: System::Windows::Forms::PictureBox^ pictureBox3;
private: System::Windows::Forms::CheckBox^ floor3;
private: System::Windows::Forms::CheckBox^ floor2;
private: System::Windows::Forms::TextBox^ floorInfoTitle;
private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel2;
private: System::Windows::Forms::Label^ floorTypeLabel;
private: System::Windows::Forms::Label^ floorType;
private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel3;
private: System::Windows::Forms::Label^ floorManaSpentLabel;
private: System::Windows::Forms::PictureBox^ pictureBox4;

private: System::Windows::Forms::Button^ enterFloorButton;
private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel4;
private: System::Windows::Forms::Label^ floorManaGenerationLabel;
private: System::Windows::Forms::Label^ floorManaGenAmount;
private: System::Windows::Forms::PictureBox^ pictureBox5;
private: System::Windows::Forms::Label^ floorManaGenTurnLabel;
private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel5;
private: System::Windows::Forms::Label^ label6;
private: System::Windows::Forms::Label^ BossName;

private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel6;
private: System::Windows::Forms::Label^ floorMonstersLabel; private: System::Windows::Forms::Label^ label9;
private: System::Windows::Forms::Label^ floorNumOfMonsters;
private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel7;
private: System::Windows::Forms::Label^ floorTrapsLabel;

private: System::Windows::Forms::Label^ floorNumOfTraps;

private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel8;
private: System::Windows::Forms::Label^ label12;
private: System::Windows::Forms::Label^ label13;
private: System::Windows::Forms::Button^ settingsButtonFloorScreen;
private: System::Windows::Forms::Button^ endTurnButton;
private: System::Windows::Forms::Panel^ panel1;
private: System::Windows::Forms::TextBox^ biomeDescBox;

private: System::Windows::Forms::TextBox^ biomeNameBox;

private: System::Windows::Forms::TextBox^ textBox2;
private: System::Windows::Forms::TextBox^ textBox1;
private: System::Windows::Forms::Button^ biomeConfirmButton;
private: System::Windows::Forms::PictureBox^ FloorSelectionBG;
private: System::Windows::Forms::PictureBox^ FloorScreenBG;
private: System::Windows::Forms::Button^ settingsLoadButton;
private: System::Windows::Forms::Button^ settingsSaveButton;
private: System::Windows::Forms::Button^ settingsBackButton;
private: System::Windows::Forms::Button^ saveScreenBack;
private: System::Windows::Forms::Button^ loadScreenBack;
private: System::Windows::Forms::PictureBox^ pictureBox6;


private: System::Windows::Forms::PictureBox^ pictureBox8;
private: System::Windows::Forms::PictureBox^ pictureBox7;
private: System::Windows::Forms::PictureBox^ pictureBox10;
private: System::Windows::Forms::Label^ floorManaSpent;





	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GameWindow::typeid));
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->TitleScreen = (gcnew System::Windows::Forms::TabPage());
			this->loadGameButton = (gcnew System::Windows::Forms::Button());
			this->newGameButton = (gcnew System::Windows::Forms::Button());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->SettingsScreen = (gcnew System::Windows::Forms::TabPage());
			this->settingsBackButton = (gcnew System::Windows::Forms::Button());
			this->settingsLoadButton = (gcnew System::Windows::Forms::Button());
			this->settingsSaveButton = (gcnew System::Windows::Forms::Button());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->SaveGameScreen = (gcnew System::Windows::Forms::TabPage());
			this->saveScreenBack = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->saveGame3 = (gcnew System::Windows::Forms::CheckBox());
			this->saveGame2 = (gcnew System::Windows::Forms::CheckBox());
			this->saveGame1 = (gcnew System::Windows::Forms::CheckBox());
			this->saveSlot3Label = (gcnew System::Windows::Forms::Label());
			this->saveSlot1Label = (gcnew System::Windows::Forms::Label());
			this->saveButton = (gcnew System::Windows::Forms::Button());
			this->saveSlot2Label = (gcnew System::Windows::Forms::Label());
			this->pictureBox10 = (gcnew System::Windows::Forms::PictureBox());
			this->LoadGameScreen = (gcnew System::Windows::Forms::TabPage());
			this->loadScreenBack = (gcnew System::Windows::Forms::Button());
			this->loadGameLayout = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->loadGame3 = (gcnew System::Windows::Forms::CheckBox());
			this->loadGame2 = (gcnew System::Windows::Forms::CheckBox());
			this->loadGame1 = (gcnew System::Windows::Forms::CheckBox());
			this->loadSlot3Label = (gcnew System::Windows::Forms::Label());
			this->loadSlot1Label = (gcnew System::Windows::Forms::Label());
			this->loadButton = (gcnew System::Windows::Forms::Button());
			this->loadSlot2Label = (gcnew System::Windows::Forms::Label());
			this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
			this->BiomeSelectionScreen = (gcnew System::Windows::Forms::TabPage());
			this->biomeSelectionPanel = (gcnew System::Windows::Forms::Panel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->biomeDescBox = (gcnew System::Windows::Forms::TextBox());
			this->biomeNameBox = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->biomeConfirmButton = (gcnew System::Windows::Forms::Button());
			this->FloorSelectionScreen = (gcnew System::Windows::Forms::TabPage());
			this->enterFloorButton = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->floorInfoTitle = (gcnew System::Windows::Forms::TextBox());
			this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->floorTypeLabel = (gcnew System::Windows::Forms::Label());
			this->floorType = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel3 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->floorManaSpentLabel = (gcnew System::Windows::Forms::Label());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->floorManaSpent = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel4 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->floorManaGenerationLabel = (gcnew System::Windows::Forms::Label());
			this->floorManaGenAmount = (gcnew System::Windows::Forms::Label());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->floorManaGenTurnLabel = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel5 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->BossName = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel6 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->floorMonstersLabel = (gcnew System::Windows::Forms::Label());
			this->floorNumOfMonsters = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel7 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->floorTrapsLabel = (gcnew System::Windows::Forms::Label());
			this->floorNumOfTraps = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel8 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->playerMana = (gcnew System::Windows::Forms::Label());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->floor3 = (gcnew System::Windows::Forms::CheckBox());
			this->floor2 = (gcnew System::Windows::Forms::CheckBox());
			this->floor1 = (gcnew System::Windows::Forms::CheckBox());
			this->floorTurnNumberLabel = (gcnew System::Windows::Forms::Label());
			this->FloorSelectionBG = (gcnew System::Windows::Forms::PictureBox());
			this->FloorScreen = (gcnew System::Windows::Forms::TabPage());
			this->settingsButtonFloorScreen = (gcnew System::Windows::Forms::Button());
			this->endTurnButton = (gcnew System::Windows::Forms::Button());
			this->eraseModeCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->tileSelectionPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->tileSelectionLabel = (gcnew System::Windows::Forms::Label());
			this->floorEditorLabel = (gcnew System::Windows::Forms::Label());
			this->turnNumberLabel = (gcnew System::Windows::Forms::Label());
			this->tileSelectionPanel = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->monstersTileList = (gcnew System::Windows::Forms::ListBox());
			this->trapsTileList = (gcnew System::Windows::Forms::ListBox());
			this->designTileList = (gcnew System::Windows::Forms::ListBox());
			this->trapsButton = (gcnew System::Windows::Forms::Button());
			this->monstersButton = (gcnew System::Windows::Forms::Button());
			this->designButton = (gcnew System::Windows::Forms::Button());
			this->manaAmountLabel = (gcnew System::Windows::Forms::Label());
			this->floorSelectionButton = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->tileDescriptionPanel = (gcnew System::Windows::Forms::Panel());
			this->tileDescriptionTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->tileDescriptionLabel = (gcnew System::Windows::Forms::Label());
			this->floorGridPanel = (gcnew System::Windows::Forms::Panel());
			this->FloorScreenBG = (gcnew System::Windows::Forms::PictureBox());
			this->tabControl1->SuspendLayout();
			this->TitleScreen->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			this->SettingsScreen->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			this->SaveGameScreen->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->BeginInit();
			this->LoadGameScreen->SuspendLayout();
			this->loadGameLayout->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->BeginInit();
			this->BiomeSelectionScreen->SuspendLayout();
			this->biomeSelectionPanel->SuspendLayout();
			this->panel1->SuspendLayout();
			this->FloorSelectionScreen->SuspendLayout();
			this->flowLayoutPanel1->SuspendLayout();
			this->flowLayoutPanel2->SuspendLayout();
			this->flowLayoutPanel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->flowLayoutPanel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			this->flowLayoutPanel5->SuspendLayout();
			this->flowLayoutPanel6->SuspendLayout();
			this->flowLayoutPanel7->SuspendLayout();
			this->flowLayoutPanel8->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->FloorSelectionBG))->BeginInit();
			this->FloorScreen->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tileSelectionPictureBox))->BeginInit();
			this->tileSelectionPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->tileDescriptionPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->FloorScreenBG))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->TitleScreen);
			this->tabControl1->Controls->Add(this->SettingsScreen);
			this->tabControl1->Controls->Add(this->SaveGameScreen);
			this->tabControl1->Controls->Add(this->LoadGameScreen);
			this->tabControl1->Controls->Add(this->BiomeSelectionScreen);
			this->tabControl1->Controls->Add(this->FloorSelectionScreen);
			this->tabControl1->Controls->Add(this->FloorScreen);
			this->tabControl1->Location = System::Drawing::Point(-5, -22);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1098, 720);
			this->tabControl1->TabIndex = 0;
			this->tabControl1->SelectedIndexChanged += gcnew System::EventHandler(this, &GameWindow::tabControl1_SelectedIndexChanged);
			// 
			// TitleScreen
			// 
			this->TitleScreen->BackColor = System::Drawing::Color::Gray;
			this->TitleScreen->Controls->Add(this->loadGameButton);
			this->TitleScreen->Controls->Add(this->newGameButton);
			this->TitleScreen->Controls->Add(this->pictureBox6);
			this->TitleScreen->Location = System::Drawing::Point(4, 22);
			this->TitleScreen->Name = L"TitleScreen";
			this->TitleScreen->Padding = System::Windows::Forms::Padding(3);
			this->TitleScreen->Size = System::Drawing::Size(1090, 694);
			this->TitleScreen->TabIndex = 0;
			this->TitleScreen->Text = L"TitleScreen";
			// 
			// loadGameButton
			// 
			this->loadGameButton->Font = (gcnew System::Drawing::Font(L"Algerian", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->loadGameButton->Location = System::Drawing::Point(331, 336);
			this->loadGameButton->Name = L"loadGameButton";
			this->loadGameButton->Size = System::Drawing::Size(367, 102);
			this->loadGameButton->TabIndex = 4;
			this->loadGameButton->Text = L"Load Game";
			this->loadGameButton->UseVisualStyleBackColor = true;
			this->loadGameButton->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &GameWindow::loadGameButton_MouseClick);
			// 
			// newGameButton
			// 
			this->newGameButton->Font = (gcnew System::Drawing::Font(L"Algerian", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->newGameButton->Location = System::Drawing::Point(331, 228);
			this->newGameButton->Name = L"newGameButton";
			this->newGameButton->Size = System::Drawing::Size(367, 102);
			this->newGameButton->TabIndex = 0;
			this->newGameButton->Text = L"New Game";
			this->newGameButton->UseVisualStyleBackColor = true;
			this->newGameButton->Click += gcnew System::EventHandler(this, &GameWindow::newGameButton_Click);
			// 
			// pictureBox6
			// 
			this->pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.Image")));
			this->pictureBox6->Location = System::Drawing::Point(-4, 0);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(1018, 671);
			this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox6->TabIndex = 5;
			this->pictureBox6->TabStop = false;
			// 
			// SettingsScreen
			// 
			this->SettingsScreen->BackColor = System::Drawing::Color::Gray;
			this->SettingsScreen->Controls->Add(this->settingsBackButton);
			this->SettingsScreen->Controls->Add(this->settingsLoadButton);
			this->SettingsScreen->Controls->Add(this->settingsSaveButton);
			this->SettingsScreen->Controls->Add(this->pictureBox7);
			this->SettingsScreen->Location = System::Drawing::Point(4, 22);
			this->SettingsScreen->Name = L"SettingsScreen";
			this->SettingsScreen->Padding = System::Windows::Forms::Padding(3);
			this->SettingsScreen->Size = System::Drawing::Size(1090, 694);
			this->SettingsScreen->TabIndex = 1;
			this->SettingsScreen->Text = L"SettingsScreen";
			// 
			// settingsBackButton
			// 
			this->settingsBackButton->FlatAppearance->BorderSize = 4;
			this->settingsBackButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->settingsBackButton->Font = (gcnew System::Drawing::Font(L"Algerian", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->settingsBackButton->Location = System::Drawing::Point(881, 609);
			this->settingsBackButton->Margin = System::Windows::Forms::Padding(2);
			this->settingsBackButton->Name = L"settingsBackButton";
			this->settingsBackButton->Size = System::Drawing::Size(117, 39);
			this->settingsBackButton->TabIndex = 3;
			this->settingsBackButton->Text = L"Back";
			this->settingsBackButton->UseVisualStyleBackColor = true;
			this->settingsBackButton->Click += gcnew System::EventHandler(this, &GameWindow::settingsBackButton_Click);
			// 
			// settingsLoadButton
			// 
			this->settingsLoadButton->FlatAppearance->BorderSize = 4;
			this->settingsLoadButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->settingsLoadButton->Font = (gcnew System::Drawing::Font(L"Algerian", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->settingsLoadButton->Location = System::Drawing::Point(370, 333);
			this->settingsLoadButton->Margin = System::Windows::Forms::Padding(2);
			this->settingsLoadButton->Name = L"settingsLoadButton";
			this->settingsLoadButton->Size = System::Drawing::Size(276, 93);
			this->settingsLoadButton->TabIndex = 2;
			this->settingsLoadButton->Text = L"Load Game";
			this->settingsLoadButton->UseVisualStyleBackColor = true;
			this->settingsLoadButton->Click += gcnew System::EventHandler(this, &GameWindow::settingsLoadButton_Click);
			// 
			// settingsSaveButton
			// 
			this->settingsSaveButton->FlatAppearance->BorderSize = 4;
			this->settingsSaveButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->settingsSaveButton->Font = (gcnew System::Drawing::Font(L"Algerian", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->settingsSaveButton->Location = System::Drawing::Point(370, 236);
			this->settingsSaveButton->Margin = System::Windows::Forms::Padding(2);
			this->settingsSaveButton->Name = L"settingsSaveButton";
			this->settingsSaveButton->Size = System::Drawing::Size(276, 93);
			this->settingsSaveButton->TabIndex = 1;
			this->settingsSaveButton->Text = L"Save Game";
			this->settingsSaveButton->UseVisualStyleBackColor = true;
			this->settingsSaveButton->Click += gcnew System::EventHandler(this, &GameWindow::settingsSaveButton_Click);
			// 
			// pictureBox7
			// 
			this->pictureBox7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.Image")));
			this->pictureBox7->Location = System::Drawing::Point(-4, 0);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(1019, 670);
			this->pictureBox7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox7->TabIndex = 14;
			this->pictureBox7->TabStop = false;
			// 
			// SaveGameScreen
			// 
			this->SaveGameScreen->BackColor = System::Drawing::Color::Gray;
			this->SaveGameScreen->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->SaveGameScreen->Controls->Add(this->saveScreenBack);
			this->SaveGameScreen->Controls->Add(this->tableLayoutPanel1);
			this->SaveGameScreen->Controls->Add(this->pictureBox10);
			this->SaveGameScreen->Location = System::Drawing::Point(4, 22);
			this->SaveGameScreen->Name = L"SaveGameScreen";
			this->SaveGameScreen->Padding = System::Windows::Forms::Padding(3);
			this->SaveGameScreen->Size = System::Drawing::Size(1090, 694);
			this->SaveGameScreen->TabIndex = 2;
			this->SaveGameScreen->Text = L"SaveGameScreen";
			// 
			// saveScreenBack
			// 
			this->saveScreenBack->BackColor = System::Drawing::Color::SteelBlue;
			this->saveScreenBack->FlatAppearance->BorderSize = 4;
			this->saveScreenBack->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->saveScreenBack->Font = (gcnew System::Drawing::Font(L"Algerian", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->saveScreenBack->Location = System::Drawing::Point(881, 609);
			this->saveScreenBack->Margin = System::Windows::Forms::Padding(2);
			this->saveScreenBack->Name = L"saveScreenBack";
			this->saveScreenBack->Size = System::Drawing::Size(117, 39);
			this->saveScreenBack->TabIndex = 10;
			this->saveScreenBack->Text = L"Back";
			this->saveScreenBack->UseVisualStyleBackColor = false;
			this->saveScreenBack->Click += gcnew System::EventHandler(this, &GameWindow::saveScreenBack_Click);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tableLayoutPanel1->BackColor = System::Drawing::Color::SteelBlue;
			this->tableLayoutPanel1->ColumnCount = 3;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->Controls->Add(this->saveGame3, 2, 1);
			this->tableLayoutPanel1->Controls->Add(this->saveGame2, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->saveGame1, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->saveSlot3Label, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->saveSlot1Label, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->saveButton, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->saveSlot2Label, 1, 0);
			this->tableLayoutPanel1->GrowStyle = System::Windows::Forms::TableLayoutPanelGrowStyle::FixedSize;
			this->tableLayoutPanel1->Location = System::Drawing::Point(193, 214);
			this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(2);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10.57471F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 89.42529F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 55)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(610, 400);
			this->tableLayoutPanel1->TabIndex = 9;
			// 
			// saveGame3
			// 
			this->saveGame3->Appearance = System::Windows::Forms::Appearance::Button;
			this->saveGame3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->saveGame3->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->saveGame3->FlatAppearance->BorderSize = 5;
			this->saveGame3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->saveGame3->Font = (gcnew System::Drawing::Font(L"Algerian", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->saveGame3->Location = System::Drawing::Point(416, 44);
			this->saveGame3->Margin = System::Windows::Forms::Padding(8);
			this->saveGame3->Name = L"saveGame3";
			this->saveGame3->Size = System::Drawing::Size(188, 292);
			this->saveGame3->TabIndex = 14;
			this->saveGame3->Text = L"EMPTY";
			this->saveGame3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->saveGame3->Click += gcnew System::EventHandler(this, &GameWindow::saveGame3_Click);
			// 
			// saveGame2
			// 
			this->saveGame2->Appearance = System::Windows::Forms::Appearance::Button;
			this->saveGame2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->saveGame2->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->saveGame2->FlatAppearance->BorderSize = 5;
			this->saveGame2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->saveGame2->Font = (gcnew System::Drawing::Font(L"Algerian", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->saveGame2->Location = System::Drawing::Point(212, 44);
			this->saveGame2->Margin = System::Windows::Forms::Padding(8);
			this->saveGame2->Name = L"saveGame2";
			this->saveGame2->Size = System::Drawing::Size(188, 292);
			this->saveGame2->TabIndex = 13;
			this->saveGame2->Text = L"EMPTY";
			this->saveGame2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->saveGame2->Click += gcnew System::EventHandler(this, &GameWindow::saveGame2_Click);
			// 
			// saveGame1
			// 
			this->saveGame1->Appearance = System::Windows::Forms::Appearance::Button;
			this->saveGame1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->saveGame1->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->saveGame1->FlatAppearance->BorderSize = 5;
			this->saveGame1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->saveGame1->Font = (gcnew System::Drawing::Font(L"Algerian", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->saveGame1->Location = System::Drawing::Point(8, 44);
			this->saveGame1->Margin = System::Windows::Forms::Padding(8);
			this->saveGame1->Name = L"saveGame1";
			this->saveGame1->Size = System::Drawing::Size(188, 292);
			this->saveGame1->TabIndex = 5;
			this->saveGame1->Text = L"EMPTY";
			this->saveGame1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->saveGame1->Click += gcnew System::EventHandler(this, &GameWindow::saveGame1_Click);
			// 
			// saveSlot3Label
			// 
			this->saveSlot3Label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->saveSlot3Label->AutoSize = true;
			this->saveSlot3Label->Font = (gcnew System::Drawing::Font(L"Algerian", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->saveSlot3Label->Location = System::Drawing::Point(411, 0);
			this->saveSlot3Label->Name = L"saveSlot3Label";
			this->saveSlot3Label->Size = System::Drawing::Size(198, 36);
			this->saveSlot3Label->TabIndex = 12;
			this->saveSlot3Label->Text = L"SLOT 3";
			this->saveSlot3Label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// saveSlot1Label
			// 
			this->saveSlot1Label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->saveSlot1Label->AutoSize = true;
			this->saveSlot1Label->BackColor = System::Drawing::Color::SteelBlue;
			this->saveSlot1Label->Font = (gcnew System::Drawing::Font(L"Algerian", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->saveSlot1Label->Location = System::Drawing::Point(3, 0);
			this->saveSlot1Label->Name = L"saveSlot1Label";
			this->saveSlot1Label->Size = System::Drawing::Size(198, 36);
			this->saveSlot1Label->TabIndex = 7;
			this->saveSlot1Label->Text = L"SLOT 1";
			this->saveSlot1Label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// saveButton
			// 
			this->saveButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->saveButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->saveButton->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->saveButton->FlatAppearance->BorderSize = 2;
			this->saveButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->saveButton->Font = (gcnew System::Drawing::Font(L"Algerian", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->saveButton->Location = System::Drawing::Point(265, 352);
			this->saveButton->Margin = System::Windows::Forms::Padding(8);
			this->saveButton->Name = L"saveButton";
			this->saveButton->Size = System::Drawing::Size(82, 40);
			this->saveButton->TabIndex = 8;
			this->saveButton->Text = L"SAVE";
			this->saveButton->Click += gcnew System::EventHandler(this, &GameWindow::saveButton_Click);
			// 
			// saveSlot2Label
			// 
			this->saveSlot2Label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->saveSlot2Label->AutoSize = true;
			this->saveSlot2Label->Font = (gcnew System::Drawing::Font(L"Algerian", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->saveSlot2Label->Location = System::Drawing::Point(207, 0);
			this->saveSlot2Label->Name = L"saveSlot2Label";
			this->saveSlot2Label->Size = System::Drawing::Size(198, 36);
			this->saveSlot2Label->TabIndex = 11;
			this->saveSlot2Label->Text = L"SLOT 2";
			this->saveSlot2Label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pictureBox10
			// 
			this->pictureBox10->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox10.Image")));
			this->pictureBox10->Location = System::Drawing::Point(-4, 0);
			this->pictureBox10->Name = L"pictureBox10";
			this->pictureBox10->Size = System::Drawing::Size(1019, 670);
			this->pictureBox10->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox10->TabIndex = 13;
			this->pictureBox10->TabStop = false;
			// 
			// LoadGameScreen
			// 
			this->LoadGameScreen->BackColor = System::Drawing::Color::Gray;
			this->LoadGameScreen->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->LoadGameScreen->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->LoadGameScreen->Controls->Add(this->loadScreenBack);
			this->LoadGameScreen->Controls->Add(this->loadGameLayout);
			this->LoadGameScreen->Controls->Add(this->pictureBox8);
			this->LoadGameScreen->Location = System::Drawing::Point(4, 22);
			this->LoadGameScreen->Name = L"LoadGameScreen";
			this->LoadGameScreen->Padding = System::Windows::Forms::Padding(3);
			this->LoadGameScreen->Size = System::Drawing::Size(1090, 694);
			this->LoadGameScreen->TabIndex = 3;
			this->LoadGameScreen->Text = L"LoadGameScreen";
			// 
			// loadScreenBack
			// 
			this->loadScreenBack->BackColor = System::Drawing::Color::SteelBlue;
			this->loadScreenBack->FlatAppearance->BorderSize = 4;
			this->loadScreenBack->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->loadScreenBack->Font = (gcnew System::Drawing::Font(L"Algerian", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->loadScreenBack->Location = System::Drawing::Point(880, 608);
			this->loadScreenBack->Margin = System::Windows::Forms::Padding(2);
			this->loadScreenBack->Name = L"loadScreenBack";
			this->loadScreenBack->Size = System::Drawing::Size(117, 39);
			this->loadScreenBack->TabIndex = 11;
			this->loadScreenBack->Text = L"Back";
			this->loadScreenBack->UseVisualStyleBackColor = false;
			this->loadScreenBack->Click += gcnew System::EventHandler(this, &GameWindow::loadScreenBack_Click);
			// 
			// loadGameLayout
			// 
			this->loadGameLayout->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->loadGameLayout->BackColor = System::Drawing::Color::SteelBlue;
			this->loadGameLayout->ColumnCount = 3;
			this->loadGameLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->loadGameLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->loadGameLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->loadGameLayout->Controls->Add(this->loadGame3, 2, 1);
			this->loadGameLayout->Controls->Add(this->loadGame2, 1, 1);
			this->loadGameLayout->Controls->Add(this->loadGame1, 0, 1);
			this->loadGameLayout->Controls->Add(this->loadSlot3Label, 2, 0);
			this->loadGameLayout->Controls->Add(this->loadSlot1Label, 0, 0);
			this->loadGameLayout->Controls->Add(this->loadButton, 1, 2);
			this->loadGameLayout->Controls->Add(this->loadSlot2Label, 1, 0);
			this->loadGameLayout->GrowStyle = System::Windows::Forms::TableLayoutPanelGrowStyle::FixedSize;
			this->loadGameLayout->Location = System::Drawing::Point(192, 212);
			this->loadGameLayout->Margin = System::Windows::Forms::Padding(2);
			this->loadGameLayout->Name = L"loadGameLayout";
			this->loadGameLayout->RowCount = 3;
			this->loadGameLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10.57471F)));
			this->loadGameLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 89.42529F)));
			this->loadGameLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 55)));
			this->loadGameLayout->Size = System::Drawing::Size(610, 400);
			this->loadGameLayout->TabIndex = 7;
			// 
			// loadGame3
			// 
			this->loadGame3->Appearance = System::Windows::Forms::Appearance::Button;
			this->loadGame3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->loadGame3->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->loadGame3->FlatAppearance->BorderSize = 5;
			this->loadGame3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->loadGame3->Font = (gcnew System::Drawing::Font(L"Algerian", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->loadGame3->Location = System::Drawing::Point(416, 44);
			this->loadGame3->Margin = System::Windows::Forms::Padding(8);
			this->loadGame3->Name = L"loadGame3";
			this->loadGame3->Size = System::Drawing::Size(188, 292);
			this->loadGame3->TabIndex = 14;
			this->loadGame3->Text = L"EMPTY";
			this->loadGame3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->loadGame3->Click += gcnew System::EventHandler(this, &GameWindow::loadGame3_Click);
			// 
			// loadGame2
			// 
			this->loadGame2->Appearance = System::Windows::Forms::Appearance::Button;
			this->loadGame2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->loadGame2->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->loadGame2->FlatAppearance->BorderSize = 5;
			this->loadGame2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->loadGame2->Font = (gcnew System::Drawing::Font(L"Algerian", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->loadGame2->Location = System::Drawing::Point(212, 44);
			this->loadGame2->Margin = System::Windows::Forms::Padding(8);
			this->loadGame2->Name = L"loadGame2";
			this->loadGame2->Size = System::Drawing::Size(188, 292);
			this->loadGame2->TabIndex = 13;
			this->loadGame2->Text = L"EMPTY";
			this->loadGame2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->loadGame2->Click += gcnew System::EventHandler(this, &GameWindow::loadGame2_Click);
			// 
			// loadGame1
			// 
			this->loadGame1->Appearance = System::Windows::Forms::Appearance::Button;
			this->loadGame1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->loadGame1->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->loadGame1->FlatAppearance->BorderSize = 5;
			this->loadGame1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->loadGame1->Font = (gcnew System::Drawing::Font(L"Algerian", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->loadGame1->Location = System::Drawing::Point(8, 44);
			this->loadGame1->Margin = System::Windows::Forms::Padding(8);
			this->loadGame1->Name = L"loadGame1";
			this->loadGame1->Size = System::Drawing::Size(188, 292);
			this->loadGame1->TabIndex = 5;
			this->loadGame1->Text = L"EMPTY";
			this->loadGame1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->loadGame1->Click += gcnew System::EventHandler(this, &GameWindow::loadGame1_Click);
			// 
			// loadSlot3Label
			// 
			this->loadSlot3Label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->loadSlot3Label->AutoSize = true;
			this->loadSlot3Label->Font = (gcnew System::Drawing::Font(L"Algerian", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->loadSlot3Label->Location = System::Drawing::Point(411, 0);
			this->loadSlot3Label->Name = L"loadSlot3Label";
			this->loadSlot3Label->Size = System::Drawing::Size(198, 36);
			this->loadSlot3Label->TabIndex = 12;
			this->loadSlot3Label->Text = L"SLOT 3";
			this->loadSlot3Label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// loadSlot1Label
			// 
			this->loadSlot1Label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->loadSlot1Label->AutoSize = true;
			this->loadSlot1Label->Font = (gcnew System::Drawing::Font(L"Algerian", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->loadSlot1Label->Location = System::Drawing::Point(3, 0);
			this->loadSlot1Label->Name = L"loadSlot1Label";
			this->loadSlot1Label->Size = System::Drawing::Size(198, 36);
			this->loadSlot1Label->TabIndex = 7;
			this->loadSlot1Label->Text = L"SLOT 1";
			this->loadSlot1Label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// loadButton
			// 
			this->loadButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->loadButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->loadButton->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->loadButton->FlatAppearance->BorderSize = 2;
			this->loadButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->loadButton->Font = (gcnew System::Drawing::Font(L"Algerian", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->loadButton->Location = System::Drawing::Point(265, 352);
			this->loadButton->Margin = System::Windows::Forms::Padding(8);
			this->loadButton->Name = L"loadButton";
			this->loadButton->Size = System::Drawing::Size(82, 40);
			this->loadButton->TabIndex = 8;
			this->loadButton->Text = L"LOAD";
			this->loadButton->Click += gcnew System::EventHandler(this, &GameWindow::loadButton_Click);
			// 
			// loadSlot2Label
			// 
			this->loadSlot2Label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->loadSlot2Label->AutoSize = true;
			this->loadSlot2Label->Font = (gcnew System::Drawing::Font(L"Algerian", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->loadSlot2Label->Location = System::Drawing::Point(207, 0);
			this->loadSlot2Label->Name = L"loadSlot2Label";
			this->loadSlot2Label->Size = System::Drawing::Size(198, 36);
			this->loadSlot2Label->TabIndex = 11;
			this->loadSlot2Label->Text = L"SLOT 2";
			this->loadSlot2Label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pictureBox8
			// 
			this->pictureBox8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox8.Image")));
			this->pictureBox8->Location = System::Drawing::Point(-5, -1);
			this->pictureBox8->Name = L"pictureBox8";
			this->pictureBox8->Size = System::Drawing::Size(1019, 670);
			this->pictureBox8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox8->TabIndex = 12;
			this->pictureBox8->TabStop = false;
			// 
			// BiomeSelectionScreen
			// 
			this->BiomeSelectionScreen->Controls->Add(this->biomeSelectionPanel);
			this->BiomeSelectionScreen->Location = System::Drawing::Point(4, 22);
			this->BiomeSelectionScreen->Name = L"BiomeSelectionScreen";
			this->BiomeSelectionScreen->Padding = System::Windows::Forms::Padding(3);
			this->BiomeSelectionScreen->Size = System::Drawing::Size(1090, 694);
			this->BiomeSelectionScreen->TabIndex = 4;
			this->BiomeSelectionScreen->Text = L"BiomeSelectionScreen";
			this->BiomeSelectionScreen->UseVisualStyleBackColor = true;
			// 
			// biomeSelectionPanel
			// 
			this->biomeSelectionPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->biomeSelectionPanel->Controls->Add(this->panel1);
			this->biomeSelectionPanel->Location = System::Drawing::Point(0, 1);
			this->biomeSelectionPanel->Name = L"biomeSelectionPanel";
			this->biomeSelectionPanel->Size = System::Drawing::Size(1009, 664);
			this->biomeSelectionPanel->TabIndex = 0;
			this->biomeSelectionPanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GameWindow::biomeSelectionPanel_Paint);
			this->biomeSelectionPanel->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &GameWindow::biomeSelectionPanel_MouseDown);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Black;
			this->panel1->Controls->Add(this->biomeDescBox);
			this->panel1->Controls->Add(this->biomeNameBox);
			this->panel1->Controls->Add(this->textBox2);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->biomeConfirmButton);
			this->panel1->Location = System::Drawing::Point(14, 6);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(200, 260);
			this->panel1->TabIndex = 1;
			// 
			// biomeDescBox
			// 
			this->biomeDescBox->BackColor = System::Drawing::Color::DarkGray;
			this->biomeDescBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->biomeDescBox->Font = (gcnew System::Drawing::Font(L"Algerian", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->biomeDescBox->Location = System::Drawing::Point(3, 65);
			this->biomeDescBox->Multiline = true;
			this->biomeDescBox->Name = L"biomeDescBox";
			this->biomeDescBox->Size = System::Drawing::Size(194, 144);
			this->biomeDescBox->TabIndex = 4;
			this->biomeDescBox->Text = L"\r\nClick any color on the map to select a biome. Biomes currently available: Fores"
				L"t, Desert, Mountains";
			this->biomeDescBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// biomeNameBox
			// 
			this->biomeNameBox->BackColor = System::Drawing::Color::DarkGray;
			this->biomeNameBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->biomeNameBox->Font = (gcnew System::Drawing::Font(L"Algerian", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->biomeNameBox->Location = System::Drawing::Point(65, 37);
			this->biomeNameBox->Name = L"biomeNameBox";
			this->biomeNameBox->Size = System::Drawing::Size(132, 22);
			this->biomeNameBox->TabIndex = 3;
			this->biomeNameBox->Text = L"N/A";
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::DarkGray;
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Algerian", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(3, 37);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(66, 22);
			this->textBox2->TabIndex = 2;
			this->textBox2->Text = L"Biome: ";
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::DarkGray;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Algerian", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(3, 3);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(194, 28);
			this->textBox1->TabIndex = 1;
			this->textBox1->Text = L"Biome Info";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// biomeConfirmButton
			// 
			this->biomeConfirmButton->BackColor = System::Drawing::Color::Silver;
			this->biomeConfirmButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->biomeConfirmButton->Font = (gcnew System::Drawing::Font(L"Algerian", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->biomeConfirmButton->Location = System::Drawing::Point(3, 215);
			this->biomeConfirmButton->Name = L"biomeConfirmButton";
			this->biomeConfirmButton->Size = System::Drawing::Size(194, 42);
			this->biomeConfirmButton->TabIndex = 0;
			this->biomeConfirmButton->Text = L"Confirm Biome";
			this->biomeConfirmButton->UseVisualStyleBackColor = false;
			this->biomeConfirmButton->Click += gcnew System::EventHandler(this, &GameWindow::biomeConfirmButton_Click);
			// 
			// FloorSelectionScreen
			// 
			this->FloorSelectionScreen->BackColor = System::Drawing::Color::Gray;
			this->FloorSelectionScreen->Controls->Add(this->enterFloorButton);
			this->FloorSelectionScreen->Controls->Add(this->flowLayoutPanel1);
			this->FloorSelectionScreen->Controls->Add(this->playerMana);
			this->FloorSelectionScreen->Controls->Add(this->pictureBox3);
			this->FloorSelectionScreen->Controls->Add(this->floor3);
			this->FloorSelectionScreen->Controls->Add(this->floor2);
			this->FloorSelectionScreen->Controls->Add(this->floor1);
			this->FloorSelectionScreen->Controls->Add(this->floorTurnNumberLabel);
			this->FloorSelectionScreen->Controls->Add(this->FloorSelectionBG);
			this->FloorSelectionScreen->Location = System::Drawing::Point(4, 22);
			this->FloorSelectionScreen->Name = L"FloorSelectionScreen";
			this->FloorSelectionScreen->Size = System::Drawing::Size(1090, 694);
			this->FloorSelectionScreen->TabIndex = 5;
			this->FloorSelectionScreen->Text = L"FloorSelectionScreen";
			// 
			// enterFloorButton
			// 
			this->enterFloorButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->enterFloorButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->enterFloorButton->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->enterFloorButton->FlatAppearance->BorderSize = 4;
			this->enterFloorButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->enterFloorButton->Font = (gcnew System::Drawing::Font(L"Algerian", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->enterFloorButton->Location = System::Drawing::Point(383, 560);
			this->enterFloorButton->Margin = System::Windows::Forms::Padding(8);
			this->enterFloorButton->Name = L"enterFloorButton";
			this->enterFloorButton->Size = System::Drawing::Size(158, 41);
			this->enterFloorButton->TabIndex = 15;
			this->enterFloorButton->Text = L"ENTER FLOOR";
			this->enterFloorButton->Click += gcnew System::EventHandler(this, &GameWindow::enterFloorButton_Click);
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->flowLayoutPanel1->AutoSize = true;
			this->flowLayoutPanel1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->flowLayoutPanel1->BackColor = System::Drawing::Color::Black;
			this->flowLayoutPanel1->Controls->Add(this->floorInfoTitle);
			this->flowLayoutPanel1->Controls->Add(this->flowLayoutPanel2);
			this->flowLayoutPanel1->Controls->Add(this->flowLayoutPanel3);
			this->flowLayoutPanel1->Controls->Add(this->flowLayoutPanel4);
			this->flowLayoutPanel1->Controls->Add(this->flowLayoutPanel5);
			this->flowLayoutPanel1->Controls->Add(this->flowLayoutPanel6);
			this->flowLayoutPanel1->Controls->Add(this->flowLayoutPanel7);
			this->flowLayoutPanel1->Controls->Add(this->flowLayoutPanel8);
			this->flowLayoutPanel1->Location = System::Drawing::Point(740, 95);
			this->flowLayoutPanel1->Margin = System::Windows::Forms::Padding(2);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Padding = System::Windows::Forms::Padding(4);
			this->flowLayoutPanel1->Size = System::Drawing::Size(241, 462);
			this->flowLayoutPanel1->TabIndex = 14;
			// 
			// floorInfoTitle
			// 
			this->floorInfoTitle->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->floorInfoTitle->BackColor = System::Drawing::Color::Gray;
			this->floorInfoTitle->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->floorInfoTitle->Font = (gcnew System::Drawing::Font(L"Algerian", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->floorInfoTitle->Location = System::Drawing::Point(6, 6);
			this->floorInfoTitle->Margin = System::Windows::Forms::Padding(2);
			this->floorInfoTitle->Name = L"floorInfoTitle";
			this->floorInfoTitle->Size = System::Drawing::Size(229, 29);
			this->floorInfoTitle->TabIndex = 0;
			this->floorInfoTitle->Text = L"FLOOR - INFO";
			this->floorInfoTitle->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// flowLayoutPanel2
			// 
			this->flowLayoutPanel2->BackColor = System::Drawing::Color::Gray;
			this->flowLayoutPanel2->Controls->Add(this->floorTypeLabel);
			this->flowLayoutPanel2->Controls->Add(this->floorType);
			this->flowLayoutPanel2->Location = System::Drawing::Point(6, 39);
			this->flowLayoutPanel2->Margin = System::Windows::Forms::Padding(2);
			this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
			this->flowLayoutPanel2->Size = System::Drawing::Size(229, 53);
			this->flowLayoutPanel2->TabIndex = 1;
			// 
			// floorTypeLabel
			// 
			this->floorTypeLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->floorTypeLabel->Font = (gcnew System::Drawing::Font(L"Algerian", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->floorTypeLabel->Location = System::Drawing::Point(0, 0);
			this->floorTypeLabel->Margin = System::Windows::Forms::Padding(0);
			this->floorTypeLabel->Name = L"floorTypeLabel";
			this->floorTypeLabel->Size = System::Drawing::Size(226, 24);
			this->floorTypeLabel->TabIndex = 9;
			this->floorTypeLabel->Text = L"TYPE";
			this->floorTypeLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// floorType
			// 
			this->floorType->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->floorType->Font = (gcnew System::Drawing::Font(L"Algerian", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->floorType->Location = System::Drawing::Point(0, 24);
			this->floorType->Margin = System::Windows::Forms::Padding(0);
			this->floorType->Name = L"floorType";
			this->floorType->Size = System::Drawing::Size(226, 29);
			this->floorType->TabIndex = 10;
			this->floorType->Text = L"SAND DUNES";
			this->floorType->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// flowLayoutPanel3
			// 
			this->flowLayoutPanel3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->flowLayoutPanel3->BackColor = System::Drawing::Color::Gray;
			this->flowLayoutPanel3->Controls->Add(this->floorManaSpentLabel);
			this->flowLayoutPanel3->Controls->Add(this->pictureBox4);
			this->flowLayoutPanel3->Controls->Add(this->floorManaSpent);
			this->flowLayoutPanel3->Location = System::Drawing::Point(6, 96);
			this->flowLayoutPanel3->Margin = System::Windows::Forms::Padding(2);
			this->flowLayoutPanel3->Name = L"flowLayoutPanel3";
			this->flowLayoutPanel3->Size = System::Drawing::Size(229, 64);
			this->flowLayoutPanel3->TabIndex = 11;
			// 
			// floorManaSpentLabel
			// 
			this->floorManaSpentLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->floorManaSpentLabel->Font = (gcnew System::Drawing::Font(L"Algerian", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->floorManaSpentLabel->Location = System::Drawing::Point(0, 0);
			this->floorManaSpentLabel->Margin = System::Windows::Forms::Padding(0);
			this->floorManaSpentLabel->Name = L"floorManaSpentLabel";
			this->floorManaSpentLabel->Size = System::Drawing::Size(226, 24);
			this->floorManaSpentLabel->TabIndex = 9;
			this->floorManaSpentLabel->Text = L"MANA CAP";
			this->floorManaSpentLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(52, 27);
			this->pictureBox4->Margin = System::Windows::Forms::Padding(52, 3, 3, 3);
			this->pictureBox4->MaximumSize = System::Drawing::Size(200, 200);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(29, 32);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox4->TabIndex = 14;
			this->pictureBox4->TabStop = false;
			// 
			// floorManaSpent
			// 
			this->floorManaSpent->AutoSize = true;
			this->floorManaSpent->Font = (gcnew System::Drawing::Font(L"Algerian", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->floorManaSpent->Location = System::Drawing::Point(87, 24);
			this->floorManaSpent->Name = L"floorManaSpent";
			this->floorManaSpent->Size = System::Drawing::Size(70, 26);
			this->floorManaSpent->TabIndex = 15;
			this->floorManaSpent->Text = L"NONE";
			this->floorManaSpent->Click += gcnew System::EventHandler(this, &GameWindow::floorManaSpent_Click);
			// 
			// flowLayoutPanel4
			// 
			this->flowLayoutPanel4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->flowLayoutPanel4->BackColor = System::Drawing::Color::Gray;
			this->flowLayoutPanel4->Controls->Add(this->floorManaGenerationLabel);
			this->flowLayoutPanel4->Controls->Add(this->floorManaGenAmount);
			this->flowLayoutPanel4->Controls->Add(this->pictureBox5);
			this->flowLayoutPanel4->Controls->Add(this->floorManaGenTurnLabel);
			this->flowLayoutPanel4->Location = System::Drawing::Point(6, 164);
			this->flowLayoutPanel4->Margin = System::Windows::Forms::Padding(2);
			this->flowLayoutPanel4->Name = L"flowLayoutPanel4";
			this->flowLayoutPanel4->Size = System::Drawing::Size(229, 64);
			this->flowLayoutPanel4->TabIndex = 16;
			// 
			// floorManaGenerationLabel
			// 
			this->floorManaGenerationLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->floorManaGenerationLabel->Font = (gcnew System::Drawing::Font(L"Algerian", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->floorManaGenerationLabel->Location = System::Drawing::Point(0, 0);
			this->floorManaGenerationLabel->Margin = System::Windows::Forms::Padding(0);
			this->floorManaGenerationLabel->Name = L"floorManaGenerationLabel";
			this->floorManaGenerationLabel->Size = System::Drawing::Size(226, 24);
			this->floorManaGenerationLabel->TabIndex = 9;
			this->floorManaGenerationLabel->Text = L"MANA GENERATION";
			this->floorManaGenerationLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// floorManaGenAmount
			// 
			this->floorManaGenAmount->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->floorManaGenAmount->Font = (gcnew System::Drawing::Font(L"Algerian", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->floorManaGenAmount->Location = System::Drawing::Point(41, 28);
			this->floorManaGenAmount->Margin = System::Windows::Forms::Padding(41, 0, 0, 0);
			this->floorManaGenAmount->Name = L"floorManaGenAmount";
			this->floorManaGenAmount->Size = System::Drawing::Size(30, 29);
			this->floorManaGenAmount->TabIndex = 11;
			this->floorManaGenAmount->Text = L"-";
			this->floorManaGenAmount->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pictureBox5
			// 
			this->pictureBox5->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(74, 27);
			this->pictureBox5->MaximumSize = System::Drawing::Size(200, 200);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(29, 32);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox5->TabIndex = 14;
			this->pictureBox5->TabStop = false;
			// 
			// floorManaGenTurnLabel
			// 
			this->floorManaGenTurnLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->floorManaGenTurnLabel->Font = (gcnew System::Drawing::Font(L"Algerian", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->floorManaGenTurnLabel->Location = System::Drawing::Point(106, 28);
			this->floorManaGenTurnLabel->Margin = System::Windows::Forms::Padding(0);
			this->floorManaGenTurnLabel->Name = L"floorManaGenTurnLabel";
			this->floorManaGenTurnLabel->Size = System::Drawing::Size(119, 29);
			this->floorManaGenTurnLabel->TabIndex = 15;
			this->floorManaGenTurnLabel->Text = L"PER TURN";
			this->floorManaGenTurnLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// flowLayoutPanel5
			// 
			this->flowLayoutPanel5->BackColor = System::Drawing::Color::Gray;
			this->flowLayoutPanel5->Controls->Add(this->label6);
			this->flowLayoutPanel5->Controls->Add(this->BossName);
			this->flowLayoutPanel5->Location = System::Drawing::Point(6, 232);
			this->flowLayoutPanel5->Margin = System::Windows::Forms::Padding(2);
			this->flowLayoutPanel5->Name = L"flowLayoutPanel5";
			this->flowLayoutPanel5->Size = System::Drawing::Size(229, 53);
			this->flowLayoutPanel5->TabIndex = 17;
			// 
			// label6
			// 
			this->label6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->label6->Font = (gcnew System::Drawing::Font(L"Algerian", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(0, 0);
			this->label6->Margin = System::Windows::Forms::Padding(0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(226, 24);
			this->label6->TabIndex = 9;
			this->label6->Text = L"BOSS";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// BossName
			// 
			this->BossName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->BossName->Font = (gcnew System::Drawing::Font(L"Algerian", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BossName->Location = System::Drawing::Point(0, 24);
			this->BossName->Margin = System::Windows::Forms::Padding(0);
			this->BossName->Name = L"BossName";
			this->BossName->Size = System::Drawing::Size(226, 29);
			this->BossName->TabIndex = 10;
			this->BossName->Text = L"LENNY THE SAND WORM";
			this->BossName->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// flowLayoutPanel6
			// 
			this->flowLayoutPanel6->BackColor = System::Drawing::Color::Gray;
			this->flowLayoutPanel6->Controls->Add(this->floorMonstersLabel);
			this->flowLayoutPanel6->Controls->Add(this->floorNumOfMonsters);
			this->flowLayoutPanel6->Location = System::Drawing::Point(6, 289);
			this->flowLayoutPanel6->Margin = System::Windows::Forms::Padding(2);
			this->flowLayoutPanel6->Name = L"flowLayoutPanel6";
			this->flowLayoutPanel6->Size = System::Drawing::Size(229, 53);
			this->flowLayoutPanel6->TabIndex = 18;
			// 
			// floorMonstersLabel
			// 
			this->floorMonstersLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->floorMonstersLabel->Font = (gcnew System::Drawing::Font(L"Algerian", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->floorMonstersLabel->Location = System::Drawing::Point(0, 0);
			this->floorMonstersLabel->Margin = System::Windows::Forms::Padding(0);
			this->floorMonstersLabel->Name = L"floorMonstersLabel";
			this->floorMonstersLabel->Size = System::Drawing::Size(226, 24);
			this->floorMonstersLabel->TabIndex = 9;
			this->floorMonstersLabel->Text = L"MONSTERS";
			this->floorMonstersLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// floorNumOfMonsters
			// 
			this->floorNumOfMonsters->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->floorNumOfMonsters->Font = (gcnew System::Drawing::Font(L"Algerian", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->floorNumOfMonsters->Location = System::Drawing::Point(0, 24);
			this->floorNumOfMonsters->Margin = System::Windows::Forms::Padding(0);
			this->floorNumOfMonsters->Name = L"floorNumOfMonsters";
			this->floorNumOfMonsters->Size = System::Drawing::Size(226, 29);
			this->floorNumOfMonsters->TabIndex = 10;
			this->floorNumOfMonsters->Text = L"-";
			this->floorNumOfMonsters->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// flowLayoutPanel7
			// 
			this->flowLayoutPanel7->BackColor = System::Drawing::Color::Gray;
			this->flowLayoutPanel7->Controls->Add(this->floorTrapsLabel);
			this->flowLayoutPanel7->Controls->Add(this->floorNumOfTraps);
			this->flowLayoutPanel7->Location = System::Drawing::Point(6, 346);
			this->flowLayoutPanel7->Margin = System::Windows::Forms::Padding(2);
			this->flowLayoutPanel7->Name = L"flowLayoutPanel7";
			this->flowLayoutPanel7->Size = System::Drawing::Size(229, 53);
			this->flowLayoutPanel7->TabIndex = 19;
			// 
			// floorTrapsLabel
			// 
			this->floorTrapsLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->floorTrapsLabel->Font = (gcnew System::Drawing::Font(L"Algerian", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->floorTrapsLabel->Location = System::Drawing::Point(0, 0);
			this->floorTrapsLabel->Margin = System::Windows::Forms::Padding(0);
			this->floorTrapsLabel->Name = L"floorTrapsLabel";
			this->floorTrapsLabel->Size = System::Drawing::Size(226, 24);
			this->floorTrapsLabel->TabIndex = 9;
			this->floorTrapsLabel->Text = L"TRAPS";
			this->floorTrapsLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// floorNumOfTraps
			// 
			this->floorNumOfTraps->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->floorNumOfTraps->Font = (gcnew System::Drawing::Font(L"Algerian", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->floorNumOfTraps->Location = System::Drawing::Point(0, 24);
			this->floorNumOfTraps->Margin = System::Windows::Forms::Padding(0);
			this->floorNumOfTraps->Name = L"floorNumOfTraps";
			this->floorNumOfTraps->Size = System::Drawing::Size(226, 29);
			this->floorNumOfTraps->TabIndex = 10;
			this->floorNumOfTraps->Text = L"-";
			this->floorNumOfTraps->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// flowLayoutPanel8
			// 
			this->flowLayoutPanel8->BackColor = System::Drawing::Color::Gray;
			this->flowLayoutPanel8->Controls->Add(this->label12);
			this->flowLayoutPanel8->Controls->Add(this->label13);
			this->flowLayoutPanel8->Location = System::Drawing::Point(6, 403);
			this->flowLayoutPanel8->Margin = System::Windows::Forms::Padding(2);
			this->flowLayoutPanel8->Name = L"flowLayoutPanel8";
			this->flowLayoutPanel8->Size = System::Drawing::Size(229, 53);
			this->flowLayoutPanel8->TabIndex = 20;
			// 
			// label12
			// 
			this->label12->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->label12->Font = (gcnew System::Drawing::Font(L"Algerian", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(0, 0);
			this->label12->Margin = System::Windows::Forms::Padding(0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(226, 24);
			this->label12->TabIndex = 9;
			this->label12->Text = L"FLOOR KILLS";
			this->label12->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label13
			// 
			this->label13->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->label13->Font = (gcnew System::Drawing::Font(L"Algerian", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(0, 24);
			this->label13->Margin = System::Windows::Forms::Padding(0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(226, 29);
			this->label13->TabIndex = 10;
			this->label13->Text = L"-";
			this->label13->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// playerMana
			// 
			this->playerMana->AutoSize = true;
			this->playerMana->BackColor = System::Drawing::Color::Transparent;
			this->playerMana->Font = (gcnew System::Drawing::Font(L"Algerian", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->playerMana->Location = System::Drawing::Point(922, 15);
			this->playerMana->Name = L"playerMana";
			this->playerMana->Size = System::Drawing::Size(66, 26);
			this->playerMana->TabIndex = 13;
			this->playerMana->Text = L"5/20";
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(892, 12);
			this->pictureBox3->MaximumSize = System::Drawing::Size(200, 200);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(29, 32);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox3->TabIndex = 12;
			this->pictureBox3->TabStop = false;
			// 
			// floor3
			// 
			this->floor3->Appearance = System::Windows::Forms::Appearance::Button;
			this->floor3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->floor3->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->floor3->FlatAppearance->BorderSize = 10;
			this->floor3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->floor3->Font = (gcnew System::Drawing::Font(L"Algerian", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->floor3->Location = System::Drawing::Point(279, 389);
			this->floor3->Margin = System::Windows::Forms::Padding(4);
			this->floor3->Name = L"floor3";
			this->floor3->Size = System::Drawing::Size(368, 97);
			this->floor3->TabIndex = 11;
			this->floor3->Text = L"FLOOR 3";
			this->floor3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->floor3->Click += gcnew System::EventHandler(this, &GameWindow::floor3_Click);
			// 
			// floor2
			// 
			this->floor2->Appearance = System::Windows::Forms::Appearance::Button;
			this->floor2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->floor2->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->floor2->FlatAppearance->BorderSize = 10;
			this->floor2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->floor2->Font = (gcnew System::Drawing::Font(L"Algerian", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->floor2->Location = System::Drawing::Point(279, 284);
			this->floor2->Margin = System::Windows::Forms::Padding(4);
			this->floor2->Name = L"floor2";
			this->floor2->Size = System::Drawing::Size(368, 97);
			this->floor2->TabIndex = 10;
			this->floor2->Text = L"FLOOR 2";
			this->floor2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->floor2->Click += gcnew System::EventHandler(this, &GameWindow::floor2_Click);
			// 
			// floor1
			// 
			this->floor1->Appearance = System::Windows::Forms::Appearance::Button;
			this->floor1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->floor1->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->floor1->FlatAppearance->BorderSize = 10;
			this->floor1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->floor1->Font = (gcnew System::Drawing::Font(L"Algerian", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->floor1->Location = System::Drawing::Point(279, 180);
			this->floor1->Margin = System::Windows::Forms::Padding(4);
			this->floor1->Name = L"floor1";
			this->floor1->Size = System::Drawing::Size(368, 97);
			this->floor1->TabIndex = 9;
			this->floor1->Text = L"FLOOR 1";
			this->floor1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->floor1->Click += gcnew System::EventHandler(this, &GameWindow::floor1_Click);
			// 
			// floorTurnNumberLabel
			// 
			this->floorTurnNumberLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->floorTurnNumberLabel->AutoSize = true;
			this->floorTurnNumberLabel->BackColor = System::Drawing::Color::Transparent;
			this->floorTurnNumberLabel->Font = (gcnew System::Drawing::Font(L"Algerian", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->floorTurnNumberLabel->Location = System::Drawing::Point(28, 12);
			this->floorTurnNumberLabel->Name = L"floorTurnNumberLabel";
			this->floorTurnNumberLabel->Size = System::Drawing::Size(108, 30);
			this->floorTurnNumberLabel->TabIndex = 8;
			this->floorTurnNumberLabel->Text = L"TURN: 1";
			this->floorTurnNumberLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// FloorSelectionBG
			// 
			this->FloorSelectionBG->Location = System::Drawing::Point(-4, 0);
			this->FloorSelectionBG->Name = L"FloorSelectionBG";
			this->FloorSelectionBG->Size = System::Drawing::Size(1023, 677);
			this->FloorSelectionBG->TabIndex = 16;
			this->FloorSelectionBG->TabStop = false;
			// 
			// FloorScreen
			// 
			this->FloorScreen->BackColor = System::Drawing::Color::Gray;
			this->FloorScreen->Controls->Add(this->settingsButtonFloorScreen);
			this->FloorScreen->Controls->Add(this->endTurnButton);
			this->FloorScreen->Controls->Add(this->eraseModeCheckBox);
			this->FloorScreen->Controls->Add(this->tileSelectionPictureBox);
			this->FloorScreen->Controls->Add(this->tileSelectionLabel);
			this->FloorScreen->Controls->Add(this->floorEditorLabel);
			this->FloorScreen->Controls->Add(this->turnNumberLabel);
			this->FloorScreen->Controls->Add(this->tileSelectionPanel);
			this->FloorScreen->Controls->Add(this->manaAmountLabel);
			this->FloorScreen->Controls->Add(this->floorSelectionButton);
			this->FloorScreen->Controls->Add(this->pictureBox2);
			this->FloorScreen->Controls->Add(this->tileDescriptionPanel);
			this->FloorScreen->Controls->Add(this->floorGridPanel);
			this->FloorScreen->Controls->Add(this->FloorScreenBG);
			this->FloorScreen->Location = System::Drawing::Point(4, 22);
			this->FloorScreen->Name = L"FloorScreen";
			this->FloorScreen->Size = System::Drawing::Size(1090, 694);
			this->FloorScreen->TabIndex = 6;
			this->FloorScreen->Text = L"FloorScreen";
			// 
			// settingsButtonFloorScreen
			// 
			this->settingsButtonFloorScreen->Font = (gcnew System::Drawing::Font(L"Algerian", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->settingsButtonFloorScreen->Location = System::Drawing::Point(909, 4);
			this->settingsButtonFloorScreen->Name = L"settingsButtonFloorScreen";
			this->settingsButtonFloorScreen->Size = System::Drawing::Size(95, 30);
			this->settingsButtonFloorScreen->TabIndex = 13;
			this->settingsButtonFloorScreen->Text = L"Settings";
			this->settingsButtonFloorScreen->UseVisualStyleBackColor = true;
			this->settingsButtonFloorScreen->Click += gcnew System::EventHandler(this, &GameWindow::settingsButtonFloorScreen_Click);
			// 
			// endTurnButton
			// 
			this->endTurnButton->BackColor = System::Drawing::Color::Transparent;
			this->endTurnButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->endTurnButton->Font = (gcnew System::Drawing::Font(L"Algerian", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->endTurnButton->Location = System::Drawing::Point(802, 577);
			this->endTurnButton->Name = L"endTurnButton";
			this->endTurnButton->Size = System::Drawing::Size(193, 48);
			this->endTurnButton->TabIndex = 12;
			this->endTurnButton->Text = L"End Turn";
			this->endTurnButton->UseVisualStyleBackColor = false;
			this->endTurnButton->Click += gcnew System::EventHandler(this, &GameWindow::endTurnButton_Click);
			// 
			// eraseModeCheckBox
			// 
			this->eraseModeCheckBox->AutoSize = true;
			this->eraseModeCheckBox->BackColor = System::Drawing::Color::Transparent;
			this->eraseModeCheckBox->Font = (gcnew System::Drawing::Font(L"Algerian", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->eraseModeCheckBox->Location = System::Drawing::Point(20, 551);
			this->eraseModeCheckBox->Name = L"eraseModeCheckBox";
			this->eraseModeCheckBox->Size = System::Drawing::Size(195, 34);
			this->eraseModeCheckBox->TabIndex = 11;
			this->eraseModeCheckBox->Text = L"Erase Mode";
			this->eraseModeCheckBox->UseVisualStyleBackColor = false;
			this->eraseModeCheckBox->CheckedChanged += gcnew System::EventHandler(this, &GameWindow::eraseModeCheckBox_CheckedChanged);
			// 
			// tileSelectionPictureBox
			// 
			this->tileSelectionPictureBox->Location = System::Drawing::Point(159, 72);
			this->tileSelectionPictureBox->Name = L"tileSelectionPictureBox";
			this->tileSelectionPictureBox->Size = System::Drawing::Size(56, 56);
			this->tileSelectionPictureBox->TabIndex = 10;
			this->tileSelectionPictureBox->TabStop = false;
			// 
			// tileSelectionLabel
			// 
			this->tileSelectionLabel->AutoSize = true;
			this->tileSelectionLabel->BackColor = System::Drawing::Color::Transparent;
			this->tileSelectionLabel->Font = (gcnew System::Drawing::Font(L"Algerian", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tileSelectionLabel->Location = System::Drawing::Point(7, 68);
			this->tileSelectionLabel->Name = L"tileSelectionLabel";
			this->tileSelectionLabel->Size = System::Drawing::Size(150, 60);
			this->tileSelectionLabel->TabIndex = 9;
			this->tileSelectionLabel->Text = L"Tile \r\nSelection";
			// 
			// floorEditorLabel
			// 
			this->floorEditorLabel->AutoSize = true;
			this->floorEditorLabel->BackColor = System::Drawing::Color::Transparent;
			this->floorEditorLabel->Font = (gcnew System::Drawing::Font(L"Algerian", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->floorEditorLabel->ForeColor = System::Drawing::Color::Black;
			this->floorEditorLabel->Location = System::Drawing::Point(292, 19);
			this->floorEditorLabel->Name = L"floorEditorLabel";
			this->floorEditorLabel->Size = System::Drawing::Size(159, 41);
			this->floorEditorLabel->TabIndex = 8;
			this->floorEditorLabel->Text = L"Floor 1";
			// 
			// turnNumberLabel
			// 
			this->turnNumberLabel->AutoSize = true;
			this->turnNumberLabel->BackColor = System::Drawing::Color::Transparent;
			this->turnNumberLabel->Font = (gcnew System::Drawing::Font(L"Algerian", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->turnNumberLabel->Location = System::Drawing::Point(902, 78);
			this->turnNumberLabel->Name = L"turnNumberLabel";
			this->turnNumberLabel->Size = System::Drawing::Size(96, 26);
			this->turnNumberLabel->TabIndex = 7;
			this->turnNumberLabel->Text = L"Turn: 1";
			// 
			// tileSelectionPanel
			// 
			this->tileSelectionPanel->BackColor = System::Drawing::Color::DimGray;
			this->tileSelectionPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tileSelectionPanel->Controls->Add(this->label3);
			this->tileSelectionPanel->Controls->Add(this->pictureBox1);
			this->tileSelectionPanel->Controls->Add(this->monstersTileList);
			this->tileSelectionPanel->Controls->Add(this->trapsTileList);
			this->tileSelectionPanel->Controls->Add(this->designTileList);
			this->tileSelectionPanel->Controls->Add(this->trapsButton);
			this->tileSelectionPanel->Controls->Add(this->monstersButton);
			this->tileSelectionPanel->Controls->Add(this->designButton);
			this->tileSelectionPanel->Location = System::Drawing::Point(12, 136);
			this->tileSelectionPanel->Name = L"tileSelectionPanel";
			this->tileSelectionPanel->Size = System::Drawing::Size(203, 400);
			this->tileSelectionPanel->TabIndex = 2;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Algerian", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(5, 359);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(153, 21);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Prices in Mana";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(163, 355);
			this->pictureBox1->MaximumSize = System::Drawing::Size(200, 200);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(29, 30);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
			// 
			// monstersTileList
			// 
			this->monstersTileList->BackColor = System::Drawing::Color::DimGray;
			this->monstersTileList->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->monstersTileList->Font = (gcnew System::Drawing::Font(L"Century", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->monstersTileList->ForeColor = System::Drawing::SystemColors::WindowText;
			this->monstersTileList->FormattingEnabled = true;
			this->monstersTileList->ItemHeight = 20;
			this->monstersTileList->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Goblin - 1", L"Orc - 2", L"Ogre - 3" });
			this->monstersTileList->Location = System::Drawing::Point(13, 169);
			this->monstersTileList->Name = L"monstersTileList";
			this->monstersTileList->Size = System::Drawing::Size(181, 100);
			this->monstersTileList->TabIndex = 7;
			this->monstersTileList->Visible = false;
			this->monstersTileList->SelectedIndexChanged += gcnew System::EventHandler(this, &GameWindow::monstersTileList_SelectedIndexChanged);
			// 
			// trapsTileList
			// 
			this->trapsTileList->BackColor = System::Drawing::Color::DimGray;
			this->trapsTileList->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->trapsTileList->Font = (gcnew System::Drawing::Font(L"Century", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->trapsTileList->ForeColor = System::Drawing::SystemColors::WindowText;
			this->trapsTileList->FormattingEnabled = true;
			this->trapsTileList->ItemHeight = 20;
			this->trapsTileList->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Tripwire - 1", L"Pitfall - 2", L"Spikes - 3" });
			this->trapsTileList->Location = System::Drawing::Point(13, 115);
			this->trapsTileList->Name = L"trapsTileList";
			this->trapsTileList->Size = System::Drawing::Size(181, 100);
			this->trapsTileList->TabIndex = 6;
			this->trapsTileList->Visible = false;
			this->trapsTileList->SelectedIndexChanged += gcnew System::EventHandler(this, &GameWindow::trapsTileList_SelectedIndexChanged);
			// 
			// designTileList
			// 
			this->designTileList->BackColor = System::Drawing::Color::DimGray;
			this->designTileList->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->designTileList->Font = (gcnew System::Drawing::Font(L"Century", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->designTileList->ForeColor = System::Drawing::SystemColors::WindowText;
			this->designTileList->FormattingEnabled = true;
			this->designTileList->ItemHeight = 20;
			this->designTileList->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Entrance - 0", L"Exit - 0", L"Path - 1",
					L"Door - 2", L"Chest - 3"
			});
			this->designTileList->Location = System::Drawing::Point(13, 58);
			this->designTileList->Name = L"designTileList";
			this->designTileList->Size = System::Drawing::Size(181, 100);
			this->designTileList->TabIndex = 5;
			this->designTileList->Visible = false;
			this->designTileList->SelectedIndexChanged += gcnew System::EventHandler(this, &GameWindow::designTileList_SelectedIndexChanged);
			// 
			// trapsButton
			// 
			this->trapsButton->Font = (gcnew System::Drawing::Font(L"Algerian", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->trapsButton->Location = System::Drawing::Point(0, 61);
			this->trapsButton->Name = L"trapsButton";
			this->trapsButton->Size = System::Drawing::Size(202, 48);
			this->trapsButton->TabIndex = 4;
			this->trapsButton->Text = L"Traps";
			this->trapsButton->UseVisualStyleBackColor = true;
			this->trapsButton->Click += gcnew System::EventHandler(this, &GameWindow::trapsButton_Click);
			// 
			// monstersButton
			// 
			this->monstersButton->Font = (gcnew System::Drawing::Font(L"Algerian", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->monstersButton->Location = System::Drawing::Point(0, 115);
			this->monstersButton->Name = L"monstersButton";
			this->monstersButton->Size = System::Drawing::Size(202, 48);
			this->monstersButton->TabIndex = 3;
			this->monstersButton->Text = L"Monsters";
			this->monstersButton->UseVisualStyleBackColor = true;
			this->monstersButton->Click += gcnew System::EventHandler(this, &GameWindow::MonstersButton_Click);
			// 
			// designButton
			// 
			this->designButton->Font = (gcnew System::Drawing::Font(L"Algerian", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->designButton->Location = System::Drawing::Point(0, 7);
			this->designButton->Name = L"designButton";
			this->designButton->Size = System::Drawing::Size(202, 48);
			this->designButton->TabIndex = 2;
			this->designButton->Text = L"Design";
			this->designButton->UseVisualStyleBackColor = true;
			this->designButton->Click += gcnew System::EventHandler(this, &GameWindow::designButton_Click);
			// 
			// manaAmountLabel
			// 
			this->manaAmountLabel->AutoSize = true;
			this->manaAmountLabel->BackColor = System::Drawing::Color::Transparent;
			this->manaAmountLabel->Font = (gcnew System::Drawing::Font(L"Algerian", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->manaAmountLabel->Location = System::Drawing::Point(828, 52);
			this->manaAmountLabel->Name = L"manaAmountLabel";
			this->manaAmountLabel->Size = System::Drawing::Size(80, 26);
			this->manaAmountLabel->TabIndex = 6;
			this->manaAmountLabel->Text = L"20/20";
			// 
			// floorSelectionButton
			// 
			this->floorSelectionButton->BackColor = System::Drawing::Color::Transparent;
			this->floorSelectionButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->floorSelectionButton->Font = (gcnew System::Drawing::Font(L"Algerian", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->floorSelectionButton->Location = System::Drawing::Point(802, 523);
			this->floorSelectionButton->Name = L"floorSelectionButton";
			this->floorSelectionButton->Size = System::Drawing::Size(193, 48);
			this->floorSelectionButton->TabIndex = 1;
			this->floorSelectionButton->Text = L"Floor Selection";
			this->floorSelectionButton->UseVisualStyleBackColor = false;
			this->floorSelectionButton->Click += gcnew System::EventHandler(this, &GameWindow::floorSelectionButton_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(793, 48);
			this->pictureBox2->MaximumSize = System::Drawing::Size(200, 200);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(29, 32);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 4;
			this->pictureBox2->TabStop = false;
			// 
			// tileDescriptionPanel
			// 
			this->tileDescriptionPanel->BackColor = System::Drawing::Color::DimGray;
			this->tileDescriptionPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tileDescriptionPanel->Controls->Add(this->tileDescriptionTextBox);
			this->tileDescriptionPanel->Controls->Add(this->tileDescriptionLabel);
			this->tileDescriptionPanel->Location = System::Drawing::Point(795, 112);
			this->tileDescriptionPanel->Name = L"tileDescriptionPanel";
			this->tileDescriptionPanel->Size = System::Drawing::Size(200, 401);
			this->tileDescriptionPanel->TabIndex = 0;
			// 
			// tileDescriptionTextBox
			// 
			this->tileDescriptionTextBox->BackColor = System::Drawing::Color::Gray;
			this->tileDescriptionTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tileDescriptionTextBox->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->tileDescriptionTextBox->Font = (gcnew System::Drawing::Font(L"Berlin Sans FB", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tileDescriptionTextBox->ForeColor = System::Drawing::Color::Black;
			this->tileDescriptionTextBox->Location = System::Drawing::Point(10, 44);
			this->tileDescriptionTextBox->Name = L"tileDescriptionTextBox";
			this->tileDescriptionTextBox->Size = System::Drawing::Size(174, 343);
			this->tileDescriptionTextBox->TabIndex = 1;
			this->tileDescriptionTextBox->Text = L"";
			// 
			// tileDescriptionLabel
			// 
			this->tileDescriptionLabel->AutoSize = true;
			this->tileDescriptionLabel->Font = (gcnew System::Drawing::Font(L"Algerian", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tileDescriptionLabel->Location = System::Drawing::Point(3, 9);
			this->tileDescriptionLabel->Name = L"tileDescriptionLabel";
			this->tileDescriptionLabel->Size = System::Drawing::Size(189, 32);
			this->tileDescriptionLabel->TabIndex = 0;
			this->tileDescriptionLabel->Text = L"Description";
			// 
			// floorGridPanel
			// 
			this->floorGridPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(61)), static_cast<System::Int32>(static_cast<System::Byte>(43)),
				static_cast<System::Int32>(static_cast<System::Byte>(35)));
			this->floorGridPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->floorGridPanel->Location = System::Drawing::Point(226, 65);
			this->floorGridPanel->Name = L"floorGridPanel";
			this->floorGridPanel->Size = System::Drawing::Size(560, 560);
			this->floorGridPanel->TabIndex = 0;
			this->floorGridPanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GameWindow::floorGridPanel_Paint);
			this->floorGridPanel->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &GameWindow::floorGridPanel_MouseClick);
			// 
			// FloorScreenBG
			// 
			this->FloorScreenBG->Location = System::Drawing::Point(-4, 0);
			this->FloorScreenBG->Name = L"FloorScreenBG";
			this->FloorScreenBG->Size = System::Drawing::Size(1023, 677);
			this->FloorScreenBG->TabIndex = 17;
			this->FloorScreenBG->TabStop = false;
			// 
			// GameWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1006, 671);
			this->Controls->Add(this->tabControl1);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1022, 710);
			this->MinimumSize = System::Drawing::Size(1022, 710);
			this->Name = L"GameWindow";
			this->Text = L"Dungeon Builder";
			this->Load += gcnew System::EventHandler(this, &GameWindow::GameWindow_Load);
			this->tabControl1->ResumeLayout(false);
			this->TitleScreen->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			this->SettingsScreen->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			this->SaveGameScreen->ResumeLayout(false);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->EndInit();
			this->LoadGameScreen->ResumeLayout(false);
			this->loadGameLayout->ResumeLayout(false);
			this->loadGameLayout->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->EndInit();
			this->BiomeSelectionScreen->ResumeLayout(false);
			this->biomeSelectionPanel->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->FloorSelectionScreen->ResumeLayout(false);
			this->FloorSelectionScreen->PerformLayout();
			this->flowLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->PerformLayout();
			this->flowLayoutPanel2->ResumeLayout(false);
			this->flowLayoutPanel3->ResumeLayout(false);
			this->flowLayoutPanel3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->flowLayoutPanel4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			this->flowLayoutPanel5->ResumeLayout(false);
			this->flowLayoutPanel6->ResumeLayout(false);
			this->flowLayoutPanel7->ResumeLayout(false);
			this->flowLayoutPanel8->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->FloorSelectionBG))->EndInit();
			this->FloorScreen->ResumeLayout(false);
			this->FloorScreen->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tileSelectionPictureBox))->EndInit();
			this->tileSelectionPanel->ResumeLayout(false);
			this->tileSelectionPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->tileDescriptionPanel->ResumeLayout(false);
			this->tileDescriptionPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->FloorScreenBG))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	
// Takes player to settings screen from title screen
private: System::Void settingsButton_Click(System::Object^ sender, System::EventArgs^ e) {
	tabControl1->SelectTab(SETTINGS_SCREEN);
}

// Takes player to biome selection screen from title screen
private: System::Void newGameButton_Click(System::Object^ sender, System::EventArgs^ e) {
	tabControl1->SelectTab(BIOME_SELECTION_SCREEN);	
}

// Takes player to load game screen from title screen
private: System::Void loadGameButton_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	tabControl1->SelectTab(LOAD_GAME_SCREEN);
	loadGame->showInfo(loadGame1, loadGame2, loadGame3);
}

// takes user back to floor selection screen from floor editor
private: System::Void floorSelectionButton_Click(System::Object^ sender, System::EventArgs^ e) {
	tabControl1->SelectTab(FLOOR_SELECTION_SCREEN);
	floorSelection->updateFloorInfoPanel(floorSelection->getCurrentFloor()->getFloorNum(), floorInfoTitle, floorManaGenAmount, floorNumOfMonsters, floorNumOfTraps);
	designTileList->SelectedItem = nullptr;
	trapsTileList->SelectedItem = nullptr;
	monstersTileList->SelectedItem = nullptr;
	tileDescriptionTextBox->Text = nullptr;
	tileSelectionPictureBox->Image = nullptr;
	eraseModeCheckBox->Checked = false;
}



// Opens up list design tiles when design button clicked
private: System::Void designButton_Click(System::Object^ sender, System::EventArgs^ e) {
	eraseModeCheckBox->Checked = false;  
	tileSelectionPictureBox->Image = nullptr;
	tileDescriptionTextBox->Text = nullptr;

	// relocates components
	trapsButton->Location = Point(0, 222);
	monstersButton->Location = Point(0, 276);

	// makes list visible
	designTileList->Visible = true;
	trapsTileList->Visible = false;
	monstersTileList->Visible = false;

	//Unselect other categories
	monstersTileList->SelectedItem = nullptr;
	trapsTileList->SelectedItem = nullptr;
}

// Opens up list of trap tiles when traps button clicked
private: System::Void trapsButton_Click(System::Object^ sender, System::EventArgs^ e) {
	eraseModeCheckBox->Checked = false;
	tileSelectionPictureBox->Image = nullptr;
	tileDescriptionTextBox->Text = nullptr;

	// relocates components
	trapsButton->Location = Point(0, 61);
	monstersButton->Location = Point(0, 282);

	// makes list visible
	designTileList->Visible = false;
	trapsTileList->Visible = true;
	monstersTileList->Visible = false;

	//Unselect other categories
	monstersTileList->SelectedItem = nullptr;
	designTileList->SelectedItem = nullptr;
}

// Opens up list of monster tiles when monsters button clicked
private: System::Void MonstersButton_Click(System::Object^ sender, System::EventArgs^ e) {
	eraseModeCheckBox->Checked = false;
	tileSelectionPictureBox->Image = nullptr;
	tileDescriptionTextBox->Text = nullptr;

	// relocates components
	trapsButton->Location = Point(0, 61);
	monstersButton->Location = Point(0, 115);

	// sets list to visible
	designTileList->Visible = false;
	trapsTileList->Visible = false;
	monstersTileList->Visible = true;

	//Unselect other categories
	designTileList->SelectedItem = nullptr;
	trapsTileList->SelectedItem = nullptr;
}

// Displays the image and description of selected design tile
private: System::Void designTileList_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	Color color;
	tileDescriptionTextBox->ForeColor = color.Black;
	if (designTileList->SelectedItem != nullptr)
	{
		eraseModeCheckBox->Checked = false;
		String^ curItem = designTileList->SelectedItem->ToString();
		tileSelectionController->displaySelectedInfoDesign(designTileList->FindString(curItem));
	}
	//Unselect other categories
	monstersTileList->SelectedItem = nullptr;
	trapsTileList->SelectedItem = nullptr;
}

// Displays the image and description of selected traps tile
private: System::Void trapsTileList_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	Color color;
	tileDescriptionTextBox->ForeColor = color.Black;
	if (trapsTileList->SelectedItem != nullptr)
	{
		eraseModeCheckBox->Checked = false;
		String^ curItem = trapsTileList->SelectedItem->ToString();
		tileSelectionController->displaySelectedInfoTraps(trapsTileList->FindString(curItem));
	}
	//Unselect other categories
	monstersTileList->SelectedItem = nullptr;
	designTileList->SelectedItem = nullptr;
}

// Displays the image and description of selected monsters tile
private: System::Void monstersTileList_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	Color color;
	tileDescriptionTextBox->ForeColor = color.Black;
	if (monstersTileList->SelectedItem != nullptr)
	{
		eraseModeCheckBox->Checked = false;
		String^ curItem = monstersTileList->SelectedItem->ToString();
		tileSelectionController->displaySelectedInfoMonsters(monstersTileList->FindString(curItem));
	}
	//Unselect other categories
	trapsTileList->SelectedItem = nullptr;
	designTileList->SelectedItem = nullptr;
}


//-----------------------------------------------------------------------------------
//
//  TODO: MODULARIZE THIS
//
//-------------------------------------------------------------------------------------
// calls appropriate methods for when user clicks on floor to add or remove tiles.
private: System::Void floorGridPanel_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (eraseModeCheckBox->Checked == true)
	{
		int mana = floorSelection->getCurrentFloor()->removeTile(e->X / floorSelection->getCurrentFloor()->getTileSize(), e->Y / floorSelection->getCurrentFloor()->getTileSize());
		gameController->manaGain(mana);
		floorSelection->getCurrentFloor()->setManaSpent(-mana);
		return;
	}

	String^ curItem;
	int index = -1;
	if (designTileList->SelectedItem != nullptr)
	{
		curItem = designTileList->SelectedItem->ToString();
		index = designTileList->FindString(curItem);
	}
	if (index >= 0)
	{
		if (index == 0 && floorSelection->getCurrentFloor()->hasAnEntrance())
		{
			Color color;
			tileDescriptionTextBox->ForeColor = color.DarkRed;
			tileDescriptionTextBox->Text = "Only one entrance can exist per floor!";
			return;
		}
		if (index == 1 && floorSelection->getCurrentFloor()->hasAnExit())
		{
			Color color;
			tileDescriptionTextBox->ForeColor = color.DarkRed;
			tileDescriptionTextBox->Text = "Only one exit can exist per floor!";
			return;
		}
		int cost = floorSelection->getCurrentFloor()->setTile(1, index, e->X / floorSelection->getCurrentFloor()->getTileSize(), e->Y / floorSelection->getCurrentFloor()->getTileSize(), gameController->getMana());
		if (cost == -10)
		{
			Color color;
			tileDescriptionTextBox->ForeColor = color.DarkRed;
			tileDescriptionTextBox->Text = "Not enough Mana!";
		}
		else
		{
			gameController->spendMana(cost);
			floorSelection->getCurrentFloor()->setManaSpent(cost);
		}
		return;
	}

	if (trapsTileList->SelectedItem != nullptr)
	{
		curItem = trapsTileList->SelectedItem->ToString();
		index = trapsTileList->FindString(curItem);
	}
	if (index >= 0)
	{
		int cost = floorSelection->getCurrentFloor()->setTile(2, index, e->X / floorSelection->getCurrentFloor()->getTileSize(), e->Y / floorSelection->getCurrentFloor()->getTileSize(), gameController->getMana());
		if (cost == -10)
		{
			Color color;
			tileDescriptionTextBox->ForeColor = color.DarkRed;
			tileDescriptionTextBox->Text = "Not enough Mana!";
		}
		else
		{
			gameController->spendMana(cost);
			floorSelection->getCurrentFloor()->setManaSpent(cost);
		}
		return;
	}

	if (monstersTileList->SelectedItem != nullptr)
	{
		curItem = monstersTileList->SelectedItem->ToString();
		index = monstersTileList->FindString(curItem);
	}
	if (index >= 0)
	{
		int cost = floorSelection->getCurrentFloor()->setTile(3, index, e->X / floorSelection->getCurrentFloor()->getTileSize(), e->Y / floorSelection->getCurrentFloor()->getTileSize(), gameController->getMana());
		if (cost == -10)
		{
			Color color;
			tileDescriptionTextBox->ForeColor = color.DarkRed;
			tileDescriptionTextBox->Text = "Not enough Mana!";
		}
		else
		{
			gameController->spendMana(cost);
			floorSelection->getCurrentFloor()->setManaSpent(cost);
		}
		return;
	}
}






// redraws dungeon floor
private: System::Void floorGridPanel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	floorSelection->getCurrentFloor()->drawFloor();
}

// displays red x for when erase mode is activated
private: System::Void eraseModeCheckBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (eraseModeCheckBox->Checked == true)
	{
		Color color;
		tileDescriptionTextBox->ForeColor = color.Black;
		gcroot<Drawing::Bitmap^> image;
		image = gcnew Drawing::Bitmap("redX.bmp");
		image->MakeTransparent(image->GetPixel(1, 1));
		tileSelectionPictureBox->Image = image;
		tileDescriptionTextBox->Text = "Remove Tiles. Costs will be refunded.";

		// unselect tiles
		designTileList->SelectedItem = nullptr;
		monstersTileList->SelectedItem = nullptr;
		trapsTileList->SelectedItem = nullptr;
	}
	else
	{
		tileDescriptionTextBox->Text = nullptr;
		tileSelectionPictureBox->Image = nullptr;
	}
}

// Unchecks the other games to load and checks the slot 1 game.
private: System::Void loadGame1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (loadGame1->Text != "EMPTY")
	{
		if (loadGame2->Checked || loadGame3->Checked)
		{
			loadGame2->Checked = false;
			loadGame3->Checked = false;
		}
		loadGame1->Checked = true;
	}
	else
		loadGame1->Checked = false;
}

// Unchecks the other games to load and checks the slot 2 game.
private: System::Void loadGame2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (loadGame2->Text != "EMPTY")
	{
		if (loadGame1->Checked || loadGame3->Checked)
		{
			loadGame1->Checked = false;
			loadGame3->Checked = false;
		}
		loadGame2->Checked = true;
	}
	else
		loadGame2->Checked = false;
}

// Unchecks the other games to load and checks the slot 3 game.
private: System::Void loadGame3_Click(System::Object^ sender, System::EventArgs^ e) {
	if (loadGame3->Text != "EMPTY")
	{
		if (loadGame1->Checked || loadGame2->Checked)
		{
			loadGame1->Checked = false;
			loadGame2->Checked = false;
		}
		loadGame3->Checked = true;
	}
	else
		loadGame3->Checked = false;
}

// Loads the checked game or does nothing if all games are unchecked.
private: System::Void loadButton_Click(System::Object^ sender, System::EventArgs^ e) {
	if (loadGame1->Checked)
	{
		loadGame->load("save1.txt", floorSelection, floorGridPanel, gameController);
	}
	else if (loadGame2->Checked)
	{
		loadGame->load("save2.txt", floorSelection, floorGridPanel, gameController);
	}
	else if (loadGame3->Checked)
	{
		loadGame->load("save3.txt", floorSelection, floorGridPanel, gameController);
	}
	if (loadGame1->Checked || loadGame2->Checked || loadGame3->Checked)
	{
		floorEditorBiome = biomeSelection->createBiome(gameController->getBiome(), FloorSelectionBG, floorType, BossName, FloorScreenBG);
		tabControl1->SelectTab(FLOOR_SELECTION_SCREEN);
	}
}

// Unchecks the other saved games and checks the save slot 1.
private: System::Void saveGame1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (saveGame2->Checked || saveGame3->Checked)
	{
		saveGame2->Checked = false;
		saveGame3->Checked = false;
	}
	saveGame1->Checked = true;
}

// Unchecks the other saved games and checks the save slot 2.
private: System::Void saveGame2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (saveGame1->Checked || saveGame3->Checked)
	{
		saveGame1->Checked = false;
		saveGame3->Checked = false;
	}
	saveGame2->Checked = true;
}

// Unchecks the other saved games and checks the save slot 3.
private: System::Void saveGame3_Click(System::Object^ sender, System::EventArgs^ e) {
	if (saveGame1->Checked || saveGame2->Checked)
	{
		saveGame1->Checked = false;
		saveGame2->Checked = false;
	}
	saveGame3->Checked = true;
}

// Saves the current game in the checked slot or does nothing if all slots are unchecked.
private: System::Void saveButton_Click(System::Object^ sender, System::EventArgs^ e) {
	if (saveGame1->Checked)
	{
		saveGame->save("save1.txt", floorEditorBiome, floorSelection, gameController);
	}
	else if (saveGame2->Checked)
	{
		saveGame->save("save2.txt", floorEditorBiome, floorSelection, gameController);
	}
	else if (saveGame3->Checked)
	{
		saveGame->save("save3.txt", floorEditorBiome, floorSelection, gameController);
	}
	loadGame->showInfo(saveGame1, saveGame2, saveGame3);
}

// Unchecks the other floors and checks floor 1.
private: System::Void floor1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (floor2->Checked || floor3->Checked)
	{
		floor2->Checked = false;
		floor3->Checked = false;
	}
	floor1->Checked = true;
	floorSelection->updateFloorInfoPanel(0, floorInfoTitle, floorManaGenAmount, floorNumOfMonsters, floorNumOfTraps);
}

// Unchecks the other floors and checks floor 2.
private: System::Void floor2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (floor1->Checked || floor3->Checked)
	{
		floor1->Checked = false;
		floor3->Checked = false;
	}
	floor2->Checked = true;
	floorSelection->updateFloorInfoPanel(1, floorInfoTitle, floorManaGenAmount, floorNumOfMonsters, floorNumOfTraps);
}

// Unchecks the other floors and checks floor 3.
private: System::Void floor3_Click(System::Object^ sender, System::EventArgs^ e) {
	if (floor1->Checked || floor2->Checked)
	{
		floor1->Checked = false;
		floor2->Checked = false;
	}
	floor3->Checked = true;
	floorSelection->updateFloorInfoPanel(2, floorInfoTitle, floorManaGenAmount, floorNumOfMonsters, floorNumOfTraps);
}


private: System::Void enterFloorButton_Click(System::Object^ sender, System::EventArgs^ e) {
	if (floor1->Checked)
		floorSelection->loadFloor(0, floorGridPanel);
	else if (floor2->Checked)
		floorSelection->loadFloor(1, floorGridPanel);
	else if (floor3->Checked)
		floorSelection->loadFloor(2, floorGridPanel);
	tabControl1->SelectTab(FLOOR_SCREEN);
	floorEditorLabel->Text = "FLOOR " + (floorSelection->getCurrentFloor()->getFloorNum() + 1) + ": " + floorEditorBiome + " BIOME";
}

// goes to setting screen from floor screen
private: System::Void settingsButtonFloorScreen_Click(System::Object^ sender, System::EventArgs^ e) {
	tabControl1->SelectTab(SETTINGS_SCREEN);

	designTileList->SelectedItem = nullptr;
	trapsTileList->SelectedItem = nullptr;
	monstersTileList->SelectedItem = nullptr;
	tileDescriptionTextBox->Text = nullptr;
	tileSelectionPictureBox->Image = nullptr;
	eraseModeCheckBox->Checked = false;
}

// end current turn and goes to next
private: System::Void endTurnButton_Click(System::Object^ sender, System::EventArgs^ e) {
	designTileList->SelectedItem = nullptr;
	trapsTileList->SelectedItem = nullptr;
	monstersTileList->SelectedItem = nullptr;
	eraseModeCheckBox->Checked = false;

	if (floorSelection->floorsValid())
	{
		gameController->endTurn();
		tileDescriptionTextBox->Text = nullptr;
		tileSelectionPictureBox->Image = nullptr;
	}
	else
	{
		gcroot<Drawing::Bitmap^> image;
		image = gcnew Drawing::Bitmap("exclamationPoint.bmp");
		image->MakeTransparent(image->GetPixel(1, 1));
		tileSelectionPictureBox->Image = image;
		Color color;
		tileDescriptionTextBox->ForeColor = color.DarkRed;
		if (!floorSelection->getCurrentFloor()->isValid())
		{
			if (!floorSelection->getCurrentFloor()->hasAnEntrance())
				tileDescriptionTextBox->Text = "Cannot end turn. Floor does not have an entrance!";
			else if (!floorSelection->getCurrentFloor()->hasAnExit())
				tileDescriptionTextBox->Text = "Cannot end turn. Floor does not have an exit!";
			else
				tileDescriptionTextBox->Text = "Cannot end turn. A valid path needs to exist from entrance to exit!";
		}
		else 
			tileDescriptionTextBox->Text = "Cannot end turn. Another floor is not valid";
	}
}

// Biome selection panel Paint function
private: System::Void biomeSelectionPanel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	// create a 'mini-panel' to scale the image to
	Point ulCorner = Point(0, 0);
	Point urCorner = Point(image->Width - 1, 0);
	Point llCorner = Point(0, image->Height - 1);
	cli::array<Point>^ destPara = { ulCorner,urCorner,llCorner };

	// draw the image to the graphics object
	e->Graphics->DrawImage(image, destPara);
}

// Loads biome info when appropriate color is clicked
private: System::Void biomeSelectionPanel_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	int xCoord = e->X;
	int yCoord = e->Y;
	Bitmap worldMap("WorldMap.bmp");
	Color pixelColor = worldMap.GetPixel(xCoord, yCoord);
	int biome = biomeSelection->loadBiome(pixelColor);
	if (biome == 0)
	{
		biomeNameBox->Text = "Desert";
		biomeDescBox->Text = "A scorching wasteland devoid of water. Here you will encounter only the most prepared adventurers but it may take some time for them to find you.";
		gameController->setBiome(biome);
	}
	else if (biome == 1)
	{
		biomeNameBox->Text = "Forest";
		biomeDescBox->Text = "A lush forest teeming with wildlife. A popular area for new adventurers to start exploring the world.";
		gameController->setBiome(biome);
	}
	else if (biome == 2)
	{
		biomeNameBox->Text = "Mountains";
		biomeDescBox->Text = "The mountains are filled with resources and opportunities but it is also the most hunted dungeon type.";
		gameController->setBiome(biome);
	}
}
private: System::Void biomeConfirmButton_Click(System::Object^ sender, System::EventArgs^ e) {
	if (gameController->getBiome() > -1)
	{
		floorEditorBiome = biomeSelection->createBiome(gameController->getBiome(), FloorSelectionBG, floorType, BossName, FloorScreenBG);
		FloorScreenBG->Image = FloorSelectionBG->Image;
		tabControl1->SelectTab(FLOOR_SELECTION_SCREEN);
	}
}
private: System::Void settingsSaveButton_Click(System::Object^ sender, System::EventArgs^ e) {
	tabControl1->SelectTab(SAVE_GAME_SCREEN);
	loadGame->showInfo(saveGame1, saveGame2, saveGame3);
}
private: System::Void settingsLoadButton_Click(System::Object^ sender, System::EventArgs^ e) {
	prevScreen = tabControl1->SelectedIndex;
	tabControl1->SelectTab(LOAD_GAME_SCREEN);
	loadGame->showInfo(loadGame1, loadGame2, loadGame3);

}
private: System::Void settingsBackButton_Click(System::Object^ sender, System::EventArgs^ e) {
	tabControl1->SelectTab(FLOOR_SCREEN);
}
private: System::Void loadScreenBack_Click(System::Object^ sender, System::EventArgs^ e) {
	tabControl1->SelectTab(prevScreen);
}
private: System::Void saveScreenBack_Click(System::Object^ sender, System::EventArgs^ e) {
	tabControl1->SelectTab(FLOOR_SCREEN);
}
private: System::Void tabControl1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	floorTurnNumberLabel->Text = turnNumberLabel->Text;
	playerMana->Text = manaAmountLabel->Text;
}
private: System::Void GameWindow_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void settingsTitleScreenButton_Click(System::Object^ sender, System::EventArgs^ e) {
	tabControl1->SelectTab(TITLE_SCREEN);
}

private: System::Void floorManaSpent_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
