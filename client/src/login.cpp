 #include "../include/login.h"


Login::Login(const ServerManager& sm,std::list<GameInfo> games, std::list<std::string> maps) 
: QWidget(0), serverManager(sm), games(games), maps(maps), tableWidget(0,4), exitButton("Salir"),
createGameButton("Crear partida"){
	this->tableWidget.verticalHeader()->hide();

    QStringList horzHeaders;
    horzHeaders<<"id"<<"Mapa"<<"Jugadores"<<"Unirse";
    this->tableWidget.setHorizontalHeaderLabels(horzHeaders);
    for(GameInfo gi : games){
        if(gi.getPlayers() < gi.getCapacity()){            
            this->tableWidget.insertRow ( this->tableWidget.rowCount() );

            std::string str = std::to_string(gi.getId());
            QTableWidgetItem * item = new QTableWidgetItem(QString(str.c_str()));
            item->setTextAlignment(Qt::AlignCenter);
            this->tableWidget.setItem   ( this->tableWidget.rowCount()-1, 0, item);        
            
            str = gi.getMapName();
            str = str.substr(0, str.size()-5);
            item = new QTableWidgetItem(QString(str.c_str()));
            item->setTextAlignment(Qt::AlignCenter);
            this->tableWidget.setItem   ( this->tableWidget.rowCount()-1, 1, item);
            
            str = std::to_string(gi.getPlayers()) + "/" + std::to_string(gi.getCapacity());
            item = new QTableWidgetItem(QString(str.c_str()));
            item->setTextAlignment(Qt::AlignCenter);
            this->tableWidget.setItem   ( this->tableWidget.rowCount()-1, 2, item);

            
            QPushButton *btn = new QPushButton();
            btn->setText("Unirse");
            btn->setVisible(true);
            QObject::connect(btn, &QPushButton::clicked,this, [=]{this->join(gi.getId());});
            this->tableWidget.setCellWidget(this->tableWidget.rowCount()-1,3,btn);
        }
    }
    

    QVBoxLayout* verticalLayout = new QVBoxLayout();
	verticalLayout->addWidget(&this->tableWidget);
	verticalLayout->addWidget(&this->createGameButton);
	verticalLayout->addWidget(&this->exitButton);
    this->setLayout(verticalLayout);

    QObject::connect(&this->exitButton, &QPushButton::clicked,this, &Login::exit);
}

void Login::exit(){
    this->close();
}

void Login::join(uint32_t game){
    this->serverManager.joinGame(game);
    this->close();
}


