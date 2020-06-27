#include "youxi.h"
#include "ui_youxi.h"
#include<Qpainter>
#include<map.h>
#include <QMouseEvent>
#include <QtGlobal>
#include "enemy.h"
#include "bullet.h"
#include "waypoint.h"
#include "plistreader.h"
#include <QMessageBox>
#include <QXmlStreamReader>
#include <QTimer>
#include <QtDebug>
#include <typeinfo>
#include <cstring>
#include<button.h>
#include<QPushButton>
#include<QPixmap>
#include<chaita.h>
#include<jianta.h>


static const int TowerCost = 300;

youxi::youxi(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::youxi)
    , m_waves(0)
    , m_playerHp(5)
    , m_playrGold(1000)
    , m_gameEnded(false)
    , m_gameWin(false)//��ʼ������
{     m_choosemap=2;
      m_pointnumber=4;
      //��һ����ѡ���ͼ���ڶ�����������ͼ�м���·���������������ͼ����4����
      //��Ҫ���ľ�������Ϸ��ʼ֮ǰ��������ť������֮��ı�����ֵ��ͬʱ��ʼ������Ϸ����
      ui->setupUi(this);
      ui->pushButton->show();
      ui->pushButton_2->show();
      this->setMinimumSize(1200,800);//��С
      m_map=new map(m_choosemap,m_pointnumber);
      m_map->preLoadWavesInfo();//���ز�����Ϣ
      m_map->loadTowerPositions();//������λ����Ϣ
      m_map->load_Points();//������λ

      QTimer *timer = new QTimer(this);
      connect(timer, SIGNAL(timeout()), this, SLOT(updateMap()));
      timer->start(30);


      connect(this,SIGNAL(canstart()),this,SLOT(gostart()));
      // ����300ms����Ϸ����
    // ����300ms����Ϸ����


}
youxi::~youxi()
{
    delete ui;
}

void youxi::gostart()
{
    QTimer::singleShot(300, this, SLOT(gameStart()));

}

void youxi::gameStart()
{
    loadWave();
}




void youxi:: paintEvent(QPaintEvent*)
{
    if (m_gameEnded || m_gameWin)
    {
        QString text = m_gameEnded ? "YOU LOST!!!" : "YOU WIN!!!";
        QPainter painter(this);
        painter.setPen(QPen(Qt::red));
        painter.drawText(rect(), Qt::AlignCenter, text);//��ʾ��������ַ�����������Ӧ����ͼƬ����
        return;
    }

    if(canload)
    {

    QPixmap cachePix(m_map->mapway);//���ص�ͼ����
    QPainter cachePainter(&cachePix);
    foreach (const TowerPosition &towerPos, m_map->m_towerPositionsList)
        towerPos.draw(&cachePainter);//������λ��
    foreach (const Tower *tower, m_towersList)
        tower->draw(&cachePainter);//����

    foreach (const QList<WayPoint*> wayPointlist, m_map->m_wayPointsList)
    foreach(const WayPoint *wayPoint,wayPointlist)
        wayPoint->draw(&cachePainter);//��·����

    foreach (const Enemy *enemy, m_enemyList)
        enemy->draw(&cachePainter);//������

    foreach (const Bullet *bullet, m_bulletList)
        bullet->draw(&cachePainter);//���ӵ�

    drawWave(&cachePainter);
    drawHP(&cachePainter);
    drawPlayerGold(&cachePainter);
    QPainter painter(this);
    painter.drawPixmap(0, 0, cachePix);
}
}



