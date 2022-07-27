import React from 'react';
import { Link } from "gatsby"

import Layout from "../components/layout"
//import Image from "../components/image"
import SEO from "../components/seo"

import Auth from '../Auth/auth';
import App from '../components/App'
// import SharedExample from "../../../shared/SharedExample"

const auth = new Auth();

export default () => {
    return (
        <Layout>
            <SEO title="Home 2" />
            <App auth={auth}></App>
            {/* <p><SharedExample name="MY SERVICES"/></p> */}
            <Link to="/page-2/">Go to page 2</Link>
        </Layout>
    )
}