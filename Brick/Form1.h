#pragma once

bool paddleRight = false;
bool paddleLeft = false;
int lives = 5, level = 1;
int mX = 300, mY = 590;
int vX = 0, vY = 6;
int fX = 600, fY = 650;
int pX = mX+25, pY = mY-25;
namespace Brick {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		static array<Button ^>^ buttons = gcnew array<Button ^>(100);
		Form1(void)
		{
			InitializeComponent();
			createButtons();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^ textBox1;
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
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();

			this->button1->Location = System::Drawing::Point(pX, pY);
			this->button1->Name = L"button1";
			this->button1->FlatStyle = FlatStyle::Popup;
			this->button1->Size = System::Drawing::Size(25, 25);
			this->button1->TabIndex = 0;
			this->button1->BackColor = Color::Red;
			this->button1->Visible = false;
			this->button1->Text = L" ";
			
			this->button2->Location = System::Drawing::Point(mX, mY);
			this->button2->Name = L"button2";
			this->button2->FlatStyle = FlatStyle::Popup;
			this->button2->Size = System::Drawing::Size(70, 10);
			this->button2->TabIndex = 0;
			this->button2->Visible = false;
			this->button2->BackColor = Color::Blue;
			this->button2->Text = L" ";
			this->button2->Focus();
			this->button2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::button2_KeyPress);
			//this->button2->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::button2_KeyDown);
			//this->button2->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::button2_KeyUp);

			
			this->button3->Location = System::Drawing::Point(475, 5);
			this->button3->Name = L"button3";
			this->button3->FlatStyle = FlatStyle::Popup;
			this->button3->Size = System::Drawing::Size(75, 25);
			this->button3->TabIndex = 0;
			this->button3->BackColor = Color::Black;
			this->button3->ForeColor = Color::White;
			this->button3->Text = L"New Game";
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
	


			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			this->timer1->Enabled = false;
			this->timer1->Stop();
			this->timer1->Interval = 1;

			this->label1->Location = System::Drawing::Point(10, 10);
			this->label1->Size = System::Drawing::Size(50, 20);
			this->label1->Name = L"label1";
			this->label1->ForeColor = Color::White;
			this->label1->TabIndex = 1;
			this->label1->Text = "Lives: "+lives.ToString();


			this->textBox1->Location = System::Drawing::Point(140, 97);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Text = "Enter Level";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			this->textBox1->Click += gcnew System::EventHandler(this, &Form1::textBox1_Click);


