#include "shape.h"
#include <QImage>

// 注: 贴图有可能反了
GLuint LoadTexture(const string filename){
	GLuint id;
	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);

	QImage img(filename.c_str());
	unsigned char * buf = img.bits();
	unsigned int width = img.width();
	unsigned int height = img.height();

	GLenum image_format = GL_RGB;
	GLint internal_format = GL_BGRA_EXT;

	glTexImage2D(GL_TEXTURE_2D, 0, image_format, width, height,0, internal_format, GL_UNSIGNED_BYTE, buf);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glBindTexture(GL_TEXTURE_2D, 0);

	return id;
}

void DrawAxis(){

	glLineWidth(4);
	glBegin(GL_LINES);
		glColor3ub(255, 0, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(1, 0, 0);
		glColor3ub(0, 255, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 1, 0);
		glColor3ub(0, 0, 255);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, 1);
	glEnd();
	glLineWidth(1);
	
	double base = 0.05, height = 0.10;
	int slices = 10, stacks = 10;
	glColor3ub(255, 0, 0);
    glPushMatrix();  
    glTranslatef(1.0f - height,0.0f,0.0f);  
    glRotatef(90.0f,0.0f,1.0f,0.0f);  
    //glutWireCone(base,height,slices,stacks);  
    glPopMatrix();  
  
	glColor3ub(0, 255, 0);
    glPushMatrix();  
    glTranslatef(0.0f,1.0f - height,0.0f);  
    glRotatef(-90.0f,1.0f,0.0f,0.0f);  
    //glutWireCone(base,height,slices,stacks);  
    glPopMatrix();  
  
	glColor3ub(0, 0, 255);
    glPushMatrix();  
    glTranslatef(0.0f,0.0f,1.0f - height);  
    glRotatef(90.0f,0.0f,0.0f,1.0f);  
    //glutWireCone(base,height,slices,stacks);  
    glPopMatrix();  
}	

void DrawGround(){
	glLineWidth(2);
	const int K = 5;
	glColor3ub(127,127,127);
	glBegin(GL_LINES);
	for (int x = -K; x <= K;++x){
		glVertex3f(x,-K,0);
		glVertex3f(x,K,0);
	}
	for (int y = -K; y <= K;++y){
		glVertex3f(-K,y,0);
		glVertex3f(K,y,0);
	}
	glEnd();
	glLineWidth(0);
}

void AddRect(Model &md, int a, int b,int c, int d){
	objPoly p;
	p.add(objPoint(a, 1));
	p.add(objPoint(b, 2));
	p.add(objPoint(c, 3));
	p.add(objPoint(d, 4));
	md.ps.push_back(p);
}

Model GetCube(double x, double y, double z){
	Model md;
	md.name = "立方体";
	double hx = x / 2;
	double hy = y / 2;
	//double hz = z / 2;
	// 从上到下, 按象限顺序
	md.vs.push_back(glm::vec3(hx,hy,z));
	md.vs.push_back(glm::vec3(-hx,hy,z));
	md.vs.push_back(glm::vec3(-hx,-hy,z));
	md.vs.push_back(glm::vec3(hx,-hy,z));
	//----
	md.vs.push_back(glm::vec3(hx,hy,0));
	md.vs.push_back(glm::vec3(-hx,hy,0));
	md.vs.push_back(glm::vec3(-hx,-hy,0));
	md.vs.push_back(glm::vec3(hx,-hy,0));
	//====
	md.vt.push_back(glm::vec2(0,0));
	md.vt.push_back(glm::vec2(1,0));
	md.vt.push_back(glm::vec2(1,1));
	md.vt.push_back(glm::vec2(0,1));
	// 面, 上下左右前后
	AddRect(md, 1,4,3,2);
	AddRect(md, 5,6,7,8);

	AddRect(md, 2,3,7,6);
	AddRect(md, 4,1,5,8);

	AddRect(md, 3,4,8,7);
	AddRect(md, 1,2,6,5);
	md.Rebuild();
	return md;
}

Model GetCone(double r, double h, int n){
	Model md;
	md.name = "圆锥";
	double a = 2 * PI / n; 
	objPoly circle;
	for (int i = 0;i < n;++i){
		double e = a * i;
		md.vs.push_back(glm::vec3(r * cos(e), r * sin(e), 0));
		circle.points.push_back(objPoint(i));
	}
	md.ps.push_back(circle);

	md.vs.push_back(glm::vec3(0,0,h));
	// 侧面
	for (int i = 0;i < n - 1;++i){
		objPoly t;
		t.points.push_back(objPoint(i + 1));
		t.points.push_back(objPoint(i + 2));
		t.points.push_back(objPoint(n+1));
		md.ps.push_back(t);
	}
	objPoly t;
	t.points.push_back(objPoint(n));
	t.points.push_back(objPoint(1));
	t.points.push_back(objPoint(n+1));
	md.ps.push_back(t);
	md.Rebuild();
	return md;
}

