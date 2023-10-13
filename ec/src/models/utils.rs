use core::convert::TryInto;

use ark_ff::Field;

use crate::{
    bindings::{point_add, point_projective_t},
    short_weierstrass_jacobian::GroupProjective,
    SWModelParameters,
};

pub(crate) fn hardware_point_add<P>(
    a: &GroupProjective<P>,
    b: &GroupProjective<P>,
) -> GroupProjective<P>
where
    P: SWModelParameters,
{
    let c_type_a = to_c_type(a);
    let c_type_b = to_c_type(b);
    let mut c_type_res = to_c_type(&GroupProjective::<P>::default());
    unsafe {
        point_add(
            &c_type_a as *const point_projective_t,
            &c_type_b as *const point_projective_t,
            &mut c_type_res as *mut point_projective_t,
        );
    }
    from_c_type(&c_type_res)
}

fn to_c_type<P>(p: &GroupProjective<P>) -> point_projective_t
where
    P: SWModelParameters,
{
    let x = p.x.into_raw_memory();
    let y = p.y.into_raw_memory();
    let z = p.z.into_raw_memory();

    point_projective_t {
        x: x.try_into()
            .expect("Hardware mode does not support curves other than bls12-381"),
        y: y.try_into()
            .expect("Hardware mode does not support curves other than bls12-381"),
        z: z.try_into()
            .expect("Hardware mode does not support curves other than bls12-381"),
    }
}

fn from_c_type<P>(p: &point_projective_t) -> GroupProjective<P>
where
    P: SWModelParameters,
{
    let mut res = GroupProjective::<P>::default();
    res.x = P::BaseField::from_raw_memory(p.x.as_ref());
    res.y = P::BaseField::from_raw_memory(p.y.as_ref());
    res.z = P::BaseField::from_raw_memory(p.z.as_ref());

    res
}