			this->Controls->Add(this->button1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->BackColor = Color::Black;
			this->components = gcnew System::ComponentModel::Container();
			this->Size = System::Drawing::Size(fX,fY);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->Text = L"Brick Breaker";
			this->Padding = System::Windows::Forms::Padding(0);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			
		}
		#pragma endregion
		void boundaries(void)
		{
			if(pX < 0)
			{
				vX *= -1;
			}
			if((pX + 45) > fX)
			{
				vX *= -1;
			}
			if(pY < 0)
			{
				vY *= -1;
			}
			if((pX > mX - 20)&&(pX < mX + 70)&&(pY + 30 >= mY)&&(vY > 0)&&(this->button1->Location != System::Drawing::Point(mX+25, mY-25)))
			{
				vY *= -1;
				if((pX <= mX + 50)&&(pX >= mX))//BAll - 30 pixels
				{
					if(pX < mX + 35){vX--;}
					else{vX++;}
				}
				if(pX > mX + 50){vX += 4;}
				if(pX < mX){vX -= 4;}
			}
			if((pY + 65) > fY)
			{
				//vY *= -1;
				lives--;
				this->label1->Text = "Lives: "+lives.ToString();
				pX = mX+25;
				pY = mY-25;
				this->button1->Location = System::Drawing::Point(pX, pY);
				this->timer1->Stop();
				this->timer1->Enabled = false;
				
			}//pX - ball			mX - paddle
		}
		void blockBounce(void)
		{
			int tmpX = vX, tmpY = vY;
			for(int i = 0; i < 100; i++)
			{
				if(this->buttons[i]->Visible == true)
				{
					for(int j = -30; j < 30; j++)
					{
						for(int k = -30; k < 30; k++)
						{
							if(this->buttons[i]->Location == System::Drawing::Point(pX+j, pY+k))
							{
								//if(tmpY == vY){vY *= -1;}
								//if(tmpX == vX){vX *= -1;}
								if((tmpY == vY)&&((k > 20)||(k < -20))){vY *= -1;}
								else if((tmpX == vX)&&((j > 20)||(j < -20))){vX *= -1;}
								this->buttons[i]->Visible = false;
							}
						} 
					}
				}
			}
		}
		void createButtons(void)
		{
			int x = 0, y = 0;
			for(int i = 0; i < 100; i++)
			{
				if(!this->Controls->Contains(buttons[i]))
				{
					x = i % 20;
					if(x == 0){y++;}
					buttons[i] = (gcnew System::Windows::Forms::Button());
					this->buttons[i]->Location = System::Drawing::Point(80+(x*20), (y*60));
					buttons[i]->Name = i.ToString();
					buttons[i]->Size = System::Drawing::Size(20, 20);
					buttons[i]->TabIndex = i;
					buttons[i]->Text = " ";
					buttons[i]->Visible = false;
					buttons[i]->Enabled = true;
					buttons[i]->FlatStyle = FlatStyle::Popup;
					buttons[i]->BackColor = Color::Green;
					//buttons[i]->Click += gcnew EventHandler(this, &Form1::ButtonsClick);
					this->Controls->Add(buttons[i]);
				}
				else
				{
					buttons[i]->Visible = true;
				}
			}
		}
		int gameOver(void)
		{
			int end = 1;
			if(lives <= 0)
			{
				this->timer1->Stop();
				MessageBox::Show("You Lose");
			}
			for(int i = 0; i < 100; i++)
			{
				if(buttons[i]->Visible == true)
				{
					end = 0;
				}					
			}
			if(end == 1)
			{
				this->timer1->Stop();
				MessageBox::Show("You Win!");
				level++;
				switchLevel();
			}
			return end;
		}
		void switchLevel(void)
		{
				switch (level)
				{
				case 1: 
					break;
				case 2: levelTwo();
					break;
				case 3: levelThree();
					break;
				case 4: levelFour();
					break;
				case 5: levelFive();
					break;
				case 6: levelSix();
					break;
				case 7: levelSeven();
					break;
				}
		}
		void levelTwo(void)
		{
			lives = 5;
			this->label1->Text = "Lives: "+lives.ToString();
			int x = 0, y = 0;
			for(int i = 0; i < 100; i++)
			{
				int b = i+1, z = 0, a = 20;
					while(b > 10)
					{
						b -= 10;
						z++;
					}
					if(z % 2 == 0){a = 0;}
					x = i % 10;
					if(x == 0){y++;}
				this->buttons[i]->Location = System::Drawing::Point(70+a+(x*40), (y*20));
				this->buttons[i]->Enabled = true;
				this->buttons[i]->Visible = true;
			}
				pX = mX+25;
				pY = mY-25;
				this->button1->Location = System::Drawing::Point(pX, pY);
		}	
		void levelThree(void)
		{
			lives = 5;
			this->label1->Text = "Lives: "+lives.ToString();
			int x = 0, y = 0;
			for(int i = 0; i < 100; i++)
			{
				x = (i % (20-y));
				if(x == 0){y++; x+=10;}
				if(y == 10)
				{
					this->buttons[i]->Location = System::Drawing::Point((x*30)-15, (y*30));
				}
				else
				{
					this->buttons[i]->Location = System::Drawing::Point((x*30), (y*30));
				}
				this->buttons[i]->Enabled = true;
				this->buttons[i]->Visible = true;
			}
				pX = mX+25;
				pY = mY-25;
				this->button1->Location = System::Drawing::Point(pX, pY);
		}

		void levelFour(void)
		{
			
			lives = 5;
			this->label1->Text = "Lives: "+lives.ToString();
			int x = 0, y = 0;
			for(int i = 0; i < 100; i++)
			{
				x = (i % 10);
				if(x == 0){y++;}
				this->buttons[i]->Location = System::Drawing::Point((x*50)+50, (y*50)-20);
				this->buttons[i]->Enabled = true;
				this->buttons[i]->Visible = true;
			}
				pX = mX+25;
				pY = mY-25;
				this->button1->Location = System::Drawing::Point(pX, pY);
		
		}
		void levelFive(void)
		{
			lives = 5;
			this->label1->Text = "Lives: "+lives.ToString();
			int x = 0, y = 0;
			for(int i = 0; i < 100; i++)
			{
				x = (i % 10);
				if(x == 0){y++;}
				this->buttons[i]->Location = System::Drawing::Point(((y-x)*20+250), ((x+y)*20));
				this->buttons[i]->Enabled = true;
				this->buttons[i]->Visible = true;
			}
				pX = mX+25;
				pY = mY-25;
				this->button1->Location = System::Drawing::Point(pX, pY);
		
		}