Model GetLoudou(double r, int cn, int hn){
	Model md;
	md.name = "漏斗";
	double hd = 2 * r / hn;
	double a = 2 * PI / cn;
    for (int k = 0;k < hn;++k){
        double h = -r + hd * k;
        double w = r - abs(h);
        double q = sqrt(r * r - w * w);
        for (int i = 0;i < cn;++i){
            double e = a * i;
            md.vs.push_back(glm::vec3(q * cos(e), q * sin(e), h));
            md.vt.push_back(glm::vec2(k * 1.0 / (hn-1), i * 1.0 / cn));
        }
    }
    for (int k = 0;k < hn;++k){
        md.vt.push_back(glm::vec2(k * 1.0 / (hn-1), 1.0 + 1.0 / cn));
    }
    for (int k = 1;k < hn;++k){
        for (int e = 0; e < cn;++e){
            objPoly p;
            int i = (e) % cn + 1;
            int j = (e + 1) % cn + 1;
            p.points.push_back(objPoint(k * cn + i, k * cn + i));
            int tex1 = k * cn + j;
            int tex2 = (k-1) * cn + j;
            if (e == cn-1){
                tex1 = hn * cn + k + 1;
                tex2 = hn * cn + k + 0;
            }
            p.points.push_back(objPoint(k * cn + j, tex1));
            p.points.push_back(objPoint((k-1) * cn + j,tex2));
            p.points.push_back(objPoint((k-1) * cn + i,(k-1) * cn + i));
            md.ps.push_back(p);
        }
    }

    md.vs.push_back(glm::vec3(0, 0, -r)); // hn * cn + 1
    md.vs.push_back(glm::vec3(0, 0, r)); // hn * cn + 2

    for (int e = 0;e < cn;++e){
        objPoly p, p2;
        int i = (e) % cn + 1;
        int j = (e + 1) % cn + 1;
        p.points.push_back(objPoint(i,i));
        p.points.push_back(objPoint(j,j));
        p.points.push_back(objPoint(hn * cn + 1));
        md.ps.push_back(p);

        int b = (hn - 1) * cn;
        p2.points.push_back(objPoint(b + i, b+i));
        p2.points.push_back(objPoint(b + j, b+j));
        p2.points.push_back(objPoint(hn * cn + 2));
        md.ps.push_back(p2);
    }

    md.Rebuild();
    return md;
}

Model GetBall(double r, int cn, int hn){
	Model md;
	md.name = "球";
	double hd = 2 * r / hn;
    double a = 2 * PI / cn;
	for (int k = 0;k < hn;++k){
		double h = -r + hd * k;
		double w = abs(h);
		double q = sqrt(r * r - w * w);
		for (int i = 0;i < cn;++i){
			double e = a * i;
			md.vs.push_back(glm::vec3(q * cos(e), q * sin(e), h));
            md.vt.push_back(glm::vec2(k * 1.0 / (hn-1), i * 1.0 / cn));
		}
    }
    for (int k = 0;k < hn;++k){
        md.vt.push_back(glm::vec2(k * 1.0 / (hn-1), 1.0 + 1.0 / cn));
    }
    for (int k = 1;k < hn;++k){
        for (int e = 0; e < cn;++e){
			objPoly p;
            int i = (e) % cn + 1;
            int j = (e + 1) % cn + 1;
            p.points.push_back(objPoint(k * cn + i, k * cn + i));
            int tex1 = k * cn + j;
            int tex2 = (k-1) * cn + j;
            if (e == cn-1){
                tex1 = hn * cn + k + 1;
                tex2 = hn * cn + k + 0;
            }
            p.points.push_back(objPoint(k * cn + j, tex1));
            p.points.push_back(objPoint((k-1) * cn + j,tex2));
            p.points.push_back(objPoint((k-1) * cn + i,(k-1) * cn + i));
			md.ps.push_back(p);
		}
    }

	md.vs.push_back(glm::vec3(0, 0, -r)); // hn * cn + 1
    md.vs.push_back(glm::vec3(0, 0, r)); // hn * cn + 2

    for (int e = 0;e < cn;++e){
        objPoly p, p2;
        int i = (e) % cn + 1;
        int j = (e + 1) % cn + 1;
        p.points.push_back(objPoint(i,i));
        p.points.push_back(objPoint(j,j));
        p.points.push_back(objPoint(hn * cn + 1));
		md.ps.push_back(p);

        int b = (hn - 1) * cn;
        p2.points.push_back(objPoint(b + i, b+i));
        p2.points.push_back(objPoint(b + j, b+j));
        p2.points.push_back(objPoint(hn * cn + 2));
        md.ps.push_back(p2);
    }

	md.Rebuild();
	return md;
}


