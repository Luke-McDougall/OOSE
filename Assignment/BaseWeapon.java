public class BaseWeapon extends Item
{
    private String type;
    private String damageType;

    public BaseWeapon(String name, int value, int effectMin,
                      int effectMax, String type, String damageType)
    {
        super(name, value, effectMin, effectMax);
        this.type = type;
        this.damageType = damageType;
    }
}