		void levelSix(void)
		{
			lives = 5;
			this->label1->Text = "Lives: "+lives.ToString();
			int x = 0, y = 0;
			for(int i = 0; i < 100; i++)
			{
				//x = (i % 10);
				//if(x == 0){y++;}
				if(i < 16)
				{
					x = i % 4;
					if(x == 0){y++;}
					//this->buttons[i]->Location = System::Drawing::Point((((x-y)*30)+200), (((y-2)*x*2))+100);
					this->buttons[i]->Location = System::Drawing::Point(x*20+150, y*20+50);
				}
				if((i < 32)&&(i >= 16))
				{
					x = i % 4;
					if(x == 0){y++;}
					if(y == 5){y = 0;}
					this->buttons[i]->Location = System::Drawing::Point(x*20+350, (y+1)*20+50);
				}
				if((i >= 32)&&(i < 40))
				{
					x = i % 2;
					if(x == 0){y++;}
					this->buttons[i]->Location = System::Drawing::Point(x*20+40, y*20+320);
				}
				if((i >= 40)&&(i < 80))
				{
					x = (i % 20);
					if(x == 0){y++;}
					this->buttons[i]->Location = System::Drawing::Point(x*20+80, y*20+300);
				}
				if((i >= 80)&&(i < 90))
				{
					x = i % 2;
					if(x == 0){y++;}
					this->buttons[i]->Location = System::Drawing::Point(x*20+40, y*20+200);
				}
				if((i >= 90))
				{
					x = i % 2;
					if(x == 0){y++;}
					if(y == 5){y = 0;}
					this->buttons[i]->Location = System::Drawing::Point(x*20+480, y*20+100);
				}
				
				this->buttons[i]->Enabled = true;
				this->buttons[i]->Visible = true;
			}
				pX = mX+25;
				pY = mY-25;
				this->button1->Location = System::Drawing::Point(pX, pY);
		
		}
		void levelSeven(void)
		{
			lives = 5;
			this->label1->Text = "Lives: "+lives.ToString();
			int x = 0, y = 0;
			for(int i = 0; i < 100; i++)
			{
				x = (i % 10);
				if(x == 0){y++;}
				//if(i < )
				this->buttons[i]->Location = System::Drawing::Point(((y-x)*20+250), ((x+y)*20));
				this->buttons[i]->Enabled = true;
				this->buttons[i]->Visible = true;
			}
			pX = mX+25;
			pY = mY-25;
			this->button1->Location = System::Drawing::Point(pX, pY);
		
		}

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e){

				 pX += vX;
				 pY += vY;
				 if((paddleRight == true)&&(paddleLeft == false))
				 {
					//mX += 15;
					paddleRight = false;
				 }
				 else if((paddleLeft == true)&&(paddleRight == false))
				 {
					//mX -= 15;
					paddleLeft = false;
				 }
				 blockBounce();
				 boundaries();
				 this->button1->Location = System::Drawing::Point(pX, pY);
				 this->button2->Location = System::Drawing::Point(mX, mY);
	 			 gameOver();
			 }
	private: System::Void button2_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
				 
				 int inc = 50;
				// if(this->timer1->Enabled == true)
				 {
				 if(e->KeyChar == 'f')
				 {
					 mX += inc;
					 paddleLeft = true;
				 }
				 if(e->KeyChar == 's')
				 {
					 mX -= inc;
					 paddleRight = true;
				 }
				 if(mX < 0)
				 {
					 mX = 0;
				 }
				 if(mX > fX - 60)
				 {
					mX = fX - 60;
				 }
				 }
				 if(e->KeyChar == 'p')
				 {
					 this->timer1->Stop();
					 this->timer1->Enabled = false;
				 }
				 if(e->KeyChar == ' ')
				 {
					 vX = 1;
					 this->timer1->Start();	 
					 this->timer1->Enabled = true;
				 }
				 if((this->timer1->Enabled == false)&&(e->KeyChar != 'p'))
				 {
					pX = mX+25;
					pY = mY-25;
					this->button1->Location = System::Drawing::Point(pX, pY);
				 }
				 this->button2->Location = System::Drawing::Point(mX, mY);
			 }	
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
				createButtons();
				this->button2->Focus();
				if((this->textBox1->Text != "Enter Level")&&(this->textBox1->Text != ""))
				{
					level = System::Convert::ToInt64(this->textBox1->Text);
				}
				switchLevel();
				if(textBox1->Visible == true)
				{
					textBox1->Visible = false;
				}
				else
				{
					textBox1->Visible = true;
					for(int i = 0; i < 100; i++)
					{
						this->buttons[i]->Visible = false;
					}
				}
				if(this->button1->Visible == false)
				{
					this->button1->Visible = true;
				}
				else
				{
					this->button1->Visible = false;
				}

				if(this->button2->Visible == false)
				{
					this->button2->Visible = true;
				}
				else
				{
					this->button2->Visible = false;
				}
				this->button2->Focus();
			 }

		 private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
					  //this->textBox1->Text = ""; 
				  
				  }

	  private: System::Void textBox1_Click(System::Object^  sender, System::EventArgs^  e) {
				   this->textBox1->Text = "";
			   
			   }

     private: System::Void Form1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				  mX = e->X;
				  this->button2->Location = System::Drawing::Point(mX, mY);
				  if(this->timer1->Enabled == false)
				  {
					pX = mX+25;
					pY = mY-25;
					this->button1->Location = System::Drawing::Point(pX, pY);
				  }
			  }
};
}