void youxi::mousePressEvent(QMouseEvent *event)//������¼�
{
    QPoint pressPos = event->pos();//�����������λ��ʱ
    auto it = m_map->m_towerPositionsList.begin();
    while (it != m_map->m_towerPositionsList.end())
    {
        if (it->containPoint(pressPos))
        {
            if(!it->hasTower())//����
            {
                jianta*dialog=new jianta;
                dialog->show();
                connect(dialog,SIGNAL(sendkind(int)),this,SLOT(t_youxi(int)));
               if(dialog->exec() == QDialog::Rejected)
                {//���ڹر�֮����н�����ж���ִ��
                    if(temp_kind==3)
                    {
                        Tower_A *tower = new Tower_A(it->centerPos(), this);//tower�������kind �Ĳ�ͬ�仯
                        if(m_playrGold>=tower->getcost())
                        {
                            m_playrGold -= tower->getcost();//��Ǯ������������������
                            m_towersList.push_back(tower);

                            it->setHasTower();
                        }
                        else delete tower;
                    }
                    if(temp_kind==1)
                    {
                        Tower_Exp *tower = new Tower_Exp(it->centerPos(), this);//tower�������kind �Ĳ�ͬ�仯
                        if(m_playrGold>=tower->getcost())
                        {
                            m_playrGold -= tower->getcost();//��Ǯ������������������
                            m_towersList.push_back(tower);

                            it->setHasTower();
                        }
                        else delete tower;
                    }
                    if(temp_kind==2)
                    {
                        Tower_M *tower = new Tower_M(it->centerPos(), this);//tower�������kind �Ĳ�ͬ�仯
                        if(m_playrGold>=tower->getcost())
                        {
                            m_playrGold -= tower->getcost();//��Ǯ������������������
                            m_towersList.push_back(tower);

                            it->setHasTower();
                        }
                        else delete tower;
                    }
                }
            update();
            break;
            }
            else
            {
                auto ti = m_towersList.begin();
                int jjj=0;
                while(ti!=m_towersList.end())
                {
                if((*ti)->getpos()==it->centerPos())
                {
                    chaita*ddialog=new chaita;
                    ddialog->show();
                    connect(ddialog,SIGNAL(sendkindd(int)),this,SLOT(t_youxi_s(int)));
                   if(ddialog->exec() == QDialog::Rejected)
                   {
                        if((*ti)->getype()==1)
                        {
                            if(temp_kindd==1)//����
                            {
                                m_playrGold+=(*ti)->getcost();
                                it->setHasTower(0);
                                m_towersList.removeAt(jjj);
                                break;
                            }
                            else//����
                            {
                                Tower_A_S *tower=new Tower_A_S(it->centerPos(), this);
                                m_playrGold-=tower->getcost();
                                m_towersList.push_back(tower);
                                 m_towersList.removeAt(jjj);
                                break;
                            }
                        }
                        else if((*ti)->getype()==3)
                        {
                            if(temp_kindd==1)
                            {
                                m_playrGold+=(*ti)->getcost();
                                it->setHasTower(0);
                                 m_towersList.removeAt(jjj);
                                break;
                            }
                            else
                            {
                                Tower_M_S *tower=new Tower_M_S(it->centerPos(), this);
                                m_playrGold-=tower->getcost();
                                m_towersList.removeAt(jjj);
                                m_towersList.push_back(tower);
                                break;
                            }
                        }
                        else if((*ti)->getype()==2)
                        {
                            if(temp_kindd==1)
                            {
                                m_playrGold+=(*ti)->getcost();
                                it->setHasTower(0);
                                m_towersList.removeAt(jjj);
                                break;
                            }
                            else
                            {
                                Tower_Exp_S *tower=new Tower_Exp_S(it->centerPos(), this);
                                m_playrGold-=tower->getcost();
                                m_towersList.removeAt(jjj);
                                m_towersList.push_back(tower);
                                break;
                            }
                        }
                        else m_playrGold+=100000;

                   }
                }
                ti++;
                jjj++;
                }
            update();
            break;}
        }
        ++it;
    }
}


void youxi::t_youxi(int i)
{
    temp_kind=i;
    return;
}
void youxi::t_youxi_s(int i)
{
    temp_kindd=i;
    return;
}

void youxi::removedBullet(Bullet *bullet)//�����ӵ�
{
    Q_ASSERT(bullet);

    m_bulletList.removeOne(bullet);
    delete bullet;
}
void youxi::getHpDamage(int damage/* = 1*/)//��Ѫ
{
    //����
    m_playerHp -= damage;
    if (m_playerHp <= 0)
        doGameOver();
}
void youxi::removedEnemy(Enemy *enemy)//���ߵ���
{
    Q_ASSERT(enemy);

    m_enemyList.removeOne(enemy);
    delete enemy;

    if (m_enemyList.empty())
    {
        ++m_waves;
        if (!loadWave())
        {
            m_gameWin = true;
            // ��Ϸʤ��ת����Ϸʤ������
            // ������ʱ�Դ�ӡ����
        }
    }
}
void youxi::doGameOver()
{
    if (!m_gameEnded)
    {
        m_gameEnded = true;
        // �˴�Ӧ���л���������������
        // ��ʱ�Դ�ӡ���,��paintEvent����
    }
}
void youxi::awardGold(int gold)
{
    m_playrGold += gold;//�õ����
    update();
}
void youxi::addBullet(Bullet *bullet)//�����ӵ�
{
    Q_ASSERT(bullet);

    m_bulletList.push_back(bullet);}
