#pragma once

#include "actor.h"

class material {
    public:
        virtual ~material() = default;

        virtual bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const {
            return false;
        }
};

class labmertian : public material {
    private:
        color albedo;
    
    public:
        labmertian(const color& alb);

        bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const override;


};

class metal : public material {
    private:
        color albedo;
        double fuzz;
    
    public:
        metal(const color& alb, double fzz);

        bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const override;


};