bool youxi::loadWave()//���ز���
{
    if (m_waves >= m_map->m_wavesInfo.size())
        return false;


    QList<QVariant> curWavesInfo = m_map->m_wavesInfo[m_waves].toList();
    WayPoint *startWayPoint = m_map->m_wayPointsList[0].back();
    Enemy* enemy[100]={NULL};
    for (int i = 0; i < curWavesInfo.size(); ++i)
    {
        QMap<QString, QVariant> dict = curWavesInfo[i].toMap();
        int spawnTime = dict.value("spawnTime").toInt();//��ȡ����ʱ��
        int road=dict.value("road").toInt();//��ȡ����·��
        if(road==2) startWayPoint = m_map->m_wayPointsList[1].back();//���
        else if(road==3) startWayPoint = m_map->m_wayPointsList[2].back();
        else if(road==4) startWayPoint = m_map->m_wayPointsList[3].back();
        int enemytype=dict.value("enemytype").toInt();
        switch (enemytype) {
        case 1:
            enemy[i] = new Enemy(startWayPoint, this);
            break;
        case 2:
            enemy[i] = new Enemy2_1(startWayPoint, this);
            break;
        case 3:
            enemy[i] = new Enemy2_2(startWayPoint, this);
             break;
        case 4:
            enemy[i] = new Enemy3_1(startWayPoint, this);
             break;
        case 5:
            enemy[i] = new Enemy3_2(startWayPoint, this);
             break;
        case 6:
            enemy[i] = new Enemy3_3(startWayPoint, this);
             break;
        case 7:
            enemy[i] = new Enemy_boss(startWayPoint, this);
             break;

        default:
            break;
        }
        m_enemyList.push_back(enemy[i]);
        QTimer::singleShot(spawnTime, enemy[i], SLOT(doActivate()));//����
    }

    return true;
}
void youxi::drawWave(QPainter *painter)//��ʾ����
{
    painter->setPen(QPen(Qt::red));
    painter->drawText(QRect(400, 5, 100, 25), QString("WAVE : %1").arg(m_waves + 1));
}
void youxi::drawHP(QPainter *painter)//��ʾ����
{
    painter->setPen(QPen(Qt::red));
    painter->drawText(QRect(30, 5, 100, 25), QString("HP : %1").arg(m_playerHp));
}
void youxi::drawPlayerGold(QPainter *painter)//��ʾ��Ǯ
{
    painter->setPen(QPen(Qt::red));
    painter->drawText(QRect(200, 5, 200, 25), QString("GOLD : %1").arg(m_playrGold));
}
QList<Enemy *> youxi::enemyList() const
{
    return m_enemyList;
}
void youxi::updateMap()//���µ�ͼ
{
    foreach (Enemy *enemy, m_enemyList)
        enemy->move();
    foreach (Tower *tower, m_towersList)
        tower->checkEnemyInRange();
    update();
}

void youxi::on_pushButton_clicked()
{
    canload=true;
    m_choosemap=1;

    m_map=new map(m_choosemap,m_pointnumber);
    m_map->preLoadWavesInfo();//���ز�����Ϣ
    m_map->loadTowerPositions();//������λ����Ϣ
    m_map->load_Points();//������λ
    emit canstart();
}

void youxi::on_pushButton_2_clicked()
{
    canload=true;
    m_choosemap=2;

    m_map=new map(m_choosemap,m_pointnumber);
    m_map->preLoadWavesInfo();//���ز�����Ϣ
    m_map->loadTowerPositions();//������λ����Ϣ
    m_map->load_Points();//������λ
    emit canstart();
}
